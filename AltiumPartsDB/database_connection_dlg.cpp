#include "database_connection_dlg.h"
#include "ui_database_connection_dlg.h"

#include <QStandardPaths>

database_connection_dlg::database_connection_dlg(QWidget *parent) : ui(new Ui::database_connection_dlg)
{
    ui->setupUi(this);

    // Don't allow the user to resize the dialog because it would mess up the layout
    //this->setWindowFlags(this->windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
}

database_connection_dlg::~database_connection_dlg()
{
    delete ui;
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
    if(this->validate_library_locations() && this->test_connection_settings())
    {
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

bool database_connection_dlg::test_connection_settings()
{\
    return true;
}
