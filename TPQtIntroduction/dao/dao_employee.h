#ifndef DAO_EMPLOYEE_H
#define DAO_EMPLOYEE_H
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <vector>
#include <map>

using namespace std;

class DAO_Employee
{
public:
    DAO_Employee();
    bool addEmployee(QString firstname, QString lastname, int idType);
    vector<map<QString, QString>> getAllEmployees();
    //vector<QString> searchEmployee(int id);
    map<QString,QString> searchEmployee(int id);
    bool modifyEmployee(int id, QString lastname, QString firstname, int idType);
    bool deleteEmployee(int id);
    QString convertIntToType(int idType);
    vector<map<QString, QString>> getAllTypes();
    vector<map<QString, QString>> getEmployeesByType(int idType);

};

#endif // DAO_EMPLOYEE_H
