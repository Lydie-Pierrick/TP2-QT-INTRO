#include "controller_employee.h"

Controller_employee::Controller_employee()
{

}

bool Controller_employee::checkLogin(QString username, QString password)
{
    QString path = "test";
//    AccesBD * test = new AccesBD(path);

    // Requete SQL ICI !!
    if(username == "lydie" && password == "ahah")
        return true;
//    if(database.searchUser(username) == username && database.searchUser(password) == password)
//        return true;

    return false;
}

bool Controller_employee::addEmployee(QString firstname, QString lastname, int idType)
{
    return daoEmployee.addEmployee(firstname, lastname, idType);
}

Employee Controller_employee::searchEmployee(int id)
{
    vector<QString> attributesEmployee = daoEmployee.searchEmployee(id);
    Employee e = Employee(attributesEmployee);

    return e;
}

bool Controller_employee::deleteEmployee(int id){
    return daoEmployee.deleteEmployee(id);
}

vector<Employee> Controller_employee::getAllEmployees()
{
    vector<vector<QString>> listEmployeeString = daoEmployee.getAllEmployees();
    vector<Employee> listEmployee;
    Employee e;


    for (unsigned int i = 0; i < listEmployeeString.size(); i++)
    {
        e = Employee(listEmployeeString[i]);
        listEmployee.push_back(e);
    }

    return listEmployee;
}

bool Controller_employee::modifyEmployee(int id, QString lastname, QString firstname, int idType)
{
    return daoEmployee.modifyEmployee(id, lastname, firstname, idType);
}

