#include <QDebug>

#include "parts_browser_dlg.h"
#include "ui_parts_browser_dlg.h"

#include "database_connection_dlg.h"
#include "part_params_dlg.h"

parts_browser_dlg::parts_browser_dlg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::parts_browser_dlg),
    db_connection_ok(false)
{
    ui->setupUi(this);

    // TODO: Make file location variable?
    if(QFile::exists("config.xml"))
    {
        read_configuration_file();
    }

    // Don't allow the user to resize the dialog because it would mess up the layout
    this->setWindowFlags(this->windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
    ui->statusBar->setSizeGripEnabled(false);
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

    // TODO: Store configuration params in a map or something...
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

void parts_browser_dlg::on_btn_new_part_clicked()
{
    part_params_dlg ppdlg;
    ppdlg.setModal(true);
    ppdlg.setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
    ppdlg.exec();
}

void parts_browser_dlg::on_actionQuit_triggered()
{
    this->close();
}
