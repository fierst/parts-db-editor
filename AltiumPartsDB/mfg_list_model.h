#ifndef MFG_LIST_MODEL_H
#define MFG_LIST_MODEL_H

#include <QAbstractTableModel>  // For QAbstractTableModel Inheritance
#include <QHeaderView>          // For attaching the header
#include <QList>                // For list of manufacturers

#include <map>                  // For the parameter map

#include "library_part.h"

#define MAXIMUM_MFGS 15         // Maximum number of manufacturers (15 total)

const int8_t uninitialized_mfg_index = -1;

enum MfgListColumns
{
    MFG_NAME = 0,
    MFG_PN,
    MFG_PREFERRED,
    MFG_STATUS,
    MFG_NOTES,
    MFG_DATE_ADDED,
    MFG_ADDED_BY,
    MFG_DATE_INACTIVATED,
    MFG_INACTIVATED_BY,
    MFG_DATASHEET_LINK,
    MFG_ROHS_STATUS,
    MFG_ROHS_LINK,
    MFG_CE_LINK,
    MFG_UL_LINK,
    NUMBER_OF_COLUMNS
};


class manufacturer
{\
public:
    manufacturer();

    manufacturer(const manufacturer &);

    // TODO: should these be private and follow a get/set pattern via. public interface?
    // It may be better practice, but that's a lot of methods to write to the same end
    // and I can't really justify it right now.
    int8_t mfg_index;           // 0 through 14 (15 total)
    QString name;               // the name of the manufacturer
    QString part_number;        // the part number
    bool preferred;             // whether or not the part is preferred
    QString date_added;         // when the part was created
    QString date_inactivated;   // when the part was inactivated
    QString added_by;           // who added the part
    QString inactivated_by;     // who inactivated the part
    QString datasheet_link;     // link to the datasheet
    QString rohs_status;        // Whether or not the part is RoHS compliant (Yes, No, Unknown, and Missing)
    QString rohs_link;          // link to the RoHS compliance info
    QString ce_link;            // link to the CE conformance info
    QString ul_link;            // link to the UL conformance info
    QString notes;              // notes

};

// Necessary to use manufacturer as a QVariant type in data models
Q_DECLARE_METATYPE(manufacturer*)

class mfg_list_model : public QAbstractTableModel
{
    Q_OBJECT

public:

    // Default constructor, doesn't really do much...
    mfg_list_model(QObject *parent = 0);

    // Constructor for existing parts
    mfg_list_model(library_part &existing_part);

    // Basic methods to maintain the manufacturers list
    void add_manufacturer(const manufacturer & mfg_to_add);
    bool remove_manufacturer(int at_what_index);
    void edit_manufacturer(const manufacturer &mfg_to_edit);

    manufacturer get_mfg_at_index(int index);

    // Get the manufacturers map (of parameters) and return the number of manufacturers serialized
    int get_mfg_map(std::map<QString, QString> &);

    int available_mfg_slots();

protected:
    // Overridden methods for the model view container
    int rowCount(const QModelIndex &index  = QModelIndex()) const;
    int columnCount(const QModelIndex &index  = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    bool insertRows(int row, int count, const QModelIndex &index = QModelIndex());
    bool removeRows(int row, int count, const QModelIndex &index = QModelIndex());

private:

    // Vector of manufacturers to populate the model
    QList<manufacturer> mfg_list;

    void serialize_manufacturer(const manufacturer &to_serialize);

    // Maintain this because it's going to be passed to the parent window
    std::map<QString, QString> mfg_map;

    void push_param_to_map(QString key, QString value);
};

#endif // MFG_LIST_MODEL_H
