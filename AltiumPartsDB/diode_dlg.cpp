#include "diode_dlg.h"
#include "ui_diode_dlg.h"

diode_dlg::diode_dlg(QWidget *parent): ui(new Ui::diode_dlg)
{
    Q_UNUSED(parent)
    
    ui->setupUi(this);
}

diode_dlg::diode_dlg(const std::shared_ptr<library_part>& existing_part) : ui(new Ui::diode_dlg)
{
    this->current_part = existing_part;

    ui->setupUi(this);

    ui->box_capacitance->setText(current_part->parameter_value("capacitance"));
    ui->box_diode_type->setText(current_part->parameter_value("type"));
    ui->box_impedance->setText(current_part->parameter_value("impedance_max"));
    ui->box_power_max->setText(current_part->parameter_value("power_max"));
    ui->box_rev_current->setText(current_part->parameter_value("current_reverse"));
    ui->box_current_avg->setText(current_part->parameter_value("current_avg"));
    ui->box_reverse_recovery_time->setText(current_part->parameter_value("reverse_recovery_time"));
    ui->box_tolerance->setText(current_part->parameter_value("tolerance"));
    ui->box_voltage_fwd->setText(current_part->parameter_value("voltage_forward"));
    ui->box_voltage_rev->setText(current_part->parameter_value("voltage_fwd"));
    ui->box_zener_voltage->setText(current_part->parameter_value("voltage_zener"));

}

diode_dlg::~diode_dlg()
{
    delete ui;
}

void diode_dlg::serialize_params()
{
    params.clear();

    if(current_part == nullptr)
    {
        push_param_to_map(QString("type"), ui->box_diode_type->text() );
        push_param_to_map(QString("current_reverse"),  ui->box_rev_current->text());
        push_param_to_map(QString("current_avg"), ui->box_current_avg->text());
        push_param_to_map(QString("voltage_forward"), ui->box_voltage_fwd->text());
        push_param_to_map(QString("voltage_rev"), ui->box_voltage_rev->text());
        push_param_to_map(QString("voltage_zener"), ui->box_zener_voltage->text());
        push_param_to_map(QString("tolerance"), ui->box_tolerance->text());
        push_param_to_map(QString("power_max"), ui->box_power_max->text());
        push_param_to_map(QString("impedance_max"), ui->box_impedance->text());
        push_param_to_map(QString("capacitance"), ui->box_capacitance->text());
        push_param_to_map(QString("reverse_recovery_time"), ui->box_reverse_recovery_time->text());
    }
    else
    {
        QString type = ui->box_diode_type->text();
        QString current_reverse = ui->box_rev_current->text();
        QString current_avg = ui->box_current_avg->text();
        QString voltage_forward = ui->box_voltage_fwd->text();
        QString voltage_rev = ui->box_voltage_rev->text();
        QString voltage_zener = ui->box_zener_voltage->text();
        QString tolerance = ui->box_tolerance->text();
        QString power_max = ui->box_power_max->text();
        QString impedance_max = ui->box_impedance->text();
        QString capacitance = ui->box_capacitance->text();
        QString reverse_recovery_time = ui->box_reverse_recovery_time->text();

        if(current_part->parameter_exists(QString("type")))
        {
            current_part->edit_parameter(QString("type"), type);
        }
        else
        {
            current_part->add_parameter(QString("type"), type);
        }

        if(current_part->parameter_exists(QString("current_avg")))
        {
            current_part->edit_parameter(QString("current_avg"), current_avg);
        }
        else
        {
            current_part->add_parameter(QString("current_avg"), current_avg);
        }

        if(current_part->parameter_exists(QString("current_reverse")))
        {
            current_part->edit_parameter(QString("current_reverse"), current_reverse);
        }
        else
        {
            current_part->add_parameter(QString("current_reverse"), current_reverse);
        }

        if(current_part->parameter_exists(QString("voltage_forward")))
        {
            current_part->edit_parameter(QString("voltage_forward"), voltage_forward);
        }
        else
        {
            current_part->add_parameter(QString("voltage_forward"), voltage_forward);
        }

        if(current_part->parameter_exists(QString("voltage_rev")))
        {
            current_part->edit_parameter(QString("voltage_rev"), voltage_rev);
        }
        else
        {
            current_part->add_parameter(QString("voltage_rev"), voltage_rev);
        }

        if(current_part->parameter_exists(QString("voltage_zener")))
        {
            current_part->edit_parameter(QString("voltage_zener"), voltage_zener);
        }
        else
        {
            current_part->add_parameter(QString("voltage_zener"), voltage_zener);
        }

        if(current_part->parameter_exists(QString("tolerance")))
        {
            current_part->edit_parameter(QString("tolerance"), tolerance);
        }
        else
        {
            current_part->add_parameter(QString("tolerance"), tolerance);
        }

        if(current_part->parameter_exists(QString("power_max")))
        {
            current_part->edit_parameter(QString("power_max"), power_max);
        }
        else
        {
            current_part->add_parameter(QString("power_max"), power_max);
        }

        if(current_part->parameter_exists(QString("impedance_max")))
        {
            current_part->edit_parameter(QString("impedance_max"), impedance_max);
        }
        else
        {
            current_part->add_parameter(QString("impedance_max"), impedance_max);
        }

        if(current_part->parameter_exists(QString("capacitance")))
        {
            current_part->edit_parameter(QString("capacitance"), capacitance);
        }
        else
        {
            current_part->add_parameter(QString("capacitance"), capacitance);
        }

        if(current_part->parameter_exists(QString("reverse_recovery_time")))
        {
            current_part->edit_parameter(QString("reverse_recovery_time"), reverse_recovery_time);
        }
        else
        {
            current_part->add_parameter(QString("reverse_recovery_time"), reverse_recovery_time);
        }

    }

    emit(params_set(params));

}

void diode_dlg::push_param_to_map(QString key, QString value)
{
    params.insert(std::map<QString, QString>::value_type(key, value));
}

void diode_dlg::on_btn_OK_clicked()
{
    serialize_params();

    this->accept();
}

void diode_dlg::on_btn_cancel_clicked()
{
    this->reject();
}
