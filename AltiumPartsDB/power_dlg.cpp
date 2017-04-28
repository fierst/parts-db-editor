#include "power_dlg.h"
#include "ui_power_dlg.h"

power_dlg::power_dlg(QWidget *parent): ui(new Ui::power_dlg)
{
    Q_UNUSED(parent)
    
    ui->setupUi(this);
}

power_dlg::power_dlg(const std::shared_ptr<library_part> &existing_part) : ui(new Ui::power_dlg)
{
    this->current_part = existing_part;

    ui->setupUi(this);

    ui->box_power_type->setText(current_part->parameter_value("type"));
    ui->box_vin_min->setText(current_part->parameter_value("voltage_input_min"));
    ui->box_vin_max->setText(current_part->parameter_value("voltage_input_max"));
    ui->box_vout_1->setText(current_part->parameter_value("voltage_output_1"));
    ui->box_vout_2->setText(current_part->parameter_value("voltage_output_2"));
    ui->box_vout_3->setText(current_part->parameter_value("voltage_output_3"));
    ui->box_num_outputs->setText(current_part->parameter_value("number_of_outputs"));
    ui->box_current_output->setText(current_part->parameter_value("current_output"));
    ui->box_voltage_iso->setText(current_part->parameter_value("voltage_isolation"));
    ui->box_power->setText(current_part->parameter_value("power"));
    ui->box_efficiency->setText(current_part->parameter_value("efficiency"));
}

power_dlg::~power_dlg()
{
    delete ui;
}

void power_dlg::serialize_params()
{
    params.clear();

    if(current_part == nullptr)
    {
        push_param_to_map(QString("type"), ui->box_power_type->text());
        push_param_to_map(QString("voltage_input_min"), ui->box_vin_min->text());
        push_param_to_map(QString("voltage_input_max"), ui->box_vin_max->text());
        push_param_to_map(QString("voltage_output_1"), ui->box_vout_1->text());
        push_param_to_map(QString("voltage_output_2"), ui->box_vout_2->text());
        push_param_to_map(QString("voltage_output_3"), ui->box_vout_3->text());
        push_param_to_map(QString("number_of_outputs"), ui->box_num_outputs->text());
        push_param_to_map(QString("current_output"), ui->box_current_output->text());
        push_param_to_map(QString("voltage_isolation"), ui->box_voltage_iso->text());
        push_param_to_map(QString("power"), ui->box_power->text());
        push_param_to_map(QString("efficiency"), ui->box_efficiency->text());
    }
    else
    {
        QString type = ui->box_power_type->text();
        QString voltage_input_min = ui->box_vin_min->text();
        QString voltage_input_max = ui->box_vin_max->text();
        QString voltage_output_1 = ui->box_vout_1->text();
        QString voltage_output_2 = ui->box_vout_2->text();
        QString voltage_output_3 = ui->box_vout_3->text();
        QString number_of_outputs = ui->box_num_outputs->text();
        QString current_output = ui->box_current_output->text();
        QString voltage_isolation = ui->box_voltage_iso->text();
        QString power = ui->box_power->text();
        QString efficiency = ui->box_efficiency->text();

        if(current_part->parameter_exists(QString("type")))
        {
            current_part->edit_parameter(QString("type"), type);
        }
        if(current_part->parameter_exists(QString("voltage_input_min")))
        {
            current_part->edit_parameter(QString("voltage_input_min"), voltage_input_min);
        }
        if(current_part->parameter_exists(QString("voltage_input_max")))
        {
            current_part->edit_parameter(QString("voltage_input_max"), voltage_input_max);
        }
        if(current_part->parameter_exists(QString("voltage_output_1")))
        {
            current_part->edit_parameter(QString("voltage_output_1"), voltage_output_1);
        }
        if(current_part->parameter_exists(QString("voltage_output_2")))
        {
            current_part->edit_parameter(QString("voltage_output_2"), voltage_output_2);
        }
        if(current_part->parameter_exists(QString("voltage_output_3")))
        {
            current_part->edit_parameter(QString("voltage_output_3"), voltage_output_3);
        }
        if(current_part->parameter_exists(QString("number_of_outputs")))
        {
            current_part->edit_parameter(QString("number_of_outputs"), number_of_outputs);
        }
        if(current_part->parameter_exists(QString("current_output")))
        {
            current_part->edit_parameter(QString("current_output"), current_output);
        }
        if(current_part->parameter_exists(QString("voltage_isolation")))
        {
            current_part->edit_parameter(QString("voltage_isolation"), voltage_isolation);
        }
        if(current_part->parameter_exists(QString("power")))
        {
            current_part->edit_parameter(QString("power"), power);
        }
        if(current_part->parameter_exists(QString("efficiency")))
        {
            current_part->edit_parameter(QString("efficiency"), efficiency);
        }

    }

    emit(params_set(params));
}

void power_dlg::push_param_to_map(QString key, QString value)
{
    params.insert(std::map<QString, QString>::value_type(key, value));
}

void power_dlg::on_btn_OK_clicked()
{
    serialize_params();

    this->accept();
}

void power_dlg::on_btn_cancel_clicked()
{
    this->reject();
}
