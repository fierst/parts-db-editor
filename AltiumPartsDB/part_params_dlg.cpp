#include "part_params_dlg.h"
#include "ui_part_params_dlg.h"

part_params_dlg::part_params_dlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::part_params_dlg),
    current_part(new library_part)
{
    ui->setupUi(this);

    // Disable the footprint and symbol selectors until the user specifies a library
    ui->cmb_footprint->setEnabled(false);
    ui->cmb_symbol->setEnabled(false);

    // Don't allow the user to resize the dialog because it would mess up the layout
    //this->setWindowFlags(this->windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
}

part_params_dlg::part_params_dlg(library_part & existing_part) : ui(new Ui::part_params_dlg)
{
    this->current_part = std::make_shared<library_part>(existing_part);

    ui->setupUi(this);

    // Disable the part-type combobox because they shouldn't be able to change it for an existing part
    ui->cmb_part_type->setEnabled(false);

    ui->txt_description->setText(current_part->parameter_value("description"));

}

part_params_dlg::~part_params_dlg()
{
    delete ui;
}

void part_params_dlg::set_current_table(int tbl_index)
{
    ui->cmb_part_type->setCurrentIndex(tbl_index);
}

void part_params_dlg::assign_db(const std::shared_ptr<QSqlDatabase>& db_ptr)
{
    this->parts_db = db_ptr;
}

void part_params_dlg::set_paths(QString sch_path, QString pcb_path)
{
    this->schlib_path = sch_path;
    this->pcblib_path = pcb_path;

    this->update_combo_boxes();
}

void part_params_dlg::on_btn_part_properties_clicked()
{
    // TODO: Status indicator showing whether or not this has been done/validated yet

    int part_type = ui->cmb_part_type->currentIndex();

    switch(part_type)
    {
        case CAPACITOR:
        {
            capacitor_dlg capacitor_props(current_part);
            capacitor_props.setModal(true);
            capacitor_props.setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
            connect(&capacitor_props, &capacitor_dlg::params_set, this, &part_params_dlg::params_updated);
            capacitor_props.exec();
            break;
        }
        case CONNECTOR:
        {
            connector_dlg connector_props(current_part);
            connector_props.setModal(true);
            connector_props.setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
            connect(&connector_props, &connector_dlg::params_set, this, &part_params_dlg::params_updated);
            connector_props.exec();
            break;
        }
        case DIODE:
        {
            diode_dlg diode_props(current_part);
            diode_props.setModal(true);
            diode_props.setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
            connect(&diode_props, &diode_dlg::params_set, this, &part_params_dlg::params_updated);
            diode_props.exec();
            break;
        }
        case ELECTROMECHANICAL:
        {
            electromechanical_dlg electromechanical_props(current_part);
            electromechanical_props.setModal(true);
            electromechanical_props.setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
            connect(&electromechanical_props, &electromechanical_dlg::params_set, this, &part_params_dlg::params_updated);
            electromechanical_props.exec();
            break;
        }
        case FILTER:
        {
            filter_dlg filter_props(current_part);
            filter_props.setModal(true);
            filter_props.setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
            connect(&filter_props, &filter_dlg::params_set, this, &part_params_dlg::params_updated);
            filter_props.exec();
            break;
        }
        case FUSE:
        {
            fuse_dlg fuse_props(current_part);
            fuse_props.setModal(true);
            fuse_props.setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
            connect(&fuse_props, &fuse_dlg::params_set, this, &part_params_dlg::params_updated);
            fuse_props.exec();
            break;
        }
        case IC:
        {
            ic_dlg ic_props(current_part);
            ic_props.setModal(true);
            ic_props.setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
            connect(&ic_props, &ic_dlg::params_set, this, &part_params_dlg::params_updated);
            ic_props.exec();
            break;
        }
        case INDUCTOR:
        {
            inductor_dlg inductor_props(current_part);
            inductor_props.setModal(true);
            inductor_props.setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
            connect(&inductor_props, &inductor_dlg::params_set, this, &part_params_dlg::params_updated);
            inductor_props.exec();
            break;
        }
        case MECHANICAL:
        {
            mechanical_dlg mechanical_props(current_part);
            mechanical_props.setModal(true);
            mechanical_props.setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
            connect(&mechanical_props, &mechanical_dlg::params_set, this, &part_params_dlg::params_updated);
            mechanical_props.exec();
            break;
        }
        case OPTOELECTRONIC:
        {
            optoelectronic_dlg optoelectronic_props(current_part);
            optoelectronic_props.setModal(true);
            optoelectronic_props.setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
            connect(&optoelectronic_props, &optoelectronic_dlg::params_set, this, &part_params_dlg::params_updated);
            optoelectronic_props.exec();
            break;
        }
        case OSCILLATOR:
        {
            oscillator_dlg oscillator_props(current_part);
            oscillator_props.setModal(true);
            oscillator_props.setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
            connect(&oscillator_props, &oscillator_dlg::params_set, this, &part_params_dlg::params_updated);
            oscillator_props.exec();
            break;
        }
        case POWER:
        {
            power_dlg power_props(current_part);
            power_props.setModal(true);
            power_props.setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
            connect(&power_props, &power_dlg::params_set, this, &part_params_dlg::params_updated);
            power_props.exec();
            break;
        }
        case RESISTOR:
        {
            resistor_dlg resistor_props(current_part);
            resistor_props.setModal(true);
            resistor_props.setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
            connect(&resistor_props, &resistor_dlg::params_set, this, &part_params_dlg::params_updated);
            resistor_props.exec();
            break;
        }
        case TRANSFORMER:
        {
            transformer_dlg transformer_props(current_part);
            transformer_props.setModal(true);
            transformer_props.setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
            connect(&transformer_props, &transformer_dlg::params_set, this, &part_params_dlg::params_updated);
            transformer_props.exec();
            break;
        }
        case TRANSISTOR:
        {
            transistor_dlg transistor_props(current_part);
            transistor_props.setModal(true);
            transistor_props.setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
            connect(&transistor_props, &transistor_dlg::params_set, this, &part_params_dlg::params_updated);
            transistor_props.exec();
            break;
        }
        default:
            return;
    }
}

void part_params_dlg::update_combo_boxes()
{
    QDir schlib_location(this->schlib_path);
    QDir pcblib_location(this->pcblib_path);

    QStringList schlib_filter, pcblib_filter;

    schlib_filter << "*.SchLib";
    pcblib_filter << "*.PcbLib";

    schlibs = schlib_location.entryInfoList(schlib_filter);
    pcblibs = pcblib_location.entryInfoList(pcblib_filter);

    // Clear the combo boxes before adding anything;
    ui->cmb_symbol_lib->clear();
    ui->cmb_footprint_lib->clear();
    ui->cmb_part_type->clear();

    if(schlibs.length() != 0)
    {
        for(int i = 0; i < schlibs.length(); i++)
        {
            ui->cmb_symbol_lib->addItem(QString(schlibs.at(i).fileName()));
        }
    }

    if(pcblibs.length() != 0)
    {
        for(int i = 0; i < pcblibs.length(); i++)
        {
            ui->cmb_footprint_lib->addItem(QString(pcblibs.at(i).fileName()));
        }
    }

    ui->cmb_part_type->addItems(parts_db->tables());

    QString path_to_footprint_lib, path_to_symbol_lib;
    path_to_footprint_lib = current_part->parameter_value("footprint_path");
    path_to_symbol_lib = current_part->parameter_value("library_path");

    if(!path_to_footprint_lib.isEmpty())
    {
        QFileInfo fplib(path_to_footprint_lib);
        ui->cmb_footprint_lib->setCurrentIndex(ui->cmb_footprint_lib->findText(fplib.fileName()));
    }

    if(!path_to_symbol_lib.isEmpty())
    {
        QFileInfo symlib(path_to_symbol_lib);
        ui->cmb_symbol_lib->setCurrentIndex(ui->cmb_symbol_lib->findText(symlib.fileName()));
    }

    ui->cmb_footprint->setCurrentText(this->current_part->parameter_value("footprint_ref"));
    ui->cmb_symbol->setCurrentText(this->current_part->parameter_value("library_ref"));

}

void part_params_dlg::params_updated(const std::map<QString, QString>& new_params)
{
    if(current_part)
    {
        // Iterate through all parameter/value pairs and either modify existing params or make new ones
        for(auto const &param_vals : new_params)
        {
            if(current_part->parameter_exists(param_vals.first))
            {
                current_part->edit_parameter(param_vals.first, param_vals.second);
            }
            else
            {
                current_part->add_parameter(param_vals.first, param_vals.second);
            }
        }
    }
}

void part_params_dlg::on_cmb_symbol_lib_currentIndexChanged(int index)
{
    ui->cmb_symbol->clear();

    altium_lib schlib_file(schlibs.at(index).absoluteFilePath().toStdString());

    if(!schlib_file.load_from_file()) return;

    std::vector<std::string> sch_entities;

    if(schlib_file.get_library_entries(sch_entities))
    {
        for(size_t i = 0; i < sch_entities.size(); i++)
        {
            ui->cmb_symbol->insertItem(i, QString::fromStdString(sch_entities.at(i)));
        }

        ui->cmb_symbol->setEnabled(true);
    }
}

void part_params_dlg::on_cmb_footprint_lib_currentIndexChanged(int index)
{
    ui->cmb_footprint->clear();

    altium_lib pcblib_file(pcblibs.at(index).absoluteFilePath().toStdString());

    if(!pcblib_file.load_from_file()) return;

    std::vector<std::string> pcb_entities;

    if(pcblib_file.get_library_entries(pcb_entities))
    {
        for(size_t i = 0; i < pcb_entities.size(); i++)
        {
            ui->cmb_footprint->insertItem(i, QString::fromStdString(pcb_entities.at(i)));
        }
        ui->cmb_footprint->setEnabled(true);
    }
}

void part_params_dlg::on_btn_ok_clicked()
{

    QString footprint_path = QString("%1/%2").arg(pcblib_path, ui->cmb_footprint_lib->currentText());
    QString symbol_path = QString("%1/%2").arg(schlib_path, ui->cmb_symbol_lib->currentText());
    QString footprint = ui->cmb_footprint->currentText();
    QString symbol = ui->cmb_symbol->currentText();

    // Handle the odd case where there are no footprints or symbols in the specified libraries (or the libraries are gone)
    // This is checked in the database connection dialog, but lets handle it here to avoid any unpleasantness
    if(footprint_path.isEmpty() || symbol_path.isEmpty() || footprint.isEmpty() || symbol.isEmpty())
    {
        QString warning_msg("Error: new part requires values for: \n");
        if(footprint_path.isEmpty())    warning_msg.append("Footprint Path\n");
        if(footprint.isEmpty()) warning_msg.append("Footprint\n");
        if(symbol_path.isEmpty()) warning_msg.append("Symbol Path\n");
        if(symbol.isEmpty()) warning_msg.append("Symbol\n");
        warning_msg.append("\nCheck paths in Database Connection and try again");

        QMessageBox::warning(this, "Error", warning_msg, QMessageBox::Ok);

        this->reject();
    }

    if(current_part->parameter_exists("description"))
    {
        current_part->edit_parameter("description", ui->txt_description->toPlainText());
    }
    else
    {
        current_part->add_parameter("description", ui->txt_description->toPlainText());
    }

    if(current_part->parameter_exists("footprint_ref"))
    {
      current_part->edit_parameter("footprint_ref", footprint);
    }
    else
    {
      current_part->add_parameter("footprint_ref", footprint);
    }

    if(current_part->parameter_exists("footprint_path"))
    {
      current_part->edit_parameter("footprint_path", footprint_path);
    }
    else
    {
      current_part->add_parameter("footprint_path", footprint_path);
    }

    if(current_part->parameter_exists("library_ref"))
    {
      current_part->edit_parameter("library_ref", symbol);
    }
    else
    {
      current_part->add_parameter("library_ref", symbol);
    }

    if(current_part->parameter_exists("library_path"))
    {
      current_part->edit_parameter("library_path", symbol_path);
    }
    else
    {
      current_part->add_parameter("library_path", symbol_path);
    }

    emit(created_part(*current_part, ui->cmb_part_type->currentText()));

    this->accept();
}

void part_params_dlg::on_btn_cancel_clicked()
{
    this->reject();
}

void part_params_dlg::on_cmb_part_type_currentIndexChanged(int index)
{
    // TODO: This should probably do something?
    Q_UNUSED(index)
}
