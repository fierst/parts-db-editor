#ifndef LIBRARY_PART_H
#define LIBRARY_PART_H

#include <QString>

#include <map>

class library_part
{

public:

    // Constructor, for new parts
    library_part();

    // Copy constructor, for editing existing parts
    library_part(const library_part &);

    // Add a new parameter to the part_parameters map with key=param and value=value
    void add_parameter(QString param, QString value);

    // Edit an existing parameter in the part_parameters map
    // For now, it fails silently if the parameter doesn't exist
    // TODO: should it not do that?
    void edit_parameter(QString param, QString value);

    // Check whether the parameter indicated by param exists in the part_parameters map
    bool parameter_exists(QString param);

    // Return the value of the parameter indicated by param in the part_parameters map
    QString parameter_value(QString param);

private:

    // Holds the parameters to be inserted into the parts database
    // Key is the name of the parameters
    // Value is the value to store in the parameters
    std::map<QString, QString> part_parameters;

};

#endif // LIBRARY_PART_H
