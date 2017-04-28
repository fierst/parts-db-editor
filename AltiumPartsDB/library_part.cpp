#include "library_part.h"

library_part::library_part()
{

}

library_part::library_part(const library_part &to_copy)
{
    this->part_parameters = to_copy.part_parameters;
}

library_part::library_part(const QSqlRecord &part_record)
{
    for(int i = 0; i < part_record.count(); i++)
    {
        this->add_parameter(part_record.fieldName(i), part_record.value(i).toString());
    }
}

void library_part::add_parameter(QString param, QString value)
{
    part_parameters.insert(std::map<QString, QString>::value_type(param, value));
}

void library_part::edit_parameter(QString param, QString value)
{
    std::map<QString, QString>::iterator it;
    it = part_parameters.find(param);
    if(it != part_parameters.end())
    {
        it->second = value;
    }
    else
    {
        // If the parameter doesn't exist, assume user wants it added
        add_parameter(param, value);
    }
}

bool library_part::parameter_exists(QString param)
{
    std::map<QString, QString>::iterator it;
    it = part_parameters.find(param);
    return (it != part_parameters.end());
}

void library_part::remove_parameter(QString param)
{
    std::map<QString, QString>::iterator it;
    it = part_parameters.find(param);
    if (it != part_parameters.end())
    {
        part_parameters.erase(it);
    }
}

QString library_part::parameter_value(QString param)
{
    if(parameter_exists(param))
    {
        return (part_parameters.find(param)->second);
    }
    else
    {
        return QString("");
    }
}

void library_part::append_params_to_map(const std::map<QString, QString> & params)
{
    part_parameters.insert(params.begin(), params.end());

    qDebug() << "test";
}

QList<QString> library_part::get_query_params(QString which_table)
{
    QList<QString> query_params;

    // Always write the base parameters (description and footprint/symbol ref & path)
    query_params.append(db_base_params);

    std::map<QString, QList<QString>>::const_iterator it;
    it = table_params_map.find(which_table);

    QString part_prop;

    // If the specified table has valid params, and it has a value, append them to the map of stuff to be added
    if(it != table_params_map.end())
    {

        for(int i = 0; i < it->second.count(); i++)
        {
            part_prop = it->second.at(i);

            if(!parameter_value(part_prop).isEmpty())
            {
                query_params.append(part_prop);
            }
        }
    }

    for(int j = 0; j < db_mfg_params.count(); j++)
    {
        if(!parameter_value(db_mfg_params.at(j)).isEmpty())
        {
            query_params.append(db_mfg_params.at(j));
        }
    }

    return query_params;
}

bool library_part::write_new_to_db(QString which_table, QSqlDatabase which_database)
{
    QList<QString> query_params = get_query_params(which_table);

    QString query_text;
    QTextStream insert_query_strm(&query_text);

    insert_query_strm << "INSERT INTO " << which_table << " (";
    for(int i = 0; i < query_params.count(); i++)
    {
        insert_query_strm << query_params.at(i);
        if(i != query_params.count() - 1)
        {
            insert_query_strm << ", ";
        }
        else
        {
            insert_query_strm << ")";
        }
    }

    insert_query_strm << " VALUES (";

    for(int j = 0; j < query_params.count(); j++)
    {
        insert_query_strm << ":" << query_params.at(j);
        if(j != query_params.count() - 1)
        {
            insert_query_strm << ", ";
        }
        else
        {
            insert_query_strm << ")";
        }
    }

    QSqlQuery insert_query(which_database);
    insert_query.prepare(query_text);

    for(int p = 0; p < query_params.count(); p++)
    {
        insert_query.bindValue(QString(":%1").arg(query_params.at(p)), parameter_value(query_params.at(p)));
    }

    insert_query.exec();
    // Build the query to write the part to the database
}

bool library_part::edit_existing_in_db(QString which_table, QSqlDatabase which_database)
{
    QList<QString> query_params = get_query_params(which_table);

    QString query_text;
    QTextStream update_query_strm(&query_text);

    update_query_strm << "UPDATE " << which_table << " SET ";

    for(int i = 0; i < query_params.count(); i++)
    {
        update_query_strm << query_params.at(i) << "=:" << query_params.at(i);

        if(i != query_params.count() - 1)
        {
            update_query_strm << ", ";
        }
    }

    update_query_strm << " WHERE part_number=:part_number";

    QSqlQuery update_query(which_database);
    update_query.prepare(query_text);

    for(int p = 0; p < query_params.count(); p++)
    {
        update_query.bindValue(QString(":%1").arg(query_params.at(p)), parameter_value(query_params.at(p)));
    }

    update_query.bindValue(":part_number", parameter_value("part_number"));

    update_query.exec();

}
