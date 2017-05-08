#include "ic_dlg.h"
#include "ui_ic_dlg.h"

ic_dlg::ic_dlg(QWidget *parent): ui(new Ui::ic_dlg)
{
    Q_UNUSED(parent)
    
    ui->setupUi(this);
}

ic_dlg::ic_dlg(const std::shared_ptr<library_part> &existing_part) : ui(new Ui::ic_dlg)
{
    this->current_part = existing_part;

    ui->setupUi(this);

    ui->box_temperature->setText(current_part->parameter_value("operating_temperature"));
}

ic_dlg::~ic_dlg()
{
    delete ui;
}

void ic_dlg::serialize_params()
{
    params.clear();

    if(current_part == nullptr)
    {
        push_param_to_map(QString("operating_temperature"), ui->box_temperature->text());
    }
    else
    {
        QString operating_temperature = ui->box_temperature->text();

        if(current_part->parameter_exists(QString("operating_temperature")))
        {
            current_part->edit_parameter(QString("operating_temperature"), operating_temperature);
        }
        else
        {
            current_part->add_parameter(QString("operating_temperature"), operating_temperature);
        }
    }

    emit(params_set(params));
}

void ic_dlg::push_param_to_map(QString key, QString value)
{

    params.insert(std::map<QString, QString>::value_type(key, value));
}

void ic_dlg::on_btn_OK_clicked()
{
    serialize_params();

    this->accept();
}

void ic_dlg::on_btn_cancel_clicked()
{
    this->reject();
}
