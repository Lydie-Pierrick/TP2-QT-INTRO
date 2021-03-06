#ifndef DAO_EMPLOYEE_H
#define DAO_EMPLOYEE_H
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <vector>
#include <map>
#include "singletondb.h"

using namespace std;

class DAO_Employee
{
public:
    DAO_Employee();
    bool addEmployee(QString firstname, QString lastname, int idType, QString username, QString password);
    bool addEmployeeOther(QString firstname, QString lastname);
    vector<map<QString, QString> > getAllEmployees();
    map<QString,QString> searchEmployee(int id);
    map<QString, QString> getEmployeeAccount(int id);
    bool modifyEmployee(int id, QString lastname, QString firstname, int idType, QString username, QString password);
    bool deleteEmployee(int id);
    QString convertIntToType(int idType);
    vector<map<QString, QString> > getAllTypes();
    vector<map<QString, QString> > getEmployeesByType(int idType);
    bool checkLogin(QString username, QString password);
    static int counter_insert;
private:
    QSqlDatabase db;
    void modify_TCompte_ITUser(int idType, QString username, QString password, int id);
};

#endif // DAO_EMPLOYEE_H
