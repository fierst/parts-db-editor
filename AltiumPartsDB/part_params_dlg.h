#ifndef PART_PARAMS_DLG_H
#define PART_PARAMS_DLG_H

#include <QDialog>
#include <QFileInfo>
#include <QDir>
#include <QMessageBox>
#include <QSharedPointer>
#include <QtSql>

#include <memory>

#include "altium_lib.hpp"
#include "cfb_types.hpp"

#include "capacitor_dlg.h"
#include "connector_dlg.h"
#include "diode_dlg.h"
#include "electromechanical_dlg.h"
#include "filter_dlg.h"
#include "fuse_dlg.h"
#include "ic_dlg.h"
#include "inductor_dlg.h"
#include "mechanical_dlg.h"
#include "optoelectronic_dlg.h"
#include "oscillator_dlg.h"
#include "power_dlg.h"
#include "resistor_dlg.h"
#include "transformer_dlg.h"
#include "transistor_dlg.h"

namespace Ui {
class part_params_dlg;
}

class part_params_dlg : public QDialog
{
    Q_OBJECT

public:

    explicit part_params_dlg(QWidget *parent = 0);

    part_params_dlg(library_part &);

    ~part_params_dlg();

    // Set the current table for ease of use
    void set_current_table(int tbl_index);

    // Set the shared pointer for the SQL database
    void assign_db(const std::shared_ptr<QSqlDatabase>& db_ptr);

    // Pass a SchLib and PcbLib path to the dialog
    void set_paths(QString sch_path, QString pcb_path);

signals:

    void created_part(library_part &part, QString which_table);

private slots:

    void on_btn_part_properties_clicked();

    void on_cmb_symbol_lib_currentIndexChanged(int index);

    void on_cmb_footprint_lib_currentIndexChanged(int index);

    void on_btn_ok_clicked();

    void on_btn_cancel_clicked();

    void on_cmb_part_type_currentIndexChanged(int index);

private:

    // Update the combo boxes based on the set paths
    void update_combo_boxes();

    // Add the updated params to the map
    void params_updated(const std::map<QString, QString> & );

    // Given the base path and the path to a library, get the relative path
    QString get_relative_path(QString path_to_library);

    std::shared_ptr<QSqlDatabase> parts_db;

    std::shared_ptr<library_part> current_part;

    Ui::part_params_dlg *ui;

    QFileInfoList schlibs, pcblibs;

    QString schlib_path, pcblib_path;

};

#endif // PART_PARAMS_DLG_H
