#include "transformer_dlg.h"
#include "ui_transformer_dlg.h"

transformer_dlg::transformer_dlg(QWidget *parent): ui(new Ui::transformer_dlg)
{
    Q_UNUSED(parent)
    
    ui->setupUi(this);
}

transformer_dlg::transformer_dlg(const std::shared_ptr<library_part> &existing_part) : ui(new Ui::transformer_dlg)
{
    this->current_part = existing_part;

    ui->setupUi(this);

    ui->box_transformer_type->setText(current_part->parameter_value("transformer_type"));
    ui->box_voltage_primary->setText(current_part->parameter_value("voltage_primary"));
    ui->box_voltage_secondary->setText(current_part->parameter_value("voltage_secondary"));
    ui->box_power_max->setText(current_part->parameter_value("power_max"));
    ui->box_current_output->setText(current_part->parameter_value("current_output"));
    ui->box_voltage_isolation->setText(current_part->parameter_value("voltage_isolation"));
    ui->box_inductance->setText(current_part->parameter_value("inductance"));
    ui->box_turns_ratio->setText(current_part->parameter_value("turns_ratio"));
    // Set the center-tap check box by comparing the value in "center_tap" to TRUE ("1")
    ui->cbx_center_tap->setChecked(QString::compare(QString("1"), current_part->parameter_value("center_tap")));
}

transformer_dlg::~transformer_dlg()
{
    delete ui;
}

void transformer_dlg::serialize_params()
{
    params.clear();

    if(current_part == nullptr)
    {
        push_param_to_map(QString("transformer_type"), ui->box_transformer_type->text());
        push_param_to_map(QString("voltage_primary"), ui->box_voltage_primary->text());
        push_param_to_map(QString("voltage_secondary"), ui->box_voltage_secondary->text());
        push_param_to_map(QString("center_tap"), ui->cbx_center_tap->checkState() ==  Qt::Checked ? QString("1") : QString("0"));
        push_param_to_map(QString("power_max"), ui->box_power_max->text());
        push_param_to_map(QString("current_output"), ui->box_current_output->text());
        push_param_to_map(QString("voltage_isolation"), ui->box_voltage_isolation->text());
        push_param_to_map(QString("inductance"), ui->box_inductance->text());
        push_param_to_map(QString("turns_ratio"), ui->box_turns_ratio->text());
    }
    else
    {
        QString transformer_type = ui->box_transformer_type->text();
        QString voltage_primary = ui->box_voltage_primary->text();
        QString voltage_secondary = ui->box_voltage_secondary->text();
        QString center_tap = ui->cbx_center_tap->checkState() == Qt::Checked ? QString("1") : QString("0");
        QString power_max = ui->box_power_max->text();
        QString current_output = ui->box_current_output->text();
        QString voltage_isolation = ui->box_voltage_isolation->text();
        QString inductance = ui->box_inductance->text();
        QString turns_ratio = ui->box_turns_ratio->text();

        if(current_part->parameter_exists(QString("transformer_type")))
        {
            current_part->edit_parameter(QString("transformer_type"), transformer_type);
        }
        else
        {
            current_part->add_parameter(QString("transformer_type"), transformer_type);
        }

        if(current_part->parameter_exists(QString("voltage_primary")))
        {
            current_part->edit_parameter(QString("voltage_primary"), voltage_primary);
        }
        else
        {
            current_part->add_parameter(QString("voltage_primary"), voltage_primary);
        }

        if(current_part->parameter_exists(QString("voltage_secondary")))
        {
            current_part->edit_parameter(QString("voltage_secondary"), voltage_secondary);
        }
        else
        {
            current_part->add_parameter(QString("voltage_secondary"), voltage_secondary);
        }

        if(current_part->parameter_exists(QString("center_tap")))
        {
            current_part->edit_parameter(QString("center_tap"), center_tap);
        }
        else
        {
            current_part->add_parameter(QString("center_tap"), center_tap);
        }

        if(current_part->parameter_exists(QString("power_max")))
        {
            current_part->edit_parameter(QString("power_max"), power_max);
        }
        else
        {
            current_part->add_parameter(QString("power_max"), power_max);
        }

        if(current_part->parameter_exists(QString("current_output")))
        {
            current_part->edit_parameter(QString("current_output"), current_output);
        }
        else
        {
            current_part->add_parameter(QString("current_output"), current_output);
        }

        if(current_part->parameter_exists(QString("voltage_isolation")))
        {
            current_part->edit_parameter(QString("voltage_isolation"), voltage_isolation);
        }
        else
        {
            current_part->add_parameter(QString("voltage_isolation"), voltage_isolation);
        }

        if(current_part->parameter_exists(QString("inductance")))
        {
            current_part->edit_parameter(QString("inductance"), inductance);
        }
        else
        {
            current_part->add_parameter(QString("inductance"), inductance);
        }

        if(current_part->parameter_exists(QString("turns_ratio")))
        {
            current_part->edit_parameter(QString("turns_ratio"), turns_ratio);
        }
        else
        {
            current_part->add_parameter(QString("turns_ratio"), turns_ratio);
        }
    }

    emit(params_set(params));
}

void transformer_dlg::push_param_to_map(QString key, QString value)
{
    params.insert(std::map<QString, QString>::value_type(key, value));
}

void transformer_dlg::on_btn_OK_clicked()
{
    serialize_params();

    this->accept();
}

void transformer_dlg::on_btn_cancel_clicked()
{
    this->reject();
}
