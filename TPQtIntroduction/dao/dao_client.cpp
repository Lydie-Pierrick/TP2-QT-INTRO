#include "dao_client.h"

DAO_Client::DAO_Client()
{
    db = SingletonDB::getInstance();
}

bool DAO_Client::addClient(QString firstname, QString lastname, int telephone,
                           QString address, QString city, int postalCode, int duration,
                           QDate dateAppointment, int priorityAppointment, QString comment)
{
    QSqlQuery sqlQuery(db);
    sqlQuery.prepare("INSERT INTO TClient "
                     "(Nom, Prenom, Adresse, Ville, CP, "
                     "Commentaire, Tel, DateRdv, DureeRdv, Priorite) "
                     "VALUES (?,?,?,?,?,?,?,?,?,?)");
    sqlQuery.addBindValue(lastname);
    sqlQuery.addBindValue(firstname);
    sqlQuery.addBindValue(address);
    sqlQuery.addBindValue(city);
    sqlQuery.addBindValue(postalCode);
    sqlQuery.addBindValue(comment);
    sqlQuery.addBindValue(telephone);
    sqlQuery.addBindValue(dateAppointment);
    sqlQuery.addBindValue(duration);
    sqlQuery.addBindValue(priorityAppointment);

    if(!sqlQuery.exec())
    {
        qDebug() << sqlQuery.lastError();

        return false;
    }
    else
    {
        qDebug() <<"Successfully add client";
        return true;
    }
}

map<QString, QString> DAO_Client::searchClientById(int id)
{
    map<QString, QString> m_record;
    QSqlQuery sqlQuery(db);
    sqlQuery.prepare("SELECT * FROM TClient WHERE Id = ?");
    sqlQuery.addBindValue(id);

    if(sqlQuery.exec())
    {
       sqlQuery.next();
       m_record = collectInfosClient(sqlQuery);
    }
    else
        qDebug() << sqlQuery.lastError();

    return m_record;
}

bool DAO_Client::searchClientExistById(int id)
{
    map<QString, QString> m_record;
    QSqlQuery sqlQuery(db);
    sqlQuery.prepare("SELECT * FROM TClient WHERE Id = ?");
    sqlQuery.addBindValue(id);

    if(sqlQuery.exec())
    {
       if(sqlQuery.next())
           return true;
    }
    else
        qDebug() << sqlQuery.lastError();

    return false;
}

vector<map<QString, QString> > DAO_Client::searchClientsByName(QString name)
{
    vector<map<QString, QString> > v_records;
    map<QString, QString> m_record;
    QSqlQuery sqlQuery(db);
    sqlQuery.prepare("SELECT * FROM TClient WHERE Nom LIKE ? or Prenom LIKE ?");
    sqlQuery.addBindValue("%"+name+"%");
    sqlQuery.addBindValue("%"+name+"%");

    if(!sqlQuery.exec())
    {
       qDebug() << sqlQuery.lastError();
    }
    else {
        while(sqlQuery.next())
        {
            m_record = collectInfosClient(sqlQuery);
            v_records.push_back(m_record);

            m_record.clear();
        }
    }
    return v_records;
}

vector<map<QString, QString> > DAO_Client::searchClientsByDate(QDate date)
{
    vector<map<QString, QString> > v_records;
    map<QString, QString> m_record;
    QSqlQuery sqlQuery(db);
    sqlQuery.prepare("SELECT * FROM TClient WHERE DateRdv = ?");
    sqlQuery.addBindValue(date);

    if(!sqlQuery.exec())
    {
       qDebug() << sqlQuery.lastError();
    }
    else {
        while(sqlQuery.next())
        {
            m_record = collectInfosClient(sqlQuery);
            v_records.push_back(m_record);

            m_record.clear();
        }
    }
    return v_records;
}

vector<map<QString, QString> > DAO_Client::getAllClients()
{
    vector<map<QString, QString> > v_records;
    map<QString, QString> m_record;
    QSqlQuery sqlQuery(db);
    sqlQuery.prepare("SELECT * FROM TClient");

    if(!sqlQuery.exec())
    {
       qDebug() << sqlQuery.lastError();
    }
    else {
        while(sqlQuery.next())
        {
            m_record = collectInfosClient(sqlQuery);
            v_records.push_back(m_record);

            m_record.clear();
        }
    }
    return v_records;
}

bool DAO_Client::deleteClient(int id)
{
    QSqlQuery sqlQuery(db);
    sqlQuery.prepare("DELETE FROM TClient WHERE Id = ? ");
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

map<QString, QString> DAO_Client::collectInfosClient(QSqlQuery sqlQuery)
{
    map<QString, QString> m_record;

    m_record.insert(pair<QString,QString>("id", sqlQuery.value(0).toString()));
    m_record.insert(pair<QString,QString>("lastname", sqlQuery.value(1).toString()));
    m_record.insert(pair<QString,QString>("firstname", sqlQuery.value(2).toString()));
    m_record.insert(pair<QString,QString>("address", sqlQuery.value(3).toString()));
    m_record.insert(pair<QString,QString>("city", sqlQuery.value(4).toString()));
    m_record.insert(pair<QString,QString>("postalCode", sqlQuery.value(5).toString()));
    m_record.insert(pair<QString,QString>("comment", sqlQuery.value(6).toString()));
    m_record.insert(pair<QString,QString>("telephone", sqlQuery.value(7).toString()));
    m_record.insert(pair<QString,QString>("date", sqlQuery.value(8).toString()));
    m_record.insert(pair<QString,QString>("duration", sqlQuery.value(9).toString()));
    m_record.insert(pair<QString,QString>("priority", sqlQuery.value(10).toString()));
    return m_record;
}
