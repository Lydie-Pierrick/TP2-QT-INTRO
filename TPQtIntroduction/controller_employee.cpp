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

bool Controller_employee::addEmployee(QString firstname, QString lastname, QString type)
{
    cout << "Remove cout !!! Add employee Controller. Firstname: " << firstname.toStdString() << " and Name: " << lastname.toStdString() << " and Type: " << type.toStdString() << endl;

   // AccesDB& db = AccesDB::Instance();

//    if(!db.addEmployee(firstname, lastname, type)) // SQL QUERY if return false = already exist
//        return false;

    return true;
}

vector<QString> Controller_employee::searchEmployee(int id)
{
    return daoEmployee.searchEmployee(id);
}

bool Controller_employee::deleteEmployee(int id){
    cout<<"Delete employee"<<endl;
    return true;
}

vector<vector<QString>> Controller_employee::getAllEmployees()
{
    return daoEmployee.getAllEmployees();
}

bool Controller_employee::modifyEmployee(int id, QString lastname, QString firstname, int idType){
    if (daoEmployee.modifyEmployee(id, lastname, firstname, idType)){
        return true;
    }
    else
    {
        return false;
    }
}

/*
void Controller_employee::setSelectedID(int selectedID)
{
    this->selectedID = selectedID;
}

int Controller_employee::getSelectedID()
{
    return selectedID;
}
*/
