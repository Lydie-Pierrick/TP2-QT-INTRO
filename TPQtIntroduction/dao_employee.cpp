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
        //qDebug()<<sql_query.lastError();
        return false;
    }
    else
    {
        return true;
    }
}

vector<vector<QString>> DAO_Employee::getAllEmployees()
{
    vector<vector<QString>> v_records;
    QSqlQuery sqlQuery;
    sqlQuery.prepare("SELECT * FROM TRessource");
    if(!sqlQuery.exec())
    {
        //qDebug()<<sql_query.lastError();
    }
    else
    {
        while(sqlQuery.next())
        {
            vector<QString> v_record; // record a line
            QString id = sqlQuery.value(0).toString();
            QString lastName = sqlQuery.value(1).toString();
            QString firstName = sqlQuery.value(2).toString();
            int idType = sqlQuery.value(3).toInt();

            QSqlQuery sqlQuery2;
            sqlQuery2.prepare("SELECT Label FROM TType WHERE Id = ?");
            sqlQuery2.addBindValue(idType);

            v_record.push_back(id);
            v_record.push_back(lastName);
            v_record.push_back(firstName);
            if(!sqlQuery2.exec())
            {
                //qDebug()<<sql_query.lastError();
                v_record.push_back("xxx");
            }
            else{
                sqlQuery2.next();
                QString type = sqlQuery2.value(0).toString();
                v_record.push_back(type);
            }
            v_records.push_back(v_record);

        }
    }

    return v_records;
}

vector<QString> DAO_Employee::searchEmployee(int id)
{
    vector<QString> v_record;
    QSqlQuery sqlQuery;
    sqlQuery.prepare("SELECT * FROM TRessource WHERE Id = ?");
    sqlQuery.addBindValue(id);

    if(!sqlQuery.exec())
    {
        //qDebug()<<sql_query.lastError();
    }
    else{
        sqlQuery.next();
        v_record.push_back(sqlQuery.value(1).toString());
        v_record.push_back(sqlQuery.value(2).toString());
        v_record.push_back(sqlQuery.value(3).toString());
    }
    return v_record;
}

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
        //qDebug()<<sql_query.lastError();
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
        //qDebug()<<sql_query.lastError();
        return false;
    }
    else{
        return true;
    }
}
