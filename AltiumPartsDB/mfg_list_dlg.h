#ifndef MFG_LIST_DLG_H
#define MFG_LIST_DLG_H

#include <QDialog>

#include "manufacturer_dlg.h"
#include "mfg_list_model.h"

namespace Ui {
class mfg_list_dlg;
}

class mfg_list_dlg : public QDialog
{
    Q_OBJECT

public:

    explicit mfg_list_dlg(QWidget *parent = 0);
    ~mfg_list_dlg();

private slots:
    void on_btn_add_clicked();

    void on_btn_edit_clicked();

    void on_btn_delete_clicked();

    void on_btn_ok_clicked();

private:

    // Slot for adding a new manufacturer to the model when the user makes one.
    void new_mfg(const manufacturer &);

    // Slot for editing an existing manufacturer when the user changes it
    void edited_mfg(const manufacturer & edited_manufacturer);

    void dbg_sec_moved(int logical_index, int old_visual, int new_visual);

    // The model to hold the manufacturer information, which populates the table view
    mfg_list_model *mfgs_list;

    Ui::mfg_list_dlg *ui;
};

#endif // MFG_LIST_DLG_H
