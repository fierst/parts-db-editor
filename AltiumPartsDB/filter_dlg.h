#ifndef FILTER_DLG_H
#define FILTER_DLG_H

#include <QDialog>
#include <QMessageBox>
#include <QtSql>

#include <map>
#include <memory>

#include "library_part.h"

namespace Ui {
  class filter_dlg;
}

class filter_dlg : public QDialog
{
    Q_OBJECT

public:
    explicit filter_dlg(QWidget *parent = 0);

    // Assign shared_ptr to existing part
    filter_dlg(const std::shared_ptr<library_part> &);
    
    ~filter_dlg();

signals:
    void params_set(const std::map<QString, QString> &params);

private slots:
    void on_btn_OK_clicked();

    void on_btn_cancel_clicked();

private:

    std::shared_ptr<library_part> current_part;

    std::map<QString, QString> params;

    void serialize_params();

    void push_param_to_map(QString key, QString value);

    Ui::filter_dlg *ui;
};

#endif //FILTER_DLG_H
