#ifndef CAPACITOR_DLG_H
#define CAPACITOR_DLG_H

#include <QDialog>
#include <QMessageBox>
#include <QtSql>
#include <QStringList>

#include <map>
#include <memory>

#include "library_part.h"

namespace Ui {
  class capacitor_dlg;
}

class capacitor_dlg : public QDialog
{
  Q_OBJECT

public:

    explicit capacitor_dlg(QWidget *parent = 0);

    // Assign shared_ptr to existing part
    capacitor_dlg(std::shared_ptr<library_part>);

    ~capacitor_dlg();

signals:

    void params_set(const std::map<QString, QString> &params);

private slots:

    void on_btn_OK_clicked();

    void on_btn_cancel_clicked();

private:
    Ui::capacitor_dlg *ui;

    std::shared_ptr<library_part> current_part;

    std::map<QString, QString> params;

    const QStringList units = {"pF", "nF", "μF", "mF"};

    void serialize_params();

    void push_param_to_map(QString key, QString value);

    void parse_capacitance();
};

#endif //CAPACITOR_DLG_H
