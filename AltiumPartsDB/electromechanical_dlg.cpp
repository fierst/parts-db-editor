#include "electromechanical_dlg.h"
#include "ui_electromechanical_dlg.h"

electromechanical_dlg::electromechanical_dlg(QWidget *parent): ui(new Ui::electromechanical_dlg)
{
    Q_UNUSED(parent)
    
    ui->setupUi(this);
}

electromechanical_dlg::electromechanical_dlg(const std::shared_ptr<library_part>& existing_part) : ui(new Ui::electromechanical_dlg)
{
    this->current_part = existing_part;

    ui->setupUi(this);

    ui->box_circuit->setText(current_part->parameter_value("circuit"));
    ui->box_coil_current->setText(current_part->parameter_value("coil_current"));
    ui->box_coil_type->setText(current_part->parameter_value("coil_type"));
    ui->box_coil_voltage->setText(current_part->parameter_value("coil_voltage"));
    ui->box_current_rating->setText(current_part->parameter_value("current_rating"));
    ui->box_electromechanical_type->setText(current_part->parameter_value("electromechanical_type"));
    ui->box_load_voltage->setText(current_part->parameter_value("load_voltage"));
    ui->box_on_resistance->setText(current_part->parameter_value("on_state_resistance"));
    ui->box_operating_time->setText(current_part->parameter_value("operating_time"));
    ui->box_release_time->setText(current_part->parameter_value("release_time"));
    ui->box_voltage_input->setText(current_part->parameter_value("voltage_input"));
    ui->box_voltage_off->setText(current_part->parameter_value("voltage_off"));
    ui->box_voltage_on->setText(current_part->parameter_value("voltage_on"));
    ui->box_voltage_rating->setText(current_part->parameter_value("voltage_rating"));
}

electromechanical_dlg::~electromechanical_dlg()
{
    delete ui;
}

void electromechanical_dlg::serialize_params()
{
    params.clear();

    if(current_part == nullptr)
    {
        push_param_to_map(QString("type"), ui->box_electromechanical_type->text());
        push_param_to_map(QString("current_rating"), ui->box_current_rating->text());
        push_param_to_map(QString("voltage_rating"), ui->box_voltage_rating->text());
        push_param_to_map(QString("on_state_resistance"), ui->box_on_resistance->text());
        push_param_to_map(QString("voltage_input"), ui->box_voltage_input->text());
        push_param_to_map(QString("voltage_load"), ui->box_load_voltage->text());
        push_param_to_map(QString("circuit"), ui->box_circuit->text());
        push_param_to_map(QString("coil_type"), ui->box_coil_type->text());
        push_param_to_map(QString("coil_current"), ui->box_coil_current->text());
        push_param_to_map(QString("coil_voltage"), ui->box_coil_voltage->text());
        push_param_to_map(QString("voltage_on"), ui->box_voltage_on->text());
        push_param_to_map(QString("voltage_off"), ui->box_voltage_off->text());
        push_param_to_map(QString("operating_time"), ui->box_operating_time->text());
        push_param_to_map(QString("release_time"), ui->box_release_time->text());
    }
    else
    {
        QString type = ui->box_electromechanical_type->text();
        QString current_rating = ui->box_current_rating->text();
        QString voltage_rating = ui->box_voltage_rating->text();
        QString on_state_resistance = ui->box_on_resistance->text();
        QString voltage_input = ui->box_voltage_input->text();
        QString voltage_load = ui->box_load_voltage->text();
        QString circuit = ui->box_circuit->text();
        QString coil_type = ui->box_coil_type->text();
        QString coil_current = ui->box_coil_current->text();
        QString coil_voltage = ui->box_coil_voltage->text();
        QString voltage_on = ui->box_voltage_on->text();
        QString voltage_off = ui->box_voltage_off->text();
        QString operating_time = ui->box_operating_time->text();
        QString release_time = ui->box_release_time->text();

        if(current_part->parameter_exists(QString("type")))
        {
            current_part->edit_parameter(QString("type"), type);
        }
        if(current_part->parameter_exists(QString("current_rating")))
        {
            current_part->edit_parameter(QString("current_rating"), current_rating);
        }
        if(current_part->parameter_exists(QString("voltage_rating")))
        {
            current_part->edit_parameter(QString("voltage_rating"), voltage_rating);
        }
        if(current_part->parameter_exists(QString("on_state_resistance")))
        {
            current_part->edit_parameter(QString("on_state_resistance"), on_state_resistance);
        }
        if(current_part->parameter_exists(QString("voltage_input")))
        {
            current_part->edit_parameter(QString("voltage_input"), voltage_input);
        }
        if(current_part->parameter_exists(QString("voltage_load")))
        {
            current_part->edit_parameter(QString("voltage_load"), voltage_load);
        }
        if(current_part->parameter_exists(QString("circuit")))
        {
            current_part->edit_parameter(QString("circuit"), circuit);
        }
        if(current_part->parameter_exists(QString("coil_type")))
        {
            current_part->edit_parameter(QString("coil_type"), coil_type);
        }
        if(current_part->parameter_exists(QString("coil_current")))
        {
            current_part->edit_parameter(QString("coil_current"), coil_current);
        }
        if(current_part->parameter_exists(QString("coil_voltage")))
        {
            current_part->edit_parameter(QString("coil_voltage"), coil_voltage);
        }
        if(current_part->parameter_exists(QString("voltage_on")))
        {
            current_part->edit_parameter(QString("voltage_on"), voltage_on);
        }
        if(current_part->parameter_exists(QString("voltage_off")))
        {
            current_part->edit_parameter(QString("voltage_off"), voltage_off);
        }
        if(current_part->parameter_exists(QString("operating_time")))
        {
            current_part->edit_parameter(QString("operating_time"), operating_time);
        }
        if(current_part->parameter_exists(QString("release_time")))
        {
            current_part->edit_parameter(QString("release_time"), release_time);
        }
    }

    emit(params_set(params));
}

void electromechanical_dlg::push_param_to_map(QString key, QString value)
{
    params.insert(std::map<QString, QString>::value_type(key, value));
}

void electromechanical_dlg::on_btn_OK_clicked()
{
    serialize_params();

    this->accept();
}

void electromechanical_dlg::on_btn_cancel_clicked()
{
    this->reject();
}
