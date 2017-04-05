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
    connect(&dbconn, &database_connection_dlg::schlib_path_set, this, &parts_browser_dlg::update_schlib_path);
    connect(&dbconn, &database_connection_dlg::pcblib_path_set, this, &parts_browser_dlg::update_pcblib_path);
    connect(&dbconn, &database_connection_dlg::db_path_set, this, &parts_browser_dlg::update_db_path);
    dbconn.exec();
}

void parts_browser_dlg::update_schlib_path(const QString& schlib_path)
{
    qDebug() << schlib_path;
}

void parts_browser_dlg::update_pcblib_path(const QString& pcblib_path)
{
    qDebug() << pcblib_path;
}

void parts_browser_dlg::update_db_path(const QString& db_path)
{
    qDebug() << db_path;
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
