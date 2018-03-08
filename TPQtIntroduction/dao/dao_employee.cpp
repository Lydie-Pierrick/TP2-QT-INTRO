#include "dao_employee.h"

DAO_Employee::DAO_Employee()
{

}

bool DAO_Employee::addEmployee(QString firstname, QString lastname, int idType)
{
    QSqlQuery sqlQuery(db);
    sqlQuery.prepare("INSERT INTO TRessource (Nom, Prenom, IdType) VALUES (?, ?, ?)");
    sqlQuery.addBindValue(lastname);
    sqlQuery.addBindValue(firstname);
    sqlQuery.addBindValue(idType);

    if(!sqlQuery.exec())
    {
        qDebug() << sqlQuery.lastError();

        return false;
    }
    else
    {
        if(convertIntToType(idType) == "Computer Scientist")
        {
            QSqlQuery sqlQuery2(db);
            sqlQuery2.prepare("INSERT INTO TCompte (IdRessource, Login, MdP) VALUES (last_insert_rowid(), '" + firstname + "', 'Password')");
        }

        return true;
    }
}

vector<map<QString, QString>> DAO_Employee::getAllEmployees()
{
    map<QString, QString> m_record;
    vector<map<QString, QString>> v_records;
    QSqlQuery sqlQuery(db);
    sqlQuery.prepare("SELECT * FROM TRessource");
    if(!sqlQuery.exec())
    {
        qDebug() << sqlQuery.lastError();
    }
    else
    {
        while(sqlQuery.next())
        {
            m_record.insert(pair<QString,QString>("id", sqlQuery.value(0).toString()));
            m_record.insert(pair<QString,QString>("lastname", sqlQuery.value(1).toString()));
            m_record.insert(pair<QString,QString>("firstname", sqlQuery.value(2).toString()));
            m_record.insert(pair<QString,QString>("type", convertIntToType(sqlQuery.value(3).toInt())));

            v_records.push_back(m_record);
            m_record.clear();
        }
    }

    return v_records;
}

map<QString, QString> DAO_Employee::searchEmployee(int id)
{
    map<QString, QString> m_record;
    QSqlQuery sqlQuery(db);
    sqlQuery.prepare("SELECT * FROM TRessource WHERE Id = ?");
    sqlQuery.addBindValue(id);

    if(!sqlQuery.exec())
    {
       qDebug() << sqlQuery.lastError();
    }
    else {
       sqlQuery.next();
       m_record.insert(pair<QString,QString>("id", sqlQuery.value(0).toString()));
       m_record.insert(pair<QString,QString>("lastname", sqlQuery.value(1).toString()));
       m_record.insert(pair<QString,QString>("firstname", sqlQuery.value(2).toString()));
       m_record.insert(pair<QString,QString>("type", convertIntToType(sqlQuery.value(3).toInt())));
    }

    return m_record;
}

bool DAO_Employee::modifyEmployee(int id, QString lastname, QString firstname, int idType)
{
    QSqlQuery sqlQuery(db);
    sqlQuery.prepare("UPDATE TRessource SET Nom = ?, Prenom = ?, IdType = ? WHERE Id = ? ");
    sqlQuery.addBindValue(lastname);
    sqlQuery.addBindValue(firstname);
    sqlQuery.addBindValue(idType);
    sqlQuery.addBindValue(id);

    if(!sqlQuery.exec())
    {
        qDebug() << sqlQuery.lastError();

        return false;
    }
    else{
        return true;
    }
}

bool DAO_Employee::deleteEmployee(int id)
{
    QSqlQuery sqlQuery(db);
    sqlQuery.prepare("DELETE FROM TRessource WHERE Id = ? ");
    sqlQuery.addBindValue(id);

    if(!sqlQuery.exec())
    {
        qDebug() << sqlQuery.lastError();
        return false;
    }
    else{
        return true;
    }
}

QString DAO_Employee::convertIntToType(int idType)
{
    // Get type of employee by label
    QSqlQuery sqlQuery(db);
    QString type;

    sqlQuery.prepare("SELECT Label FROM TType WHERE Id = ?");
    sqlQuery.addBindValue(idType);

    if(!sqlQuery.exec())
    {
        qDebug() << sqlQuery.lastError();
    }
    else{
        sqlQuery.next();
        type = sqlQuery.value(0).toString();
    }

    return type;
}

vector<QString> DAO_Employee::getAllTypes()
{
    // faire
}

bool DAO_Employee::checkLogin(QString username, QString password)
{
    QSqlQuery sqlQuery(db);
    QString idRessource;
    QString idType;

    // To get employee if username and password matched
    sqlQuery.prepare("SELECT IdRessource FROM TCompte WHERE Login = ? AND MdP = ?");
    sqlQuery.addBindValue(username);
    sqlQuery.addBindValue(password);

    if(!sqlQuery.exec())
    {
        qDebug() << sqlQuery.lastError();
    }
    else{
        // If employee username and password matched
        if(sqlQuery.next())
        {
            QSqlQuery sqlQuery2(db);
            idRessource = sqlQuery.value(0).toString();

            // Get id type of the employee
            sqlQuery2.prepare("SELECT IdType FROM TRessource WHERE Id = ?");
            sqlQuery2.addBindValue(idRessource);

            if(!sqlQuery2.exec())
            {
                qDebug() << sqlQuery2.lastError();
            }
            else{
                // If the employee had id type exist
                if(sqlQuery2.next())
                    idType = sqlQuery2.value(0).toString();
                else
                    return false;

                // Check if the type of employee for authentification is only IT
                if(!(convertIntToType(idType.toInt()) == "Computer Scientist"))
                    return false;
            }

            return true;
        }

    }

    return false;
}
