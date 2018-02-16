#ifndef CONTROLLER_EMPLOYEE_H
#define CONTROLLER_EMPLOYEE_H

#include <QString>
#include "employee.h"
#include "accesbd.h"

class Controller_employee
{
public:
    Controller_employee();
    bool checkLogin(QString username, QString password);
};

#endif // CONTROLLER_EMPLOYEE_H
