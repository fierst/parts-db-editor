#include "part_params_dlg.h"
#include "ui_part_params_dlg.h"

#include "mfg_list_dlg.h"

part_params_dlg::part_params_dlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::part_params_dlg)
{
    ui->setupUi(this);

    // Don't allow the user to resize the dialog because it would mess up the layout
    this->setWindowFlags(this->windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
}

part_params_dlg::~part_params_dlg()
{
    delete ui;
}

void part_params_dlg::on_btn_manufacturers_clicked()
{
    mfg_list_dlg mfgs_dlg;
    mfgs_dlg.setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
    mfgs_dlg.exec();
}
