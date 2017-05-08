#include "resistor_dlg.h"
#include "ui_resistor_dlg.h"

resistor_dlg::resistor_dlg(QWidget *parent): ui(new Ui::resistor_dlg)
{
    Q_UNUSED(parent)
    
    ui->setupUi(this);
}

resistor_dlg::resistor_dlg(const std::shared_ptr<library_part> &existing_part) : ui(new Ui::resistor_dlg)
{
    this->current_part = existing_part;

    ui->setupUi(this);

    ui->box_resistance->setText((current_part->parameter_value("resistance")));
    ui->box_tolerance->setText(current_part->parameter_value("tolerance"));
    ui->box_power->setText(current_part->parameter_value("power"));
    ui->box_operating_temp->setText(current_part->parameter_value("operating_temperature"));
    ui->box_tempco->setText(current_part->parameter_value("temperature_coefficient"));
}

resistor_dlg::~resistor_dlg()
{
    delete ui;
}

void resistor_dlg::serialize_params()
{
    params.clear();

    if(current_part == nullptr)
    {
        push_param_to_map(QString("resistance"), ui->box_resistance->text());
        push_param_to_map(QString("tolerance"), ui->box_tolerance->text());
        push_param_to_map(QString("power"), ui->box_power->text());
        push_param_to_map(QString("operating_temperature"), ui->box_operating_temp->text());
        push_param_to_map(QString("temperature_coefficient"), ui->box_tempco->text());
    }
    else
    {
        QString resistance = ui->box_resistance->text();
        QString tolerance = ui->box_tolerance->text();
        QString power = ui->box_power->text();
        QString operating_temperature = ui->box_operating_temp->text();
        QString temperature_coefficient = ui->box_tempco->text();

        if(current_part->parameter_exists(QString("resistance")))
        {
            current_part->edit_parameter(QString("resistance"), resistance);
        }
        else
        {
            current_part->add_parameter(QString("resistance"), resistance);
        }

        if(current_part->parameter_exists(QString("tolerance")))
        {
            current_part->edit_parameter(QString("tolerance"), tolerance);
        }
        else
        {
            current_part->add_parameter(QString("tolerance"), tolerance);
        }

        if(current_part->parameter_exists(QString("power")))
        {
            current_part->edit_parameter(QString("power"), power);
        }
        else
        {
            current_part->add_parameter(QString("power"), power);
        }

        if(current_part->parameter_exists(QString("operating_temperature")))
        {
            current_part->edit_parameter(QString("operating_temperature"), operating_temperature);
        }
        else
        {
            current_part->add_parameter(QString("operating_temperature"), operating_temperature);
        }

        if(current_part->parameter_exists(QString("temperature_coefficient")))
        {
            current_part->edit_parameter(QString("temperature_coefficient"), temperature_coefficient);
        }
        else
        {
            current_part->add_parameter(QString("temperature_coefficient"), temperature_coefficient);
        }
    }

    emit(params_set(params));
}

void resistor_dlg::push_param_to_map(QString key, QString value)
{
    params.insert(std::map<QString, QString>::value_type(key, value));
}

void resistor_dlg::on_btn_OK_clicked()
{
    serialize_params();

    this->accept();
}

void resistor_dlg::on_btn_cancel_clicked()
{
    this->reject();
}
