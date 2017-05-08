#include "connector_dlg.h"
#include "ui_connector_dlg.h"

connector_dlg::connector_dlg(QWidget *parent): ui(new Ui::connector_dlg)
{
    Q_UNUSED(parent)
    
    ui->setupUi(this);
}

connector_dlg::connector_dlg(const std::shared_ptr<library_part>& existing_part) : ui(new Ui::connector_dlg)
{
    this->current_part = existing_part;

    ui->setupUi(this);

    // Set text in all of the text boxes
    ui->box_contact_finish->setText(current_part->parameter_value("contact_finish"));
    ui->box_current->setText(current_part->parameter_value("current"));
    ui->box_num_pos->setText(current_part->parameter_value("number_of_positions"));
    ui->box_num_rows->setText(current_part->parameter_value("number_of_rows"));
    ui->box_voltage->setText(current_part->parameter_value("voltage"));
    ui->box_wire_gauge->setText(current_part->parameter_value("wire_gauge"));
}

connector_dlg::~connector_dlg()
{
    delete ui;
}

void connector_dlg::serialize_params()
{
    params.clear();

    if(current_part == nullptr)
    {
        push_param_to_map(QString("number_of_positions"), ui->box_num_pos->text() );
        push_param_to_map(QString("number_of_rows"), ui->box_num_rows->text());
        push_param_to_map(QString("contact_finish"), ui->box_contact_finish->text());
        push_param_to_map(QString("current"), ui->box_current->text());
        push_param_to_map(QString("voltage"), ui->box_voltage->text());
        push_param_to_map(QString("wire_gauge"), ui->box_wire_gauge->text());
    }
    else
    {
        QString num_pos = ui->box_num_pos->text();
        QString num_rows = ui->box_num_rows->text();
        QString contact_finish = ui->box_contact_finish->text();
        QString current = ui->box_current->text();
        QString voltage = ui->box_voltage->text();
        QString wire_gauge = ui->box_wire_gauge->text();

        if(current_part->parameter_exists(QString("number_of_positions")))
        {
            current_part->edit_parameter(QString("number_of_positions"), num_pos);
        }
        else
        {
            current_part->add_parameter(QString("number_of_positions"), num_pos);
        }
        if(current_part->parameter_exists(QString("number_of_rows")))
        {
            current_part->edit_parameter(QString("number_of_rows"), num_rows);
        }
        else
        {
            current_part->add_parameter(QString("number_of_rows"), num_rows);
        }
        if(current_part->parameter_exists(QString("contact_finish")))
        {
            current_part->edit_parameter(QString("contact_finish"), contact_finish);
        }
        else
        {
            current_part->add_parameter(QString("contact_finish"), contact_finish);
        }
        if(current_part->parameter_exists(QString("current")))
        {
            current_part->edit_parameter(QString("current"), current);
        }
        else
        {
            current_part->add_parameter(QString("current"), current);
        }
        if(current_part->parameter_exists(QString("voltage")))
        {
            current_part->edit_parameter(QString("voltage"), voltage);
        }
        else
        {
            current_part->add_parameter(QString("voltage"), voltage);
        }
        if(current_part->parameter_exists(QString("wire_gauge)")))
        {
            current_part->edit_parameter(QString("wire_gauge"), wire_gauge);
        }
        else
        {
            current_part->add_parameter(QString("wire_gauge"), wire_gauge);
        }

    }

    emit(params_set(params));
}

void connector_dlg::push_param_to_map(QString key, QString value)
{
    params.insert(std::map<QString, QString>::value_type(key, value));
}

void connector_dlg::on_btn_OK_clicked()
{
    serialize_params();

    this->accept();
}

void connector_dlg::on_btn_cancel_clicked()
{
    this->reject();
}
