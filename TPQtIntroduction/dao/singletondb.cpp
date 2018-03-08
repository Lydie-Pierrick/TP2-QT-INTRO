#include "singletondb.h"
#include <iostream>
using namespace std;

SingletonDB* SingletonDB::m_instance = nullptr;
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

QSqlDatabase SingletonDB::getInstance()
{
    if(m_instance == nullptr)
        m_instance = new SingletonDB();

    return db;
}
void SingletonDB::closeDB()
{
    if(m_instance != nullptr) {
        delete m_instance;
        m_instance = nullptr;
    }
}
