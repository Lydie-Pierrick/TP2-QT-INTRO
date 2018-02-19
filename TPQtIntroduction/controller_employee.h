#ifndef CONTROLLER_EMPLOYEE_H
#define CONTROLLER_EMPLOYEE_H

#include <QString>
#include "employee.h"
#include "accesdb.h"

class Controller_employee
{
public:
    Controller_employee();
    bool checkLogin(QString username, QString password);
    bool addEmployee(QString firstname, QString lastname, int type);
};

#endif // CONTROLLER_EMPLOYEE_H
