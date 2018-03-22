#include "singletondb.h"
#include <iostream>

// Singleton to have just one instance of database

using namespace std;

SingletonDB* SingletonDB::m_instance = NULL;
QSqlDatabase SingletonDB::db;

// A private Constructor
SingletonDB::SingletonDB()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("base_tmp.sqli");
    db.open();
}

// Destructor
SingletonDB::~SingletonDB()
{
    db.close();
}

// Static 'instance' method
SingletonDB* SingletonDB::getInstance()
{
    if(m_instance == NULL)
        m_instance = new SingletonDB();

    return m_instance;
}

// Get DB of Instance in all program
QSqlDatabase SingletonDB::getDB()
{
    return db;
}

// Get Close DB method of Instance in all program
void SingletonDB::closeDB()
{
    if(m_instance != NULL) {
        delete m_instance;
        m_instance = NULL;
    }
}
