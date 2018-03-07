#ifndef CONTROLLER_EMPLOYEE_H
#define CONTROLLER_EMPLOYEE_H

#include <QString>
#include "employee.h"
#include "dao_employee.h"
#include <iostream>

using namespace std;

class Controller_employee
{
private:
    DAO_Employee daoEmployee;
public:
    static int selectedID;
    Controller_employee();
    bool checkLogin(QString username, QString password);
    bool addEmployee(QString firstname, QString lastname, int idType);
    Employee searchEmployee(int id);
    bool searchEmployee(QString name);
    bool modifyEmployee(int id, QString lastname, QString firstname, int idType);
    bool deleteEmployee(int id);
    vector<Employee> getAllEmployees();
    vector<QString> getAllTypes();
};



#endif // CONTROLLER_EMPLOYEE_H
