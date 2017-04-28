#ifndef DATABASE_CONNECTION_DLG_H
#define DATABASE_CONNECTION_DLG_H

#include <QDialog>
#include <QFileDialog>
#include <QStandardPaths>
#include <QMessageBox>

#include <QtSql>

#include <valarray>

namespace Ui {
class database_connection_dlg;
}

class database_connection_dlg : public QDialog
{
    Q_OBJECT

public:
    explicit database_connection_dlg(QWidget *parent = 0);
    ~database_connection_dlg();

    void set_fields_from_cfg(const QString &schlib_path, const QString &pcblib_path, const QString &db_path);

signals:

    void schlib_path_set(const QString &schlib_path);

    void pcblib_path_set(const QString &pcblib_path);

    void db_path_set(const QString &db_path);

private slots:

    void on_btn_browse_schlib_clicked();

    void on_btn_browse_pcblib_clicked();

    void on_btn_cancel_clicked();

    void on_btn_connect_clicked();

    void on_btn_test_db_connection_clicked();

private:
    Ui::database_connection_dlg *ui;

    bool validate_library_locations();

    bool test_connection_settings(const QString &);
};

#endif // DATABASE_CONNECTION_DLG_H
