#ifndef LIBRARY_PART_H
#define LIBRARY_PART_H

#include <QDate>
#include <QString>
#include <QTextStream>
#include <QtSql>
#include <map>

enum part_types {
    CAPACITOR = 0,
    CONNECTOR,
    DIODE,
    ELECTROMECHANICAL,
    FILTER,
    FUSE,
    IC,
    INDUCTOR,
    MECHANICAL,
    OPTOELECTRONIC,
    OSCILLATOR,
    POWER,
    RESISTOR,
    TRANSFORMER,
    TRANSISTOR
};

class library_part
{

public:

    // Constructor, for new parts
    library_part();

    // Copy constructor, for editing existing parts
    library_part(const library_part &);

    // Constructor for parts created from an SQL query
    library_part(const QSqlRecord &part_record);

    // Add a new parameter to the part_parameters map with key=param and value=value
    void add_parameter(QString param, QString value);

    // Edit an existing parameter in the part_parameters map
    // If it doesn't exist, then add it
    void edit_parameter(QString param, QString value);

    // Check whether the parameter indicated by param exists in the part_parameters map
    bool parameter_exists(QString param);

    // Remove a parameter from the map if it exists
    void remove_parameter(QString param);

    // Return the value of the parameter indicated by param in the part_parameters map
    // If the parameter doesn't exist, return a blank string
    QString parameter_value(QString param);

    // Append new/existing params to the part_parameters map
    void append_params_to_map(const std::map<QString, QString> &params);

    // Perform SQL query to insert the current part into the database
    bool write_new_to_db(QString which_table, QSqlDatabase which_database);

    // Perform SQL query to edit the part (specified by part number) in the database
    bool edit_existing_in_db(QString which_table, QSqlDatabase which_database);

private:

    // Holds the parameters to be inserted into the parts database
    // Key is the name of the parameters
    // Value is the value to store in the parameters
    std::map<QString, QString> part_parameters;

    // Get a list of the relevant query params (where a value actually exists)
    QStringList get_query_params(QString which_table, QSqlDatabase which_database);

};

#endif // LIBRARY_PART_H
