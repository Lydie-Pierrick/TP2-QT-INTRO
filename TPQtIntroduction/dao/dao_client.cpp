#include "dao_client.h"

DAO_Client::DAO_Client()
{
    db = SingletonDB::getInstance();
}

bool DAO_Client::addClient(QString firstname, QString lastname, int telephone,
                           QString address, QString city, int postalCode, int duration,
                           QDate dateAppointment, int priorityAppointment, QString comment,
                           vector<int> idsRes)
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

    // Check if the sql was executed
    if(sqlQuery.exec())
    {
        QSqlQuery sqlQuery2(db);
        sqlQuery2.prepare("SELECT last_insert_rowid()");
        // Check if the sql 2 was executed
        if(sqlQuery2.exec())
        {
            sqlQuery2.next();
            int idClient = sqlQuery2.value(0).toInt();

            // Check if add ressources successfully
            if(addRessources(idClient, idsRes))
            {
                qDebug() <<"Successfully add client";
                return true;
            }
        }
    }

    return false;
}

vector<map<QString, QString> > DAO_Client::searchClientById(int id)
{
    vector<map<QString, QString> > v_records;
    map<QString, QString> m_record;

    QSqlQuery sqlQuery(db);
    sqlQuery.prepare("SELECT * FROM TClient WHERE Id = ?");
    sqlQuery.addBindValue(id);

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

bool DAO_Client::modifyClient(int id, QString firstname, QString lastname, int telephone,
                              QString address, QString city, int postalCode, int duration,
                              QDate dateAppointment, int priorityAppointment, QString comment,
                              vector<int> idsRes)
{
    QSqlQuery sqlQuery(db);
    sqlQuery.prepare("UPDATE TClient SET Nom = ?, Prenom = ?, Adresse = ?, Ville = ?, CP = ?, "
                     "Commentaire = ?, Tel = ?, DateRdv = ?, DureeRdv = ?, Priorite = ? "
                     "WHERE Id = ?");
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
    sqlQuery.addBindValue(id);

    if(!sqlQuery.exec())
    {
        qDebug() << sqlQuery.lastError();
        return false;
    }
    else{
        return true;
    }

//    // Check if the sql was executed
//    if(sqlQuery.exec())
//    {
//        QSqlQuery sqlQuery2(db);
//        sqlQuery2.prepare("SELECT last_insert_rowid()");
//        // Check if the sql 2 was executed
//        if(sqlQuery2.exec())
//        {
//            sqlQuery2.next();
//            int idClient = sqlQuery2.value(0).toInt();

//            // Check if add ressources successfully
//            if(addRessources(idClient, idsRes))
//            {
//                qDebug() <<"Successfully add client";
//                return true;
//            }
//        }
//    }

}

bool DAO_Client::addRessources(int idClient, vector<int> idRessources)
{
    QSqlQuery sqlQuery(db);

    for(unsigned int i = 0; i < idRessources.size(); i++)
    {
        sqlQuery.prepare("INSERT INTO TRdv (IdClient, IdRessource) VALUES (?,?)");
        sqlQuery.addBindValue(idClient);
        sqlQuery.addBindValue(idRessources[i]);

        if(!sqlQuery.exec())
        {
            qDebug() << sqlQuery.lastError();
            return false;
        }
        else
        {
            qDebug() <<"Successfully added ressource to client " + idClient;
            return true;
        }
    }

    return false;
}

bool DAO_Client::modifyRessources(int idClient, vector<int> idRessources)
{
    QSqlQuery sqlQuery(db);

    for(unsigned int i = 0; i < idRessources.size(); i++)
    {
        sqlQuery.prepare("UPDATE TRdv SET IdClient = ?, IdRessource = ?");
        sqlQuery.addBindValue(idClient);
        sqlQuery.addBindValue(idRessources[i]);

        if(!sqlQuery.exec())
        {
            qDebug() << sqlQuery.lastError();
            return false;
        }
        else
        {
            qDebug() <<"Successfully modified ressource to client " + idClient;
            return true;
        }
    }

    return false;
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
