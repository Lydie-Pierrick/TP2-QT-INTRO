#include "singletondb.h"
#include <iostream>

using namespace std;

SingletonDB* SingletonDB::m_instance = NULL;
QSqlDatabase SingletonDB::db;

SingletonDB::SingletonDB()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("base_tmp.sqli");
    db.open();
}

SingletonDB::~SingletonDB()
{
    db.close();
}

SingletonDB* SingletonDB::getInstance()
{
    if(m_instance == NULL)
        m_instance = new SingletonDB();

    return m_instance;
}

QSqlDatabase SingletonDB::getDB()
{
    return db;
}

void SingletonDB::closeDB()
{
    if(m_instance != NULL) {
        delete m_instance;
        m_instance = NULL;
    }
}
