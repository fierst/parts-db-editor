#include "transistor_dlg.h"
#include "ui_transistor_dlg.h"

transistor_dlg::transistor_dlg(QWidget *parent): ui(new Ui::transistor_dlg)
{
    Q_UNUSED(parent)
    
    ui->setupUi(this);
}

transistor_dlg::transistor_dlg(const std::shared_ptr<library_part> &existing_part) : ui(new Ui::transistor_dlg)
{
    this->current_part = existing_part;

    ui->setupUi(this);

    ui->box_transistor_type->setText(current_part->parameter_value("transistor_type"));
    ui->box_power_max->setText(current_part->parameter_value("power_max"));
    ui->box_operating_temp->setText(current_part->parameter_value("operating_temperature"));
    ui->box_collector_current->setText(current_part->parameter_value("current_collector"));
    ui->box_vce_breakdown->setText(current_part->parameter_value("vce_breakdown"));
    ui->box_vce_sat->setText(current_part->parameter_value("vce_saturation"));
    ui->box_gain->setText(current_part->parameter_value("dc_current_gain"));
    ui->box_drain_current->setText(current_part->parameter_value("current_drain"));
    ui->box_vdss->setText(current_part->parameter_value("vdss"));
    ui->box_drive_voltage->setText(current_part->parameter_value("drive_voltage"));
    ui->box_vgs->setText(current_part->parameter_value("vgs"));
    ui->box_rds_on->setText(current_part->parameter_value("rds_on"));
}

transistor_dlg::~transistor_dlg()
{
    delete ui;
}

void transistor_dlg::serialize_params()
{
    params.clear();

    if(current_part == nullptr)
    {
        push_param_to_map(QString("transistor_type"), ui->box_transistor_type->text());
        push_param_to_map(QString("power_max"), ui->box_power_max->text());
        push_param_to_map(QString("operating_temperature"), ui->box_operating_temp->text());
        push_param_to_map(QString("current_collector"), ui->box_collector_current->text());
        push_param_to_map(QString("vce_breakdown"), ui->box_vce_breakdown->text());
        push_param_to_map(QString("vce_saturation"), ui->box_vce_sat->text());
        push_param_to_map(QString("dc_current_gain"), ui->box_gain->text());
        push_param_to_map(QString("current_drain"), ui->box_drain_current->text());
        push_param_to_map(QString("vdss"), ui->box_vdss->text());
        push_param_to_map(QString("drive_voltage"), ui->box_drive_voltage->text());
        push_param_to_map(QString("vgs"), ui->box_vgs->text());
        push_param_to_map(QString("rds_on"), ui->box_rds_on->text());
    }
    else
    {
        QString transistor_type = ui->box_transistor_type->text();
        QString power_max = ui->box_power_max->text();
        QString operating_temperature = ui->box_operating_temp->text();
        QString current_collector = ui->box_collector_current->text();
        QString vce_breakdown = ui->box_vce_breakdown->text();
        QString vce_saturation = ui->box_vce_sat->text();
        QString dc_current_gain = ui->box_gain->text();
        QString current_drain = ui->box_drain_current->text();
        QString vdss = ui->box_vdss->text();
        QString drive_voltage = ui->box_drive_voltage->text();
        QString vgs = ui->box_vgs->text();
        QString rds_on = ui->box_rds_on->text();

        if(current_part->parameter_exists(QString("transistor_type")))
        {
            current_part->edit_parameter(QString("transistor_type"), transistor_type);
        }
        if(current_part->parameter_exists(QString("power_max")))
        {
            current_part->edit_parameter(QString("power_max"), power_max);
        }
        if(current_part->parameter_exists(QString("operating_temperature")))
        {
            current_part->edit_parameter(QString("operating_temperature"), operating_temperature);
        }
        if(current_part->parameter_exists(QString("current_collector")))
        {
            current_part->edit_parameter(QString("current_collector"), current_collector);
        }
        if(current_part->parameter_exists(QString("vce_breakdown")))
        {
            current_part->edit_parameter(QString("vce_breakdown"), vce_breakdown);
        }
        if(current_part->parameter_exists(QString("vce_saturation")))
        {
            current_part->edit_parameter(QString("vce_saturation"), vce_saturation);
        }
        if(current_part->parameter_exists(QString("dc_current_gain")))
        {
            current_part->edit_parameter(QString("dc_current_gain"), dc_current_gain);
        }
        if(current_part->parameter_exists(QString("current_drain")))
        {
            current_part->edit_parameter(QString("current_drain"), current_drain);
        }
        if(current_part->parameter_exists(QString("vdss")))
        {
            current_part->edit_parameter(QString("vdss"), vdss);
        }
        if(current_part->parameter_exists(QString("drive_voltage")))
        {
            current_part->edit_parameter(QString("drive_voltage"), drive_voltage);
        }
        if(current_part->parameter_exists(QString("vgs")))
        {
            current_part->edit_parameter(QString("vgs"), vgs);
        }
        if(current_part->parameter_exists(QString("rds_on")))
        {
            current_part->edit_parameter(QString("rds_on"), rds_on);
        }
    }

    emit(params_set(params));
}

void transistor_dlg::push_param_to_map(QString key, QString value)
{
    params.insert(std::map<QString, QString>::value_type(key, value));
}

void transistor_dlg::on_btn_OK_clicked()
{
    serialize_params();

    this->accept();
}

void transistor_dlg::on_btn_cancel_clicked()
{
    this->reject();
}
