#include "database_connection_dlg.h"
#include "ui_database_connection_dlg.h"

#include <QStandardPaths>

database_connection_dlg::database_connection_dlg(QWidget *parent) : ui(new Ui::database_connection_dlg)
{
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
    QString schlib_location = QFileDialog::getOpenFileName(this, tr("Load Altium Schematic Library..."), QString(QStandardPaths::HomeLocation), tr("Altium Schematic Libraries (*.SchLib)"));
    ui->box_schlib_location->setText(schlib_location);
    emit schlib_path_set(schlib_location);
}

void database_connection_dlg::on_btn_browse_pcblib_clicked()
{
    QString pcblib_location = QFileDialog::getOpenFileName(this, tr("Load Altium Footprint Library..."), QString(QStandardPaths::HomeLocation), tr("Altium Footprint Libraries (*.PcbLib)"));
    ui->box_pcblib_location->setText(pcblib_location);
    emit pcblib_path_set(pcblib_location);
}

void database_connection_dlg::on_btn_cancel_clicked()
{
    QDialog::reject();
}

void database_connection_dlg::on_btn_connect_clicked()
{
    if(this->validate_library_locations() && this->test_connection_settings(ui->box_db_location->text()))
    {
        emit db_path_set(ui->box_db_location->text());
        emit schlib_path_set(ui->box_schlib_location->text());
        emit pcblib_path_set(ui->box_pcblib_location->text());
        QDialog::accept();
    }
    else
    {
        QDialog::reject();
    }
}

bool database_connection_dlg::validate_library_locations()
{
    return true;
}

bool database_connection_dlg::test_connection_settings(const QString &db_string)
{\
    return true;
}

void database_connection_dlg::on_btn_test_db_connection_clicked()
{
    QString db_connection_str = ui->box_db_location->text();

    if(test_connection_settings(db_connection_str))
    {
        emit(db_path_set(db_connection_str));
    }
}
