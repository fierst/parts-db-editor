#ifndef MANUFACTURER_DLG_H
#define MANUFACTURER_DLG_H

#include <QDialog>
#include <QDate>
#include <QMessageBox>

#include "mfg_list_model.h"     // For access to the manufacturer type

namespace Ui {
class manufacturer_dlg;
}

class manufacturer_dlg : public QDialog
{
    Q_OBJECT

public:

    explicit manufacturer_dlg(QWidget *parent = 0);

    manufacturer_dlg(const manufacturer &, QWidget *parent = 0);

    ~manufacturer_dlg();

signals:

    // Raise this signal for the manufacturer list dialog when a new one is created
    void new_manufacturer(const manufacturer &);
    // Raise this signal when the manufacturer was edited
    void edited_manufacturer(const manufacturer &);

private slots:
    void on_btn_ok_clicked();

    void on_box_notes_textChanged();

private:
    Ui::manufacturer_dlg *ui;

    // Determine whether or not the user changed the notes field
    // to sort-of enforce that they remark why a part was inactivated
    bool notes_updated;

    // Hold the initial state of the preferred and active states to determine state change on save
    bool initial_active_state, initial_preferred_state;

    // Populate all of the controls in the UI with existing values
    void populate_ui_controls();

    // Check the values in the UI elements and verify they're OK
    bool validate_manufacturer();

    // Grab values from the UI elements and construct a manufacturer object
    void construct_and_save_mfg();

    manufacturer mfg;
};

#endif // MANUFACTURER_DLG_H
