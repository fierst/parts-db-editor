#include "mfg_list_model.h"

#include <QDebug>

mfg_list_model::mfg_list_model(QObject *parent)
{

}

void mfg_list_model::add_manufacturer(const manufacturer &mfg_to_add)
{
    int current_row = this->rowCount();

    // Insert a new row
    this->insertRows(current_row, 1);

    // Set all the data fields
    QModelIndex index = this->index(current_row, MfgListColumns::MFG_NAME);
    this->setData(index, mfg_to_add.name);
    index = this->index(current_row, MfgListColumns::MFG_PN);
    this->setData(index, mfg_to_add.part_number);
    index = this->index(current_row, MfgListColumns::MFG_PREFERRED);
    this->setData(index, mfg_to_add.preferred);
    index = this->index(current_row, MfgListColumns::MFG_STATUS);
    this->setData(index, mfg_to_add.date_inactivated.isEmpty());
    index = this->index(current_row, MfgListColumns::MFG_NOTES);
    this->setData(index, mfg_to_add.notes);
    index = this->index(current_row, MfgListColumns::MFG_DATE_ADDED);
    this->setData(index, mfg_to_add.date_added);
    index = this->index(current_row, MfgListColumns::MFG_ADDED_BY);
    this->setData(index, mfg_to_add.added_by);
    index = this->index(current_row, MfgListColumns::MFG_DATE_INACTIVATED);
    this->setData(index, mfg_to_add.date_inactivated);
    index = this->index(current_row, MfgListColumns::MFG_INACTIVATED_BY);
    this->setData(index, mfg_to_add.inactivated_by);
    index = this->index(current_row, MfgListColumns::MFG_DATASHEET_LINK);
    this->setData(index, mfg_to_add.datasheet_link);
    index = this->index(current_row, MfgListColumns::MFG_ROHS_LINK);
    this->setData(index, mfg_to_add.rohs_link);
    index = this->index(current_row, MfgListColumns::MFG_CE_LINK);
    this->setData(index, mfg_to_add.ce_link);
    index = this->index(current_row, MfgListColumns::MFG_UL_LINK);
    this->setData(index, mfg_to_add.ul_link);

}

int mfg_list_model::available_mfg_slots()
{
    return (MAXIMUM_MFGS - mfg_list.size());
}

manufacturer mfg_list_model::get_mfg_at_index(int index)
{
    return mfg_list.at(index);
}

void mfg_list_model::edit_manufacturer(const manufacturer & mfg_to_edit)
{
    mfg_list.replace(mfg_to_edit.mfg_index, mfg_to_edit);
}

bool mfg_list_model::remove_manufacturer(int at_what_index)
{
    // Check bounds
    if(at_what_index < 0 || at_what_index >= this->rowCount())
        return false;

    return this->removeRows(at_what_index, 1);
}

int mfg_list_model::rowCount(const QModelIndex &index) const
{
    Q_UNUSED(index);

    // Number of rows should equal the number of manufacturers in the map
    return this->mfg_list.size();
}

int mfg_list_model::columnCount(const QModelIndex &index) const
{
    Q_UNUSED(index);

    return MfgListColumns::NUMBER_OF_COLUMNS;
}

QVariant mfg_list_model::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
    {
        return QVariant();
    }

    if (role == Qt::DisplayRole)
    {
        if(index.column() == MFG_NAME)
        {
            return mfg_list.at(index.row()).name;
        }
        else if(index.column() == MFG_PN)
        {
            return mfg_list.at(index.row()).part_number;
        }
        else if(index.column() == MFG_DATE_ADDED)
        {
            return mfg_list.at(index.row()).date_added;
        }
        else if(index.column() == MFG_ADDED_BY)
        {
            return mfg_list.at(index.row()).added_by;
        }
        else if(index.column() == MFG_DATE_INACTIVATED)
        {
            return mfg_list.at(index.row()).date_inactivated;
        }
        else if(index.column() == MFG_INACTIVATED_BY)
        {
            return mfg_list.at(index.row()).inactivated_by;
        }
        else if(index.column() == MFG_NOTES)
        {
            return mfg_list.at(index.row()).notes;
        }
        else if(index.column() == MFG_DATASHEET_LINK)
        {
            return mfg_list.at(index.row()).datasheet_link;
        }
        else if(index.column() == MFG_ROHS_LINK)
        {
            return mfg_list.at(index.row()).rohs_link;
        }
        else if(index.column() == MFG_CE_LINK)
        {
            return mfg_list.at(index.row()).ce_link;
        }
        else if(index.column() == MFG_UL_LINK)
        {
            return mfg_list.at(index.row()).ul_link;
        }
    }
    else if (role == Qt::CheckStateRole)    // Show the preferred state and active status as a checkbox
    {
        if(index.column() == MfgListColumns::MFG_PREFERRED)
        {
            return (mfg_list.at(index.row()).preferred ? Qt::Checked : Qt::Unchecked);
        }
        else if(index.column() == MfgListColumns::MFG_STATUS)
        {
            return (mfg_list.at(index.row()).date_inactivated.isEmpty() ? Qt::Checked : Qt::Unchecked);
        }
        else
        {
            return QVariant();
        }
    }

    return QVariant();
}

QVariant mfg_list_model::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole)
        return QVariant();

    if(orientation == Qt::Vertical)
    {
        return tr("      "); // For now, just give a blank box to drag around. Figure out indexing eventually...
    }

    if(orientation == Qt::Horizontal)
    {
        switch(section)
        {
            case (int)MfgListColumns::MFG_NAME:
                return tr("Manufacturer");
            case (int)MfgListColumns::MFG_PN:
                return tr("Manufacturer PN");
            case (int)MfgListColumns::MFG_PREFERRED:
                return tr("Preferred");
            case (int)MfgListColumns::MFG_STATUS:
                return tr("Status");
            case (int)MfgListColumns::MFG_DATE_ADDED:
                return tr("Date Added");
            case (int)MfgListColumns::MFG_ADDED_BY:
                return tr("Added by");
            case (int)MfgListColumns::MFG_DATE_INACTIVATED:
                return tr("Date Inactivated");
            case (int)MfgListColumns::MFG_INACTIVATED_BY:
                return tr("Inactivated by");
            case (int)MfgListColumns::MFG_NOTES:
                return tr("Notes");
            case (int)MfgListColumns::MFG_DATASHEET_LINK:
                return tr("Datasheet Link");
            case (int)MfgListColumns::MFG_ROHS_LINK:
                return tr("RoHS Conformance Link");
            case (int)MfgListColumns::MFG_CE_LINK:
                return tr("CE Conformance Link");
            case (int)MfgListColumns::MFG_UL_LINK:
                return tr("UL Conformance Link");
            default:
                return QVariant();
        }
    }

    return QVariant();
}

Qt::ItemFlags mfg_list_model::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    Qt::ItemFlags column_flags = QAbstractTableModel::flags(index);

    column_flags |= Qt::ItemIsSelectable;

    return column_flags;

}

bool mfg_list_model::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!index.isValid())
    {
        return false;
    }

    manufacturer mfg = this->mfg_list.value(index.row());

    if(role == Qt::EditRole)
    {
        if(index.column() == MFG_NAME)
        {
            mfg.name = value.toString();
        }
        else if(index.column() == MFG_PN)
        {
            mfg.part_number = value.toString();
        }
        else if(index.column() == MFG_DATE_ADDED)
        {
            mfg.date_added = value.toString();
        }
        else if(index.column() == MFG_ADDED_BY)
        {
            mfg.added_by = value.toString();
        }
        else if(index.column() == MFG_DATE_INACTIVATED)
        {
            mfg.date_inactivated = value.toString();
        }
        else if(index.column() == MFG_INACTIVATED_BY)
        {
            mfg.inactivated_by = value.toString();
        }
        else if(index.column() == MFG_NOTES)
        {
            mfg.notes = value.toString();
        }
        else if(index.column() == MFG_DATASHEET_LINK)
        {
            mfg.datasheet_link = value.toString();
        }
        else if(index.column() == MFG_ROHS_LINK)
        {
            mfg.rohs_link = value.toString();
        }
        else if(index.column() == MFG_CE_LINK)
        {
            mfg.ce_link = value.toString();
        }
        else if(index.column() == MFG_UL_LINK)
        {
            mfg.ul_link = value.toString();
        }

        mfg_list.replace(index.row(), mfg);
        emit(dataChanged(index, index));
        return true;
    }

    if(role == Qt::CheckStateRole)
    {
        bool check_val = (((Qt::CheckState)value.toInt() == Qt::Checked) ? true : false);

        if(index.column() == MFG_PREFERRED)
        {
            mfg.preferred = check_val;
        }
        else
        {
            return false;
        }
        mfg_list.replace(index.row(), mfg);
        emit(dataChanged(index, index));
        return true;
    }

    return false;
}

bool mfg_list_model::insertRows(int row, int count, const QModelIndex &index)
{
    Q_UNUSED(index);

    beginInsertRows(QModelIndex(), row, row + count - 1);

    for(int i = 0; i < count; i++)
    {
        manufacturer new_mfg;
        this->mfg_list.insert(row, new_mfg);
    }

    endInsertRows();

    return true;
}

bool mfg_list_model::removeRows(int row, int count, const QModelIndex &index)
{
    Q_UNUSED(index);

    beginRemoveRows(QModelIndex(), row, row + count - 1);

    for(int i = 0; i < count; i++)
    {
        this->mfg_list.removeAt(row);
    }

    endRemoveRows();

    return true;
}

manufacturer::manufacturer()
{
    // Empty constructor, these values are largely invalid
    this->mfg_index = -1;
    this->name = "";
    this->part_number = "";
    this->preferred = true;
    this->date_added = "";
    this->date_inactivated = "";
    this->added_by = "";
    this->inactivated_by = "";
    this->datasheet_link = "";
    this->rohs_link = "";
    this->ce_link = "" ;
    this->ul_link = "";
    this->notes = "";
}

manufacturer::manufacturer(const manufacturer & to_copy)
{
    // Default copy constructor, just copy everything over
    this->mfg_index = to_copy.mfg_index;
    this->name = to_copy.name;
    this->part_number = to_copy.part_number;
    this->preferred = to_copy.preferred;
    this->date_added = to_copy.date_added;
    this->date_inactivated = to_copy.date_inactivated;
    this->added_by = to_copy.added_by;
    this->inactivated_by = to_copy.inactivated_by;
    this->datasheet_link = to_copy.datasheet_link;
    this->rohs_link = to_copy.rohs_link;
    this->ce_link = to_copy.ce_link;
    this->ul_link = to_copy.ul_link;
    this->notes = to_copy.notes;
}
