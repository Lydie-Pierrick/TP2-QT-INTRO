#include "dao_client.h"

// Constructor
DAO_Client::DAO_Client()
{
    db = SingletonDB::getInstance()->getDB();
}

// Add a client
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
            // Get client ID
            int idClient = sqlQuery2.value(0).toInt();

            // Check if add ressources successfully
            if(addRessources(idClient, idsRes))
            {
                return true;
            }
        }
    }

    return false;
}

// Search client by ID
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
            // Get a map of all information of client
            m_record = collectInfosClient(sqlQuery);
            v_records.push_back(m_record);

            m_record.clear();
        }
    }
    return v_records;
}

// Search clients by name
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
            // Get a map of all information of client
            m_record = collectInfosClient(sqlQuery);
            v_records.push_back(m_record);

            m_record.clear();
        }
    }
    return v_records;
}

// Search clients by date
vector<map<QString, QString> > DAO_Client::searchClientsByDate(QDate dateFrom, QDate dateTo)
{
    vector<map<QString, QString> > v_records;
    map<QString, QString> m_record;
    QSqlQuery sqlQuery(db);
    sqlQuery.prepare("SELECT * FROM TClient WHERE DateRdv >= ? AND DateRdv <= ?");
    sqlQuery.addBindValue(dateFrom);
    sqlQuery.addBindValue(dateTo);

    if(!sqlQuery.exec())
    {
       qDebug() << sqlQuery.lastError();
    }
    else {
        while(sqlQuery.next())
        {
            // Get a map of all information of client
            m_record = collectInfosClient(sqlQuery);
            v_records.push_back(m_record);

            m_record.clear();
        }
    }
    return v_records;
}

// Get all clients form database
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
            // Get a map of all information of client
            m_record = collectInfosClient(sqlQuery);
            v_records.push_back(m_record);

            m_record.clear();
        }
    }
    return v_records;
}

// Delete a client
bool DAO_Client::deleteClient(int id)
{
    QSqlQuery sqlQuery(db);
    sqlQuery.prepare("DELETE FROM TClient WHERE Id = ? ");
    sqlQuery.addBindValue(id);

    QSqlQuery sqlQuery2(db);
    sqlQuery2.prepare("DELETE FROM TRdv WHERE IdClient = ? ");
    sqlQuery2.addBindValue(id);

    if(!sqlQuery2.exec())
    {
        qDebug() << sqlQuery2.lastError();
    }

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

// Modify a client
bool DAO_Client::modifyClient(int id, QString firstname, QString lastname, int telephone,
                              QString address, QString city, int postalCode, int duration,
                              QDate dateAppointment, int priorityAppointment, QString comment,
                              vector<int> idsRes)
{
    bool isOk = false;

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
        isOk = false;
    }
    else{
        isOk = true;
    }

    // Check if the sql was executed
    if(sqlQuery.exec())
    {
        QSqlQuery sqlQuery2(db);
        sqlQuery2.prepare("DELETE FROM TRdv WHERE IdClient = ?");
        sqlQuery2.addBindValue(id);
        // Check if the sql 2 was executed
        if(sqlQuery2.exec())
        {
            // Check if add ressources successfully
            if(addRessources(id, idsRes))
            {
                isOk = true;
            }
            else
            {
                isOk = false;
            }
        }
    }

    return isOk;
}

// Add ressources to a client
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
    }

    return true;
}

// Modify ressources of a client
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
            return true;
        }
    }

    return false;
}

// Searchi ressources IDs by client ID
vector<int> DAO_Client::searchRessourcesID(int idClient)
{
    QSqlQuery sqlQuery(db);
    sqlQuery.prepare("SELECT IdRessource FROM TRdv WHERE IdClient = ?");
    sqlQuery.addBindValue(idClient);

    int idRes;
    vector<int> v_records;

    if(!sqlQuery.exec())
    {
       qDebug() << sqlQuery.lastError();
    }
    else {
        while(sqlQuery.next())
        {
            idRes = sqlQuery.value(0).toInt();
            v_records.push_back(idRes);
        }
    }
    return v_records;
}

// Collect all the infomation of client and return to map
map<QString, QString> DAO_Client::collectInfosClient(QSqlQuery sqlQuery)
{
    map<QString, QString> m_record;

    // Insert pairs into the map with keys and values
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
