#include <QDebug>

#include "parts_browser_dlg.h"
#include "ui_parts_browser_dlg.h"

#include "database_connection_dlg.h"
#include "part_params_dlg.h"

parts_browser_dlg::parts_browser_dlg(QWidget *parent) :
    QMainWindow(parent),
    db_connection_ok(false),
    ui(new Ui::parts_browser_dlg)
{
    ui->setupUi(this);

    ui->tbl_parts->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);      // Automatically resize columns

    if(QFile::exists("config.xml"))
    {
        read_configuration_file();
        if(connect_to_database())
        {
            ui->cmb_part_types->addItems(parts_db->tables());
            QSqlQueryModel *model = new QSqlQueryModel;
            model->setQuery(QString("SELECT * FROM %1").arg(ui->cmb_part_types->currentText()), *parts_db.get());
            ui->tbl_parts->setModel(model);
        }
    }

    // Don't allow the user to resize the dialog because it would mess up the layout
    //this->setWindowFlags(this->windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
    //ui->statusBar->setSizeGripEnabled(false);
}

parts_browser_dlg::~parts_browser_dlg()
{
    delete ui;
}

void parts_browser_dlg::on_actionConnect_triggered()
{
    database_connection_dlg dbconn;
    dbconn.setModal(true);
    dbconn.setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);

    // Populate the fields in the dialog from the configuration file
    dbconn.set_fields_from_cfg(this->schlib_path, this->pcblib_path, this->db_connection_path);

    connect(&dbconn, &database_connection_dlg::schlib_path_set, this, &parts_browser_dlg::update_schlib_path);
    connect(&dbconn, &database_connection_dlg::pcblib_path_set, this, &parts_browser_dlg::update_pcblib_path);
    connect(&dbconn, &database_connection_dlg::db_path_set, this, &parts_browser_dlg::update_db_path);

    // If the database connection is good, write the configuration file.
    if(dbconn.exec() == QDialog::Accepted)
    {
        write_configuration_file();
    }
}

void parts_browser_dlg::update_schlib_path(const QString& schlib_path)
{
    this->schlib_path = schlib_path;
}

void parts_browser_dlg::update_pcblib_path(const QString& pcblib_path)
{
    this->pcblib_path = pcblib_path;
}

void parts_browser_dlg::update_db_path(const QString& db_path)
{
    this->db_connection_path = db_path;
}

void parts_browser_dlg::write_configuration_file()
{
    QString filename = "config.xml";
    QFile file(filename);

    file.open(QIODevice::WriteOnly);

    QXmlStreamWriter xmlwriter(&file);
    xmlwriter.setAutoFormatting(true);
    xmlwriter.writeStartDocument();

    xmlwriter.writeStartElement("Paths");
    xmlwriter.writeTextElement("DBPath", this->db_connection_path);
    xmlwriter.writeTextElement("SchLibPath", this->schlib_path);
    xmlwriter.writeTextElement("PcbLibPath", this->pcblib_path);
    xmlwriter.writeEndElement();

    file.close();
}

void parts_browser_dlg::read_configuration_file()
{
    QString filename = "config.xml";
    QFile file(filename);

    file.open(QIODevice::ReadOnly);

    QXmlStreamReader xmlreader(&file);

    while (xmlreader.readNextStartElement())
    {
        if(xmlreader.name() == "Paths")
        {
            while(xmlreader.readNextStartElement())
            {
                QString element = xmlreader.readElementText();

                if(xmlreader.name() == "DBPath")
                {
                    db_connection_path = element;
                }
                else if(xmlreader.name() == "SchLibPath")
                {
                    schlib_path = element;
                }
                else if(xmlreader.name() == "PcbLibPath")
                {
                    pcblib_path = element;
                }
                else
                {
                    xmlreader.skipCurrentElement();
                }
            }
        }
    }

    file.close();
}

bool parts_browser_dlg::connect_to_database()
{
    QSqlDatabase temp_db = QSqlDatabase::addDatabase(QString("QODBC"), QString("PartsDB%1").arg(1));
    temp_db.setDatabaseName("parts");
    temp_db.setHostName(this->db_connection_path);
    temp_db.setPort(3306);

    if(!temp_db.open("parts_db_editor", ""))
    {
        return false;
    }

    parts_db = std::make_shared<QSqlDatabase>(temp_db);

    return true;
}

void parts_browser_dlg::process_new_part(library_part &part, QString which_table)
{
    // If the new part is in a different table, switch that table now
    // Note: refresh_table_query() actually changes what's shown in the table
    ui->cmb_part_types->setCurrentText(which_table);

    // Perform the SQL INSERT query
    part.write_new_to_db(which_table, *parts_db);

    // Refresh the query model
    refresh_table_query();
}

void parts_browser_dlg::process_edited_part(library_part &part, QString which_table)
{
    // Perform the SQL UPDATE query
    part.edit_existing_in_db(which_table, *parts_db);

    // Refresh the query model
    refresh_table_query();
}

void parts_browser_dlg::on_btn_new_part_clicked()
{
    part_params_dlg ppdlg;
    ppdlg.setModal(true);
    ppdlg.setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
    ppdlg.assign_db(parts_db);
    ppdlg.set_paths(this->schlib_path, this->pcblib_path);
    ppdlg.set_current_table(ui->cmb_part_types->currentIndex());
    connect(&ppdlg, &part_params_dlg::created_part, this, &parts_browser_dlg::process_new_part);
    ppdlg.exec();
}

void parts_browser_dlg::on_actionQuit_triggered()
{
    this->close();
}

void parts_browser_dlg::on_cmb_part_types_currentIndexChanged(int index)
{
    Q_UNUSED(index)

    refresh_table_query();
}

void parts_browser_dlg::refresh_table_query()
{
    // Set the model to select all paramters from the selected database
    parts_query_model.setQuery(QString("SELECT * FROM %1").arg(ui->cmb_part_types->currentText()), *parts_db.get());
    ui->tbl_parts->setModel(&parts_query_model);
}

void parts_browser_dlg::on_btn_edit_part_clicked()
{
    // Don't try to edit a part if there's none selected
    if(ui->tbl_parts->selectionModel()->selectedRows().count() == 0)
    {
        QMessageBox::warning(this, "Error", "No part selected!", QMessageBox::Ok);
        return;
    }

    library_part current_part(parts_query_model.record(ui->tbl_parts->currentIndex().row()));
    part_params_dlg ppdlg(current_part);
    ppdlg.setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
    ppdlg.assign_db(parts_db);
    ppdlg.set_paths(this->schlib_path, this->pcblib_path);
    ppdlg.set_current_table(ui->cmb_part_types->currentIndex());
    connect(&ppdlg, &part_params_dlg::created_part, this, &parts_browser_dlg::process_edited_part);
    ppdlg.exec();
}

void parts_browser_dlg::on_btn_copy_part_clicked()
{
    library_part current_part(parts_query_model.record(ui->tbl_parts->currentIndex().row()));
    current_part.remove_parameter("part_number");
    part_params_dlg ppdlg(current_part);
    ppdlg.setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
    ppdlg.assign_db(parts_db);
    ppdlg.set_paths(this->schlib_path, this->pcblib_path);
    ppdlg.set_current_table(ui->cmb_part_types->currentIndex());
    connect(&ppdlg, &part_params_dlg::created_part, this, &parts_browser_dlg::process_new_part);
    ppdlg.exec();
}
