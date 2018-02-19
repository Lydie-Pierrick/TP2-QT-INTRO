#ifndef ACCESDB_H
#define ACCESDB_H

#include <iostream>
#include <QString>
#include <QSqlDatabase>
#include <QDebug>
#include <QFile>
#include <QSqlQuery>
#include <QSqlError>
#include "c_init_bd.h"

class AccesDB
{
public:
    static AccesDB& Instance();
    bool addEmployee(QString lastname, QString firstname, QString type);
private:
    AccesDB& operator= (const AccesDB&){}
    AccesDB(const AccesDB&){}
    QSqlDatabase db;

    static AccesDB m_instance;
    AccesDB();
    ~AccesDB();
};

#endif // ACCESDB_H
