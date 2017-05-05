#ifndef PARTS_BROWSER_DLG_H
#define PARTS_BROWSER_DLG_H

#include <QMainWindow>
#include <QFile>                    // For file I/O
#include <QXmlStreamReader>         // For reading the configuration file
#include <QXmlStreamWriter>         // For writing the configuration file

#include <QtSql>
#include <QSharedPointer>
#include <memory>

#include "library_part.h"

namespace Ui {
class parts_browser_dlg;
}

class parts_browser_dlg : public QMainWindow
{
    Q_OBJECT

public:
    explicit parts_browser_dlg(QWidget *parent = 0);
    ~parts_browser_dlg();

    QString pcblib_path, schlib_path, db_connection_path;

    bool db_connection_ok;


private slots:
    void on_actionConnect_triggered();

    void on_btn_new_part_clicked();

    void on_actionQuit_triggered();

    void on_cmb_part_types_currentIndexChanged(int index);

    void on_btn_edit_part_clicked();

    void on_btn_copy_part_clicked();

private:

    void update_schlib_path(const QString& schlib_path);
    void update_pcblib_path(const QString& pcblib_path);
    void update_db_path(const QString& db_path);

    std::shared_ptr<QSqlDatabase> parts_db;

    QSqlQueryModel parts_query_model;

    // TODO: Path specification?
    // For now, these will both just default to wherever-the-application-looks
    void write_configuration_file();
    void read_configuration_file();

    // Attempt to connect to the database based on the configuration file
    bool connect_to_database();

    // Enable the dialog elements that allow for part creation/deletion and database tools
    // This is called when the database is successfully connected
    void enable_part_controls();

    // Process a new part (including copied parts, which are effectively new parts)
    void process_new_part(library_part &part, QString which_table);

    // Process an edited part
    void process_edited_part(library_part &part, QString which_table);

    Ui::parts_browser_dlg *ui;

    // Refresh the tableview
    void refresh_table_query();
};

#endif // PARTS_BROWSER_DLG_H
