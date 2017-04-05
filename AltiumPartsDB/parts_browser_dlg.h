#ifndef PARTS_BROWSER_DLG_H
#define PARTS_BROWSER_DLG_H

#include <QMainWindow>
#include <QFile>                    // For file I/O
#include <QXmlStreamReader>         // For reading the configuration file
#include <QXmlStreamWriter>         // For writing the configuration file

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

private:

    void update_schlib_path(const QString& schlib_path);
    void update_pcblib_path(const QString& pcblib_path);
    void update_db_path(const QString& db_path);

    // TODO: Path specification?
    // For now, these will both just default to wherever-the-application-looks
    void write_configuration_file();
    void read_configuration_file();

    // Attempt to load the configuration file from the current directory
    // If it's not there, return false
    bool load_configuration_file();

    // Enable the dialog elements that allow for part creation/deletion and database tools
    // This is called when the database is successfully connected
    void enable_part_controls();

    Ui::parts_browser_dlg *ui;
};

#endif // PARTS_BROWSER_DLG_H
