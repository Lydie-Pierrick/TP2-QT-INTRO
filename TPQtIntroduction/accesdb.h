#ifndef ACCESDB_H
#define ACCESDB_H

#include <iostream>
#include <QString>
#include <QSqlDatabase>
#include <QDebug>
#include <QFile>
#include <QSqlQuery>
#include <QSqlError>
#include <vector>

#include "c_init_bd.h"
#include "employee.h"

class AccesDB
{
public:
    static AccesDB& Instance();
    bool addEmployee(QString lastname, QString firstname, int type);
    Employee getEmployeeById(int id);
    vector<Employee> getEmployeeAll();
private:
    AccesDB& operator= (const AccesDB&) = delete;
    AccesDB (const AccesDB&){}
    QSqlDatabase db;

    static AccesDB m_instance;
    AccesDB();
    ~AccesDB();
};

#endif // ACCESDB_H
