#include "capacitor_dlg.h"
#include "ui_capacitor_dlg.h"

capacitor_dlg::capacitor_dlg(QWidget *parent): ui(new Ui::capacitor_dlg)
{
    Q_UNUSED(parent)

    ui->setupUi(this);

    ui->cmb_units->addItems(units);
}

capacitor_dlg::capacitor_dlg(std::shared_ptr<library_part> existing_part) : ui(new Ui::capacitor_dlg)
{
    this->current_part = existing_part;

    ui->setupUi(this);

    // populate the UI elements from the part parameters
    parse_capacitance();
    ui->box_tempco->setText(current_part->parameter_value("temperature_coefficient"));
    ui->box_tolerance->setText(current_part->parameter_value("tolerance"));
    ui->box_voltage->setText(current_part->parameter_value("voltage"));
}

capacitor_dlg::~capacitor_dlg()
{
    delete ui;
}

void capacitor_dlg::on_btn_OK_clicked()
{
    serialize_params();

    this->accept();
}

void capacitor_dlg::on_btn_cancel_clicked()
{
    this->reject();
}

void capacitor_dlg::serialize_params()
{
    params.clear();

    // If there's no existing part, these are new parameters so emit the signal
    if(current_part == nullptr)
    {
        push_param_to_map(QString("capacitance"), QString("%1%2").arg(ui->box_capacitance->text(), ui->cmb_units->currentText()));
        push_param_to_map(QString("tolerance"), ui->box_tolerance->text());
        push_param_to_map(QString("temperature_coefficient"), ui->box_tempco->text());
        push_param_to_map(QString("voltage"), ui->box_voltage->text());
    }
    else
    {
        // If there is an existing part, modify (or add) these parameters to that existing part

        QString new_capacitance = QString("%1%2").arg(ui->box_capacitance->text(), ui->cmb_units->currentText());
        QString new_tempco = ui->box_tempco->text();
        QString new_tolerance = ui->box_tolerance->text();
        QString new_voltage = ui->box_voltage->text();

        if(current_part->parameter_exists(QString("capacitance")))
        {
            current_part->edit_parameter(QString("capacitance"), new_capacitance);
        }
        else
        {
            current_part->add_parameter(QString("capacitance"), new_capacitance);
        }
        \
        if(current_part->parameter_exists(QString("temperature_coefficient")))
        {
            current_part->edit_parameter(QString("temperature_coefficient"), new_tempco);
        }
        else
        {
            current_part->add_parameter(QString("temperature_coefficient"), new_tempco);
        }

        if(current_part->parameter_exists(QString("tolerance")))
        {
            current_part->edit_parameter(QString("tolerance"), new_tolerance);
        }
        else
        {
            current_part->add_parameter(QString("tolerance"), new_tolerance);
        }

        if(current_part->parameter_exists(QString("voltage")))
        {
            current_part->edit_parameter(QString("voltage"), new_voltage);
        }
        else
        {
            current_part->add_parameter(QString("voltage"), new_voltage);
        }
    }

    emit(params_set(params));
}

void capacitor_dlg::parse_capacitance()
{
    if(current_part != nullptr)
    {
        QString cap_str = current_part->parameter_value(QString("capacitance"));
        // Parse the units (2 characters) from the database value and set that as the current dropdown value
        ui->cmb_units->setCurrentIndex(ui->cmb_units->findText(cap_str.right(2)));
        // Put the rest of the string (sans units) in the capacitance text box
        cap_str.chop(2);
        ui->box_capacitance->setText(cap_str);
    }
}

void capacitor_dlg::push_param_to_map(QString key, QString value)
{
    params.insert(std::map<QString, QString>::value_type(key, value));
}
