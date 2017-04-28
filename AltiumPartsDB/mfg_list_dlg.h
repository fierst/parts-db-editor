#ifndef MFG_LIST_DLG_H
#define MFG_LIST_DLG_H

#include <QDialog>

#include <memory>

#include "manufacturer_dlg.h"
#include "mfg_list_model.h"
#include "library_part.h"

namespace Ui {
class mfg_list_dlg;
}

class mfg_list_dlg : public QDialog
{
    Q_OBJECT

public:

    explicit mfg_list_dlg(QWidget *parent = 0);

    mfg_list_dlg(library_part & existing_part);

    ~mfg_list_dlg();

signals:

    void manufacturer_list_populated(const std::map<QString, QString> & mfgs);

private slots:
    void on_btn_add_clicked();

    void on_btn_edit_clicked();

    void on_btn_delete_clicked();

    void on_btn_ok_clicked();

    void on_btn_cancel_clicked();

private:

    // Slot for adding a new manufacturer to the model when the user makes one.
    void new_mfg(const manufacturer &);

    // Slot for editing an existing manufacturer when the user changes it
    void edited_mfg(const manufacturer & edited_manufacturer);

    // The model to hold the manufacturer information, which populates the table view
    mfg_list_model *mfgs_list;

    // Pointer to the current part being edited
    std::shared_ptr<library_part> current_part;

    Ui::mfg_list_dlg *ui;
};

#endif // MFG_LIST_DLG_H
