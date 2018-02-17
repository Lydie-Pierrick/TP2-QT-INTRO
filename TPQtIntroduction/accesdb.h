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
    AccesDB();
private:
    QSqlDatabase db;
};

#endif // ACCESDB_H
