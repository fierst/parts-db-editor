#include "optoelectronic_dlg.h"
#include "ui_optoelectronic_dlg.h"

optoelectronic_dlg::optoelectronic_dlg(QWidget *parent): ui(new Ui::optoelectronic_dlg)
{
    Q_UNUSED(parent)
    
    ui->setupUi(this);
}

optoelectronic_dlg::optoelectronic_dlg(const std::shared_ptr<library_part> &existing_part) : ui(new Ui::optoelectronic_dlg)
{
    this->current_part = existing_part;

    ui->setupUi(this);

    ui->box_color->setText(current_part->parameter_value("color"));
    ui->box_wavelength->setText(current_part->parameter_value("wavelength"));
    ui->box_power_dissipation->setText(current_part->parameter_value("power_dissipation"));
    ui->box_voltage_fwd->setText(current_part->parameter_value("voltage_forward"));
    ui->box_current_rating->setText(current_part->parameter_value("current_rating"));
    ui->box_millicandela_rating->setText(current_part->parameter_value("millicandela_rating"));
}

optoelectronic_dlg::~optoelectronic_dlg()
{
    delete ui;
}

void optoelectronic_dlg::serialize_params()
{
    params.clear();

    if(current_part == nullptr)
    {
        push_param_to_map(QString("color"), ui->box_color->text());
        push_param_to_map(QString("wavelength"), ui->box_wavelength->text());
        push_param_to_map(QString("power_dissipation"), ui->box_power_dissipation->text());
        push_param_to_map(QString("voltage_forward"), ui->box_voltage_fwd->text());
        push_param_to_map(QString("current_rating"), ui->box_current_rating->text());
        push_param_to_map(QString("millicandela_rating"), ui->box_millicandela_rating->text());
    }
    else
    {
        QString color = ui->box_color->text();
        QString wavelength = ui->box_wavelength->text();
        QString power_dissipation = ui->box_power_dissipation->text();
        QString voltage_forward = ui->box_voltage_fwd->text();
        QString current_rating = ui->box_current_rating->text();
        QString millicandela_rating = ui->box_millicandela_rating->text();

        if(current_part->parameter_exists(QString("color")))
        {
            current_part->edit_parameter(QString("color"), color);
        }
        else
        {
            current_part->add_parameter(QString("color"), color);
        }

        if(current_part->parameter_exists(QString("wavelength")))
        {
            current_part->edit_parameter(QString("wavelength"), wavelength);
        }
        else
        {
            current_part->add_parameter(QString("wavelength"), wavelength);
        }

        if(current_part->parameter_exists(QString("power_dissipation")))
        {
            current_part->edit_parameter(QString("power_dissipation"), power_dissipation);
        }
        else
        {
            current_part->add_parameter(QString("power_dissipation"), power_dissipation);
        }

        if(current_part->parameter_exists(QString("voltage_forward")))
        {
            current_part->edit_parameter(QString("voltage_forward"), voltage_forward);
        }
        else
        {
            current_part->add_parameter(QString("voltage_forward"), voltage_forward);
        }

        if(current_part->parameter_exists(QString("current_rating")))
        {
            current_part->edit_parameter(QString("current_rating"), current_rating);
        }
        else
        {
            current_part->add_parameter(QString("current_rating"), current_rating);
        }

        if(current_part->parameter_exists(QString("millicandela_rating")))
        {
            current_part->edit_parameter(QString("millicandela_rating"), millicandela_rating);
        }
        else
        {
            current_part->add_parameter(QString("millicandela_rating"), millicandela_rating);
        }

    }

    emit(params_set(params));
}

void optoelectronic_dlg::push_param_to_map(QString key, QString value)
{
    params.insert(std::map<QString, QString>::value_type(key, value));
}

void optoelectronic_dlg::on_btn_OK_clicked()
{
    serialize_params();

    this->accept();
}

void optoelectronic_dlg::on_btn_cancel_clicked()
{
    this->reject();
}
