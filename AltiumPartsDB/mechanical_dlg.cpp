#include "mechanical_dlg.h"
#include "ui_mechanical_dlg.h"

mechanical_dlg::mechanical_dlg(QWidget *parent): ui(new Ui::mechanical_dlg)
{
    Q_UNUSED(parent)
    
    ui->setupUi(this);
}

mechanical_dlg::mechanical_dlg(const std::shared_ptr<library_part> &existing_part) : ui(new Ui::mechanical_dlg)
{
    this->current_part = existing_part;

    ui->setupUi(this);

    ui->box_mechanical_type->setText(current_part->parameter_value("mechanical_type"));
}

mechanical_dlg::~mechanical_dlg()
{
    delete ui;
}

void mechanical_dlg::serialize_params()
{
    params.clear();

    if(current_part == nullptr)
    {
        push_param_to_map(QString("mechanical_type"), ui->box_mechanical_type->text());
    }
    else
    {
        QString mechanical_type = ui->box_mechanical_type->text();

        if(current_part->parameter_exists(QString("mechanical_type")))
        {
            current_part->edit_parameter(QString("mechanical_type"), mechanical_type);
        }
        else
        {
            current_part->add_parameter(QString("mechanical_type"), mechanical_type);
        }
    }

    emit(params_set(params));
}

void mechanical_dlg::push_param_to_map(QString key, QString value)
{
    params.insert(std::map<QString, QString>::value_type(key, value));
}

void mechanical_dlg::on_btn_OK_clicked()
{
    serialize_params();

    this->accept();
}

void mechanical_dlg::on_btn_cancel_clicked()
{
    this->reject();
}
