#include "inductor_dlg.h"
#include "ui_inductor_dlg.h"

inductor_dlg::inductor_dlg(QWidget *parent): ui(new Ui::inductor_dlg)
{
    Q_UNUSED(parent)
    
    ui->setupUi(this);
}

inductor_dlg::inductor_dlg(const std::shared_ptr<library_part> &existing_part) : ui(new Ui::inductor_dlg)
{
    this->current_part = existing_part;

    ui->setupUi(this);

    ui->box_inductance->setText(current_part->parameter_value("inductance"));
    ui->box_tolerance->setText(current_part->parameter_value("tolerance"));
    ui->box_core_material->setText(current_part->parameter_value("core_material"));
    ui->box_current_rating->setText(current_part->parameter_value("current_rating"));
    ui->box_resistance->setText(current_part->parameter_value("resistance"));
    ui->box_operating_temperature->setText(current_part->parameter_value("operating_temperature"));
}

inductor_dlg::~inductor_dlg()
{
    delete ui;
}

void inductor_dlg::serialize_params()
{
    params.clear();

    if(current_part == nullptr)
    {
        push_param_to_map(QString("inductance"), ui->box_inductance->text());
        push_param_to_map(QString("tolerance"), ui->box_tolerance->text());
        push_param_to_map(QString("core_material"), ui->box_core_material->text());
        push_param_to_map(QString("current_rating"), ui->box_current_rating->text());
        push_param_to_map(QString("resistance"), ui->box_resistance->text());
        push_param_to_map(QString("operating_temperature"), ui->box_operating_temperature->text());
    }
    else
    {
        QString inductance = ui->box_inductance->text();
        QString tolerance = ui->box_tolerance->text();
        QString core_material = ui->box_core_material->text();
        QString current_rating = ui->box_current_rating->text();
        QString resistance = ui->box_resistance->text();
        QString operating_temperature = ui->box_operating_temperature->text();

        if(current_part->parameter_exists(QString("inductance")))
        {
            current_part->edit_parameter(QString("inductance"), inductance);
        }
        if(current_part->parameter_exists(QString("tolerance")))
        {
            current_part->edit_parameter(QString("tolerance"), tolerance);
        }
        if(current_part->parameter_exists(QString("core_material")))
        {
            current_part->edit_parameter(QString("core_material"), core_material);
        }
        if(current_part->parameter_exists(QString("current_rating")))
        {
            current_part->edit_parameter(QString("current_rating"), current_rating);
        }
        if(current_part->parameter_exists(QString("resistance")))
        {
            current_part->edit_parameter(QString("resistance"), resistance);
        }
        if(current_part->parameter_exists(QString("operating_temperature")))
        {
            current_part->edit_parameter(QString("operating_temperature"), operating_temperature);
        }
    }

    emit(params_set(params));
}

void inductor_dlg::push_param_to_map(QString key, QString value)
{
    params.insert(std::map<QString, QString>::value_type(key, value));
}

void inductor_dlg::on_btn_OK_clicked()
{
    serialize_params();

    this->accept();
}

void inductor_dlg::on_btn_cancel_clicked()
{
    this->reject();
}
