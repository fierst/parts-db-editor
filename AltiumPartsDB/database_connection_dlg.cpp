#include "database_connection_dlg.h"
#include "ui_database_connection_dlg.h"

database_connection_dlg::database_connection_dlg(QWidget *parent) : ui(new Ui::database_connection_dlg)
{
    Q_UNUSED(parent);

    ui->setupUi(this);
}

database_connection_dlg::~database_connection_dlg()
{
    delete ui;
}

void database_connection_dlg::set_fields_from_cfg(const QString &schlib_path, const QString &pcblib_path, const QString &db_path)
{
    ui->box_db_location->setText(db_path);
    ui->box_schlib_location->setText(schlib_path);
    ui->box_pcblib_location->setText(pcblib_path);
}

void database_connection_dlg::on_btn_browse_schlib_clicked()
{
    QFileDialog dir_dlg;
    dir_dlg.setFileMode(QFileDialog::Directory);
    dir_dlg.setOption(QFileDialog::ShowDirsOnly);
    QString schlib_location = dir_dlg.getExistingDirectory(this, tr("Schematic Library Location..."), QString(QStandardPaths::HomeLocation));
    ui->box_schlib_location->setText(schlib_location);
}

void database_connection_dlg::on_btn_browse_pcblib_clicked()
{
    QFileDialog dir_dlg;
    dir_dlg.setFileMode(QFileDialog::Directory);
    dir_dlg.setOption(QFileDialog::ShowDirsOnly);
    QString pcblib_location = dir_dlg.getExistingDirectory(this, tr("Footprint Library Location..."), QString(QStandardPaths::HomeLocation));
    ui->box_pcblib_location->setText(pcblib_location);
}

void database_connection_dlg::on_btn_cancel_clicked()
{
    // Quit without saving values
    QDialog::reject();
}

void database_connection_dlg::on_btn_connect_clicked()
{
    if(this->validate_library_locations() && this->test_connection_settings(ui->box_db_location->text()))
    {
        // Update the values in the part browser dialog
        emit db_path_set(ui->box_db_location->text());
        emit schlib_path_set(ui->box_schlib_location->text());
        emit pcblib_path_set(ui->box_pcblib_location->text());
        // Accept the result
        QDialog::accept();
    }
    else
    {
        // Paths are bad and files/database weren't found. Don't let the user save this.
        QMessageBox::critical(this, "Error", "Incorrect paths entered for database or library locations.\nCheck paths and try again", QMessageBox::Ok | QMessageBox::Cancel);
    }
}

bool database_connection_dlg::validate_library_locations()
{
    QDir schlib_location(ui->box_schlib_location->text());
    QDir pcblib_location(ui->box_pcblib_location->text());
    QStringList schlib_filter, pcblib_filter;
    schlib_filter << "*.SchLib";
    pcblib_filter << "*.PcbLib";

    return (!schlib_location.entryInfoList(schlib_filter).isEmpty() &&
            !pcblib_location.entryInfoList(pcblib_filter).isEmpty());
}

bool database_connection_dlg::test_connection_settings(const QString &db_string)
{\
    QSqlDatabase temp_db = QSqlDatabase::addDatabase(QString("QODBC"), QString("test_db%1").arg(1));
    temp_db.setDatabaseName("parts");
    temp_db.setHostName(db_string);
    temp_db.setPort(3306);
    if(!temp_db.open("parts_db_editor", ""))
    {
        return false;
    }

    return true;
}

void database_connection_dlg::on_btn_test_db_connection_clicked()
{
    QString db_connection_str = ui->box_db_location->text();

    if(test_connection_settings(db_connection_str))
    {
        QMessageBox::information(this, "Connection Ok", "Successfully connected to database", QMessageBox::Ok);
        emit(db_path_set(db_connection_str));
    }
    else
    {
        QMessageBox::warning(this, "Connection Error", "Could not connect to database at specified path", QMessageBox::Ok);
    }
}
