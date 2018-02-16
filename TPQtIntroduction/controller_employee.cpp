#include "controller_employee.h"

Controller_employee::Controller_employee()
{

}

bool Controller_employee::checkLogin(QString username, QString password)
{
    QString path = "test";
    AccesBD * test = new AccesBD(path);

    // Requete SQL ICI !!
    if(username == "lydie" && password == "ahah")
        return true;
//    if(database.searchUser(username) == username && database.searchUser(password) == password)
//        return true;

    return false;
}
