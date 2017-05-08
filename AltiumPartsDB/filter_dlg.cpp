#include "filter_dlg.h"
#include "ui_filter_dlg.h"

filter_dlg::filter_dlg(QWidget *parent): ui(new Ui::filter_dlg)
{
    Q_UNUSED(parent)
    
    ui->setupUi(this);
}

filter_dlg::filter_dlg(const std::shared_ptr<library_part>& existing_part) : ui(new Ui::filter_dlg)
{
    this->current_part = existing_part;

    ui->setupUi(this);

    ui->box_filter_type->setText(current_part->parameter_value("filter_type"));
    ui->box_impedance->setText(current_part->parameter_value("impedance"));
    ui->box_inductance->setText(current_part->parameter_value("inductance"));
    ui->box_bandwidth->setText(current_part->parameter_value("bandwidth"));
    ui->box_frequency->setText(current_part->parameter_value("frequency"));
    ui->box_resistance->setText(current_part->parameter_value("resistance"));
    ui->box_voltage_rating->setText(current_part->parameter_value("voltage_rating"));
    ui->box_current_rating->setText(current_part->parameter_value("current_rating"));
    ui->box_operating_temperature->setText(current_part->parameter_value("operating_temperature"));
}

filter_dlg::~filter_dlg()
{
    delete ui;
}

void filter_dlg::serialize_params()
{
    params.clear();

    if(current_part == nullptr)
    {
        push_param_to_map(QString("filter_type"), ui->box_filter_type->text());
        push_param_to_map(QString("impedance"), ui->box_impedance->text());
        push_param_to_map(QString("inductance"), ui->box_inductance->text());
        push_param_to_map(QString("bandwidth"), ui->box_bandwidth->text());
        push_param_to_map(QString("frequency"), ui->box_frequency->text());
        push_param_to_map(QString("resistance"), ui->box_resistance->text());
        push_param_to_map(QString("voltage_rating"), ui->box_voltage_rating->text());
        push_param_to_map(QString("current_rating"), ui->box_current_rating->text());
        push_param_to_map(QString("operating_temperature"), ui->box_operating_temperature->text());
    }
    else
    {
        QString filter_type = ui->box_filter_type->text();
        QString impedance = ui->box_impedance->text();
        QString inductance = ui->box_inductance->text();
        QString bandwidth = ui->box_bandwidth->text();
        QString frequency = ui->box_frequency->text();
        QString resistance = ui->box_resistance->text();
        QString voltage_rating = ui->box_voltage_rating->text();
        QString current_rating = ui->box_current_rating->text();
        QString operating_temperature = ui->box_operating_temperature->text();

        if(current_part->parameter_exists(QString("filter_type")))
        {
            current_part->edit_parameter(QString("filter_type"), filter_type);
        }
        else
        {
            current_part->add_parameter(QString("filter_type"), filter_type);
        }

        if(current_part->parameter_exists(QString("impedance")))
        {
            current_part->edit_parameter(QString("impedance"), impedance);
        }
        else
        {
            current_part->add_parameter(QString("impedance"), impedance);
        }

        if(current_part->parameter_exists(QString("inductance")))
        {
            current_part->edit_parameter(QString("inductance"), inductance);
        }
        else
        {
            current_part->add_parameter(QString("inductance"), inductance);
        }

        if(current_part->parameter_exists(QString("bandwidth")))
        {
            current_part->edit_parameter(QString("bandwidth"), bandwidth);
        }
        else
        {
            current_part->add_parameter(QString("bandwidth"), bandwidth);
        }

        if(current_part->parameter_exists(QString("frequency")))
        {
            current_part->edit_parameter(QString("frequency"), frequency);
        }
        else
        {
            current_part->add_parameter(QString("frequency"), frequency);
        }

        if(current_part->parameter_exists(QString("resistance")))
        {
            current_part->edit_parameter(QString("resistance"), resistance);
        }
        else
        {
            current_part->add_parameter(QString("resistance"), resistance);
        }

        if(current_part->parameter_exists(QString("voltage_rating")))
        {
            current_part->edit_parameter(QString("voltage_rating"), voltage_rating);
        }
        else
        {
            current_part->add_parameter(QString("voltage_rating"), voltage_rating);
        }

        if(current_part->parameter_exists(QString("current_rating")))
        {
            current_part->edit_parameter(QString("current_rating"), current_rating);
        }
        else
        {
            current_part->add_parameter(QString("current_rating"), current_rating);
        }

        if(current_part->parameter_exists(QString("operating_temperature")))
        {
            current_part->edit_parameter(QString("operating_temperature"), operating_temperature);
        }
        else
        {
            current_part->add_parameter(QString("operating_temperature"), operating_temperature);
        }

    }
}

void filter_dlg::push_param_to_map(QString key, QString value)
{
    params.insert(std::map<QString, QString>::value_type(key, value));
}

void filter_dlg::on_btn_OK_clicked()
{
    serialize_params();

    this->accept();
}

void filter_dlg::on_btn_cancel_clicked()
{
    this->reject();
}
