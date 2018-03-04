#ifndef CONTROLLER_EMPLOYEE_H
#define CONTROLLER_EMPLOYEE_H

#include <QString>
#include "employee.h"
//#include "accesdb.h"
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
<<<<<<< HEAD
    bool addEmployee(QString firstname, QString lastname, int idType);
    vector<QString> searchEmployee(int id);
    bool searchEmployee(QString name);
    bool modifyEmployee(int id, QString lastname, QString firstname, int idType);
    bool deleteEmployee(int id);
    vector<vector<QString>> getAllEmployees();
=======
    bool addEmployee(QString firstname, QString lastname, int type);
>>>>>>> master
};



#endif // CONTROLLER_EMPLOYEE_H
