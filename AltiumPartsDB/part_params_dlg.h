#ifndef PART_PARAMS_DLG_H
#define PART_PARAMS_DLG_H

#include <QDialog>

namespace Ui {
class part_params_dlg;
}

class part_params_dlg : public QDialog
{
    Q_OBJECT

public:
    explicit part_params_dlg(QWidget *parent = 0);
    ~part_params_dlg();

private slots:
    void on_btn_manufacturers_clicked();

private:
    Ui::part_params_dlg *ui;
};

#endif // PART_PARAMS_DLG_H
