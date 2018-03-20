#ifndef SINGLETONDB_H
#define SINGLETONDB_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QFile>

using namespace std;

class SingletonDB
{
private:
    static SingletonDB *m_instance;
    static QSqlDatabase db;

    SingletonDB();
    ~SingletonDB();
public:
    static SingletonDB* getInstance();
    static QSqlDatabase getDB();
    static void closeDB();
};

#endif // SINGLETONDB_H

