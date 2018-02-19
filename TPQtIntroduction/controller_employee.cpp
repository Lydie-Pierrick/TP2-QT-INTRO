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

bool Controller_employee::addEmployee(QString firstname, QString lastname, int type)
{
    cout << "Remove cout !!! Add employee Controller. Firstname: " << firstname.toStdString() << " and Name: " << lastname.toStdString() << " and Type: " << type << endl;

    AccesDB& db = AccesDB::Instance();

    bool test = db.addEmployee(firstname, lastname, type);
    if(!test) // SQL QUERY if return false = already exist
        return false;

    return true;
}
