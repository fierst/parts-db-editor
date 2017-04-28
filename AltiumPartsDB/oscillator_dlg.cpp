#include "oscillator_dlg.h"
#include "ui_oscillator_dlg.h"

oscillator_dlg::oscillator_dlg(QWidget *parent): ui(new Ui::oscillator_dlg)
{
    Q_UNUSED(parent)
    
    ui->setupUi(this);
}

oscillator_dlg::oscillator_dlg(const std::shared_ptr<library_part> &existing_part) : ui(new Ui::oscillator_dlg)
{
    this->current_part = existing_part;

    ui->setupUi(this);

    ui->box_frequency->setText(current_part->parameter_value("frequency"));
    ui->box_tolerance->setText(current_part->parameter_value("tolerance"));
    ui->box_load_capacitance->setText(current_part->parameter_value("load_capacitance"));
    ui->box_esr->setText(current_part->parameter_value("equivalent_series_resistance"));
    ui->box_voltage->setText(current_part->parameter_value("voltage"));
    ui->box_current->setText(current_part->parameter_value("current"));
    ui->box_output_type->setText(current_part->parameter_value("output_type"));
}

oscillator_dlg::~oscillator_dlg()
{
    delete ui;
}

void oscillator_dlg::serialize_params()
{
    params.clear();

    if(current_part == nullptr)
    {
        push_param_to_map(QString("frequency"), ui->box_frequency->text());
        push_param_to_map(QString("tolerance"), ui->box_tolerance->text());
        push_param_to_map(QString("load_capacitance"), ui->box_load_capacitance->text());
        push_param_to_map(QString("equivalent_series_resistance"), ui->box_esr->text());
        push_param_to_map(QString("voltage"), ui->box_voltage->text());
        push_param_to_map(QString("current"), ui->box_current->text());
        push_param_to_map(QString("output_type"), ui->box_output_type->text());
    }
    else
    {
        QString frequency = ui->box_frequency->text();
        QString tolerance = ui->box_tolerance->text();
        QString load_capacitance = ui->box_load_capacitance->text();
        QString equivalent_series_resistance = ui->box_esr->text();
        QString voltage = ui->box_voltage->text();
        QString current = ui->box_current->text();
        QString output_type = ui->box_output_type->text();

        if(current_part->parameter_exists(QString("frequency")))
        {
            current_part->edit_parameter(QString("frequency"), frequency);
        }
        if(current_part->parameter_exists(QString("tolerance")))
        {
            current_part->edit_parameter(QString("tolerance"), tolerance);
        }
        if(current_part->parameter_exists(QString("load_capacitance")))
        {
            current_part->edit_parameter(QString("load_capacitance"), load_capacitance);
        }
        if(current_part->parameter_exists(QString("equivalent_series_resistance")))
        {
            current_part->edit_parameter(QString("equivalent_series_resistance"), equivalent_series_resistance);
        }
        if(current_part->parameter_exists(QString("voltage")))
        {
            current_part->edit_parameter(QString("voltage"), voltage);
        }
        if(current_part->parameter_exists(QString("current")))
        {
            current_part->edit_parameter(QString("current"), current);
        }
        if(current_part->parameter_exists(QString("output_type")))
        {
            current_part->edit_parameter(QString("output_type"), output_type);
        }
    }

    emit(params_set(params));
}

void oscillator_dlg::push_param_to_map(QString key, QString value)
{
    params.insert(std::map<QString, QString>::value_type(key, value));
}

void oscillator_dlg::on_btn_OK_clicked()
{
    serialize_params();

    this->accept();
}

void oscillator_dlg::on_btn_cancel_clicked()
{
    this->reject();
}
