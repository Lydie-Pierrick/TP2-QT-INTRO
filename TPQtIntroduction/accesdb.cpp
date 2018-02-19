#include "accesdb.h"

AccesDB AccesDB::m_instance=AccesDB();

AccesDB::AccesDB()
{
    // Init DB
    C_INIT_BD::Creation_BD();

    // Open DB
    db = QSqlDatabase::addDatabase("QSQLITE");

    if(db.isValid())
    {
        db.setHostName("localhost");
        db.setUserName("root");
        db.setPassword("password");

        if(!QFile::exists("base_tmp.sqli"))
            exit(1);

        db.setDatabaseName("base_tmp.sqli");
        db.open();

        if(!db.isOpen())
        {
            qDebug() << db.lastError().text();
            qDebug() << "Erreur à louverture de la base !\n";
        }
    }
}

AccesDB::~AccesDB()
{

}

AccesDB& AccesDB::Instance()
{
    return m_instance;
}

bool AccesDB::addEmployee(QString lastname, QString firstname, QString type)
{
    bool b_test = false;
    unsigned int id;

    QSqlQuery query(db);


    // Query to get last id determined by the number of line
    query.prepare("SELECT * FROM TRessource");
    query.exec();

    id = query.size() + 1;

    // Insert employee

    query.prepare("INSERT INTO TRessource (id, name, firstname,) "
                      "VALUES (:Id, :Name, :Firstname)");
    query.bindValue(":Id", id);
    query.bindValue(":Name", lastname);
    query.bindValue(":Firs", firstname);
    query.bindValue(":IdType", type);

    b_test=query.exec();

    if(!b_test)
    {
        qDebug() << query.lastError().text();
        qDebug() << "Insertion de données dans TRessource impossible !\n";
        return false;
    }

    return true;
}
