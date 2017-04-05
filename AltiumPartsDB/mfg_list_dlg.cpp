#include "mfg_list_dlg.h"
#include "ui_mfg_list_dlg.h"

#include <QDebug>

mfg_list_dlg::mfg_list_dlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mfg_list_dlg)
{
    ui->setupUi(this);

    mfgs_list = new mfg_list_model(this);

    ui->tbl_mfg_list->setModel(mfgs_list);
    ui->tbl_mfg_list->setSelectionBehavior(QAbstractItemView::SelectRows);                          // Select whole rows
    ui->tbl_mfg_list->setSelectionMode(QAbstractItemView::SingleSelection);                         // Only allow a single row selection
    ui->tbl_mfg_list->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);      // Automatically resize columns
}

mfg_list_dlg::~mfg_list_dlg()
{
    delete ui;
}

// Slot for adding a new manufacturer to the model when the user makes one.
void mfg_list_dlg::new_mfg(const manufacturer & new_manufacturer)
{
    mfgs_list->add_manufacturer(new_manufacturer);
}

void mfg_list_dlg::edited_mfg(const manufacturer & edited_manufacturer)
{
    mfgs_list->edit_manufacturer(edited_manufacturer);
}

void mfg_list_dlg::on_btn_add_clicked()
{
    // Check to make sure that there's room to add another manufacturer (we've only allocated 15 in the database
    if(mfgs_list->available_mfg_slots() == 0)
    {
        QMessageBox::warning(this, "Error", "Couldn't add another manufacturer, maximum number reached", QMessageBox::StandardButton::Ok);
        return;
    }

    manufacturer_dlg mfg_dlg;
    mfg_dlg.setModal(true);
    mfg_dlg.setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
    connect(&mfg_dlg, &manufacturer_dlg::new_manufacturer, this, &mfg_list_dlg::new_mfg);
    mfg_dlg.exec();
}

void mfg_list_dlg::on_btn_edit_clicked()
{
    if(ui->tbl_mfg_list->selectionModel()->selectedRows().count() > 0)
    {
        manufacturer_dlg mfg_dlg(mfgs_list->get_mfg_at_index(ui->tbl_mfg_list->selectionModel()->selectedRows().at(0).row()));
        mfg_dlg.setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
        connect(&mfg_dlg, &manufacturer_dlg::new_manufacturer, this, &mfg_list_dlg::edited_mfg);
        mfg_dlg.exec();
    }
}

void mfg_list_dlg::on_btn_delete_clicked()
{
    // If there are no manufacturers or no rows selected, don't actually do anything
    if(mfgs_list->available_mfg_slots() != MAXIMUM_MFGS && ui->tbl_mfg_list->selectionModel()->selectedRows().count() > 0)
    {
        QMessageBox::StandardButton actually_delete_mfg;

        // Verify the user actually wants to delete
        actually_delete_mfg = QMessageBox::question(this, "Delete", "If a manufacturer is no longer active or preferred, it is better to edit than delete.\nActually delete?", QMessageBox::StandardButton::Yes | QMessageBox::StandardButton::No);

        if(actually_delete_mfg == QMessageBox::Yes)
        {
            mfgs_list->remove_manufacturer(ui->tbl_mfg_list->selectionModel()->selectedRows().at(0).row());
        }
    }
}

void mfg_list_dlg::on_btn_ok_clicked()
{
    int num_rows = ui->tbl_mfg_list->model()->rowCount();
}
