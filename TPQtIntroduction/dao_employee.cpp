#include "dao_employee.h"

DAO_Employee::DAO_Employee()
{

}

bool DAO_Employee::addEmployee(QString firstname, QString lastname, int idType)
{
    QSqlQuery sqlQuery;
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
        return true;
    }
}

vector<map<QString, QString>> DAO_Employee::getAllEmployees()
{
    //vector<vector<QString>> v_records;
    map<QString, QString> m_record;
    vector<map<QString, QString>> v_records;
    QSqlQuery sqlQuery;
    sqlQuery.prepare("SELECT * FROM TRessource");
    if(!sqlQuery.exec())
    {
        qDebug() << sqlQuery.lastError();
    }
    else
    {
        while(sqlQuery.next())
        {
//            vector<QString> v_record; // record a line
//            QString id = sqlQuery.value(0).toString();
//            QString lastName = sqlQuery.value(1).toString();
//            QString firstName = sqlQuery.value(2).toString();
//            int idType = sqlQuery.value(3).toInt();

//            v_record.push_back(id);
//            v_record.push_back(lastName);
//            v_record.push_back(firstName);
//            v_record.push_back(convertIntToType(idType));


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
    QSqlQuery sqlQuery;
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

//vector<QString> DAO_Employee::searchEmployee(int id)
//{
//    vector<QString> v_record;
//    QSqlQuery sqlQuery;
//    sqlQuery.prepare("SELECT * FROM TRessource WHERE Id = ?");
//    sqlQuery.addBindValue(id);

//    if(!sqlQuery.exec())
//    {
//        qDebug() << sqlQuery.lastError();
//    }
//    else {
//        sqlQuery.next();
//        v_record.push_back(sqlQuery.value(0).toString());
//        v_record.push_back(sqlQuery.value(1).toString());
//        v_record.push_back(sqlQuery.value(2).toString());
//        v_record.push_back(convertIntToType(sqlQuery.value(3).toInt()));
//    }

//    return v_record;
//}

bool DAO_Employee::modifyEmployee(int id, QString lastname, QString firstname, int idType)
{
    QSqlQuery sqlQuery;
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
    QSqlQuery sqlQuery;
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
    QSqlQuery sqlQuery2;
    QString type;

    sqlQuery2.prepare("SELECT Label FROM TType WHERE Id = ?");
    sqlQuery2.addBindValue(idType);

    if(!sqlQuery2.exec())
    {
        qDebug() << sqlQuery2.lastError();
    }
    else{
        sqlQuery2.next();
        type = sqlQuery2.value(0).toString();
    }

    return type;
}
