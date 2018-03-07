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
    map<QString,QString> m_attributsEmployee = daoEmployee.searchEmployee(id);

    QString lastname = m_attributsEmployee["lastname"];
    QString firstname = m_attributsEmployee["firstname"];
    QString type = m_attributsEmployee["type"];
    Employee e = Employee(id, lastname, firstname, type);

    return e;
}

bool Controller_employee::deleteEmployee(int id){
    return daoEmployee.deleteEmployee(id);
}

vector<Employee> Controller_employee::getAllEmployees()
{
    vector<map<QString, QString>> listEmployeeString = daoEmployee.getAllEmployees();
    map<QString, QString> m_record;
    vector<Employee> v_employees;
    Employee e;


    for (unsigned int i = 0; i < listEmployeeString.size(); i++)
    {
        m_record = listEmployeeString[i];
        e = Employee(m_record["id"].toInt(), m_record["lastname"], m_record["firstname"], m_record["type"]);

        v_employees.push_back(e);
    }

    return v_employees;
}

bool Controller_employee::modifyEmployee(int id, QString lastname, QString firstname, int idType)
{
    return daoEmployee.modifyEmployee(id, lastname, firstname, idType);
}

vector<QString> Controller_employee::getAllTypes()
{
    return daoEmployee.getAllTypes();
}