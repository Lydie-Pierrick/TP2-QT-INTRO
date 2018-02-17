#include "accesdb.h"

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

        QSqlQuery query(db);
        if(!db.isOpen())
        {
            qDebug() << db.lastError().text();
            qDebug() << "Erreur à louverture de la base !\n";
        }
    }
}
