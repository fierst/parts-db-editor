#include "fuse_dlg.h"
#include "ui_fuse_dlg.h"

fuse_dlg::fuse_dlg(QWidget *parent): ui(new Ui::fuse_dlg)
{
    Q_UNUSED(parent)
    
    ui->setupUi(this);
}

fuse_dlg::fuse_dlg(const std::shared_ptr<library_part> &existing_part): ui(new Ui::fuse_dlg)
{
    this->current_part = existing_part;

    ui->setupUi(this);

    ui->box_fuse_type->setText(current_part->parameter_value("fuse_type"));
    ui->box_current_rating->setText(current_part->parameter_value("current_rating"));
    ui->box_response_time->setText(current_part->parameter_value("response_time"));
    ui->box_voltage_ac->setText(current_part->parameter_value("voltage_rating_ac"));
    ui->box_voltage_dc->setText(current_part->parameter_value("voltage_rating_dc"));
    ui->box_breaking_capacity->setText(current_part->parameter_value("breaking_capacity"));
}

fuse_dlg::~fuse_dlg()
{
    delete ui;
}

void fuse_dlg::serialize_params()
{
    params.clear();

    if(current_part == nullptr)
    {
        push_param_to_map(QString("fuse_type"), ui->box_fuse_type->text());
        push_param_to_map(QString("current_rating"), ui->box_current_rating->text());
        push_param_to_map(QString("response_time"), ui->box_response_time->text());
        push_param_to_map(QString("voltage_rating_ac"), ui->box_voltage_ac->text());
        push_param_to_map(QString("voltage_rating_dc"), ui->box_voltage_dc->text());
        push_param_to_map(QString("breaking_capacity"), ui->box_breaking_capacity->text());
    }
    else
    {
        QString fuse_type = ui->box_fuse_type->text();
        QString current_rating = ui->box_current_rating->text();
        QString response_time = ui->box_response_time->text();
        QString voltage_rating_ac = ui->box_voltage_ac->text();
        QString voltage_rating_dc = ui->box_voltage_dc->text();
        QString breaking_capacity = ui->box_breaking_capacity->text();

        if(current_part->parameter_exists(QString("fuse_type")))
        {
            current_part->edit_parameter(QString("fuse_type"), fuse_type);
        }
        else
        {
            current_part->add_parameter(QString("fuse_type"), fuse_type);
        }

        if(current_part->parameter_exists(QString("current_rating")))
        {
            current_part->edit_parameter(QString("current_rating"), current_rating);
        }
        else
        {
            current_part->add_parameter(QString("current_rating"), current_rating);
        }

        if(current_part->parameter_exists(QString("response_time")))
        {
            current_part->edit_parameter(QString("response_time"), response_time);
        }
        else
        {
            current_part->add_parameter(QString("response_time"), response_time);
        }

        if(current_part->parameter_exists(QString("voltage_rating_ac")))
        {
            current_part->edit_parameter(QString("voltage_rating_ac"), voltage_rating_ac);
        }
        else
        {
            current_part->add_parameter(QString("voltage_rating_ac"), voltage_rating_ac);
        }

        if(current_part->parameter_exists(QString("voltage_rating_dc")))
        {
            current_part->edit_parameter(QString("voltage_rating_dc"), voltage_rating_dc);
        }
        else
        {
            current_part->add_parameter(QString("voltage_rating_dc"), voltage_rating_dc);
        }

        if(current_part->parameter_exists(QString("breaking_capacity")))
        {
            current_part->edit_parameter(QString("breaking_capacity"), breaking_capacity);
        }
        else
        {
            current_part->add_parameter(QString("breaking_capacity"), breaking_capacity);
        }


    }

    emit(params_set(params));
}

void fuse_dlg::push_param_to_map(QString key, QString value)
{
    params.insert(std::map<QString, QString>::value_type(key, value));
}

void fuse_dlg::on_btn_OK_clicked()
{
    serialize_params();

    this->accept();
}

void fuse_dlg::on_btn_cancel_clicked()
{
    this->reject();
}
