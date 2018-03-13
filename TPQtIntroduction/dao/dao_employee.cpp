#include "dao_employee.h"

DAO_Employee::DAO_Employee()
{
    db = SingletonDB::getInstance();
}

bool DAO_Employee::addEmployee(QString firstname, QString lastname, int idType, QString username, QString password)
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
        if(convertIntToType(idType) == "Computer Scientist" && !username.isEmpty() && !password.isEmpty())
        {
            QSqlQuery sqlQuery2(db);
            sqlQuery2.prepare("INSERT INTO TCompte (IdRessource, Login, MdP) VALUES (?, ?, ?)");
            sqlQuery2.addBindValue(sqlQuery.lastInsertId());
            sqlQuery2.addBindValue(username);
            sqlQuery2.addBindValue(password);

            if(!sqlQuery2.exec())
            {
                qDebug() << sqlQuery2.lastError();
            }
        }

        return true;
    }
}

vector<map<QString, QString> > DAO_Employee::getAllEmployees()
{
    map<QString, QString> m_record;
    vector<map<QString, QString> > v_records;
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

map<QString, QString> DAO_Employee::getEmployeeAccount(int id)
{
    map<QString, QString> m_record;

    QSqlQuery sqlQuery(db);
    sqlQuery.prepare("SELECT * FROM TCompte where IdRessource = ?");
    sqlQuery.addBindValue(id);

    if(!sqlQuery.exec())
    {
        qDebug() << sqlQuery.lastError();
    }
    else
    {
        sqlQuery.next();
        m_record.insert(pair<QString,QString>("username", sqlQuery.value(0).toString()));
        m_record.insert(pair<QString,QString>("password", sqlQuery.value(1).toString()));
    }

    return m_record;
}

void DAO_Employee::modify_TCompte_ITUser(int idType, QString username, QString password, int id)
{
    // Check if an entry already existed in TCompte
    bool alreadyExist = false;
    QSqlQuery sqlQuery2(db);
    sqlQuery2.prepare("SELECT * FROM TCompte where IdRessource = ?");
    sqlQuery2.addBindValue(id);

    if(!sqlQuery2.exec())
    {
        qDebug() << sqlQuery2.lastError();
    }

    alreadyExist = sqlQuery2.next();

    // If it's a Computer Scientist Update if exist or insert new row account
    if(convertIntToType(idType) == "Computer Scientist" && !username.isEmpty() && !password.isEmpty())
    {
        QSqlQuery sqlQuery3(db);

        if(alreadyExist){
            sqlQuery3.prepare("UPDATE INTO TCompte(Id, IdRessource, Login, MdP) VALUES (?, ?, '?', '?')");
            sqlQuery3.addBindValue(sqlQuery2.value(0).toInt());
        }
        else{
            sqlQuery3.prepare("INSERT INTO TCompte (IdRessource, Login, MdP) VALUES (?, ?, ?)");
        }

        sqlQuery3.addBindValue(id);
        sqlQuery3.addBindValue(username);
        sqlQuery3.addBindValue(password);

        if(!sqlQuery3.exec())
        {
            qDebug() << sqlQuery3.lastError();
        }
    }
    // Or delete row if employee is not Computer Scientist
    else
    {
        if(alreadyExist)
        {
            QSqlQuery sqlQuery4(db);
            sqlQuery4.prepare("DELETE FROM TCompte WHERE IdRessource = ?");
            sqlQuery4.addBindValue(id);

            if(!sqlQuery4.exec())
            {
                qDebug() << sqlQuery4.lastError();
            }
        }
    }
}

bool DAO_Employee::modifyEmployee(int id, QString lastname, QString firstname, int idType, QString username, QString password)
{
    QSqlQuery sqlQuery(db);
    sqlQuery.prepare("UPDATE TRessource SET Nom = ?, Prenom = ?, IdType = ? WHERE Id = ? ");
    sqlQuery.addBindValue(lastname);
    sqlQuery.addBindValue(firstname);
    sqlQuery.addBindValue(idType);
    sqlQuery.addBindValue(id);

    // Modify the table TCompte to manage account
    modify_TCompte_ITUser(idType, username, password, id);

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
    // Remove account of Computer Scientist
    map<QString,QString> m_employee = searchEmployee(id);
    if(m_employee["type"] == "Computer Scientist")
    {
        // Check if account exist to avoid error
        QSqlQuery sqlQuery(db);
        sqlQuery.prepare("SELECT * FROM TCompte where IdRessource = ?");
        sqlQuery.addBindValue(id);

        if(!sqlQuery.exec())
        {
            qDebug() << sqlQuery.lastError();
        }

        // Delete account if an account exist
        if(sqlQuery.next())
        {
            QSqlQuery sqlQuery1(db);
            sqlQuery1.prepare("DELETE FROM TCompte WHERE IdRessource = ?");
            sqlQuery1.addBindValue(id);

            if(!sqlQuery1.exec())
            {
                qDebug() << sqlQuery1.lastError();
            }
        }
    }

    QSqlQuery sqlQuery2(db);
    sqlQuery2.prepare("DELETE FROM TRessource WHERE Id = ? ");
    sqlQuery2.addBindValue(id);

    if(!sqlQuery2.exec())
    {
        qDebug() << sqlQuery2.lastError();
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

vector<map<QString, QString> > DAO_Employee::getAllTypes()
{
    vector<map<QString, QString> > v_records;
    map<QString, QString> m_record;
    QSqlQuery sqlQuery;
    sqlQuery.prepare("SELECT * FROM TType");
    if(!sqlQuery.exec())
    {
        qDebug() << sqlQuery.lastError();
    }
    else
    {
        while(sqlQuery.next())
        {
            m_record.insert(pair<QString,QString>("id", sqlQuery.value(0).toString()));
            m_record.insert(pair<QString,QString>("label", sqlQuery.value(1).toString()));

            v_records.push_back(m_record);
            m_record.clear();
        }
    }

    return v_records;
}

vector<map<QString, QString> > DAO_Employee::getEmployeesByType(int idType)
{
    map<QString, QString> m_record;
    vector<map<QString, QString> > v_records;
    QSqlQuery sqlQuery;
    sqlQuery.prepare("SELECT * FROM TRessource where idType = ?");
    sqlQuery.addBindValue(idType);

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
