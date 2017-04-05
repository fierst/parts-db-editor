#include "manufacturer_dlg.h"
#include "ui_manufacturer_dlg.h"

manufacturer_dlg::manufacturer_dlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::manufacturer_dlg)
{
    ui->setupUi(this);

    // Don't allow the user to resize the dialog because it would mess up the layout
    this->setWindowFlags(this->windowFlags() | Qt::MSWindowsFixedSizeDialogHint);

    // Handle initial values for tracked booleans
    this->notes_updated = false;
    this->initial_preferred_state = true;
    this->initial_active_state = true;
}

manufacturer_dlg::manufacturer_dlg(const manufacturer & current_mfg, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::manufacturer_dlg)
{
    this->mfg = current_mfg;

    ui->setupUi(this);

    this->setWindowFlags(this->windowFlags() | Qt::MSWindowsFixedSizeDialogHint);

    // TODO: This is probably unnecessary if a QString can be attached to a QLineEdit object...
    populate_ui_controls();

    // Handle initial values for tracked booleans
    this->notes_updated = false;
    this->initial_preferred_state = this->mfg.preferred;
    this->initial_active_state = (this->mfg.date_inactivated.isEmpty() ? true : false);
}


manufacturer_dlg::~manufacturer_dlg()
{
    delete ui;
}

void manufacturer_dlg::on_btn_ok_clicked()
{
    // Validate inputs
    if(validate_manufacturer())
    {
        // Construct the manufacturer object + emit changed
        construct_and_save_mfg();
        this->close();
    }
}

bool manufacturer_dlg::validate_manufacturer()
{
    QMessageBox::StandardButton user_override;

    // Check mfg and mfg_pn
    // The manufacturer can't (or shouldn't) be created without these fields
    if(ui->box_mfg->text().isEmpty() || ui->box_mfg_pn->text().isEmpty())
    {
        QMessageBox::critical(this, "Error", "Manufacturer and Manufacturer Part Number required", QMessageBox::Ok);
        return false;
    }

    // Check active check-box for new parts
    if(ui->cb_active->checkState() != Qt::CheckState::Checked && this->mfg.date_added.isEmpty())
    {
       user_override = QMessageBox::warning(this, "Warning", "New manufacturer not marked as active. Continue?", QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
       // If the user wants to create a new part that is automatically inactive, let them do it
       if(user_override != QMessageBox::Yes)
       {
           return false;
       }
    }

    // If the preferred or active check boxes change
    //  -- Check the notes
    bool current_preferred_state, current_active_state;

    current_preferred_state = ui->cb_preferred->isChecked();
    current_active_state = ui->cb_active->isChecked();

    if(current_preferred_state != initial_preferred_state && notes_updated == false)
    {
        user_override = QMessageBox::warning(this, "Warning", "Preferred status changed but notes not updated.\nAdding notes is strongly recommended. Continue?", QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

        if(user_override != QMessageBox::Yes)
        {
            return false;
        }
    }

    if(current_active_state != initial_active_state && notes_updated == false)
    {
        user_override = QMessageBox::warning(this, "Warning", "Active status changed but notes not updated.\nAdding notes is strongly recommended. Continue?", QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

        if(user_override != QMessageBox::Yes)
        {
            return false;
        }
    }

    // TODO: Automatically make inactive part non-preferred?

    return true;
}


void manufacturer_dlg::construct_and_save_mfg()
{
    QString current_date, current_user;

    current_date = QDate::currentDate().toString("yyyy-MM-dd");

    // TODO: Either make more portable or let the user enter their username in the connection dialog
    current_user = qgetenv("USERNAME");

    this->mfg.name = ui->box_mfg->text();
    this->mfg.part_number = ui->box_mfg_pn->text();
    this->mfg.preferred = (ui->cb_preferred->checkState() == Qt::CheckState::Checked ? true : false);

    // If the part is not marked active and the product was not previously inactivated, do that now
    if(this->mfg.date_inactivated.isEmpty() && this->ui->cb_active->checkState() != Qt::CheckState::Checked)
    {
        this->mfg.date_inactivated = current_date;
        this->mfg.inactivated_by = current_user;
    }

    // If the part is new, add the date and the user who added it
    if(this->mfg.date_added.isEmpty())
    {
        this->mfg.date_added = current_date;
        this->mfg.added_by = current_user;
    }

    this->mfg.datasheet_link = ui->box_datasheet_link->text();
    this->mfg.rohs_link = ui->box_rohs_link->text();
    this->mfg.ce_link = ui->box_ce_link->text();
    this->mfg.ul_link = ui->box_ul_link->text();

    this->mfg.notes = ui->box_notes->toPlainText();

    // Let the calling dialog know there's a new manufacturer
    emit new_manufacturer(this->mfg);
}

void manufacturer_dlg::populate_ui_controls()
{
    ui->box_mfg->setText(this->mfg.name);
    ui->box_mfg_pn->setText(this->mfg.part_number);
    ui->box_notes->setText(this->mfg.notes);
    ui->box_datasheet_link->setText(this->mfg.datasheet_link);
    ui->box_rohs_link->setText(this->mfg.rohs_link);
    ui->box_ce_link->setText(this->mfg.ce_link);
    ui->box_ul_link->setText(this->mfg.ul_link);
    ui->cb_preferred->setChecked(this->mfg.preferred);
    // If the date inactivated field is empty, then the part is assumed active
    ui->cb_active->setChecked(this->mfg.date_inactivated.isEmpty());
}

void manufacturer_dlg::on_box_notes_textChanged()
{
    this->notes_updated = true;
}
