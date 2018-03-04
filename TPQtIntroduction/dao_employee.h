#ifndef DAO_EMPLOYEE_H
#define DAO_EMPLOYEE_H
#include <QSqlQuery>
#include <QDebug>
#include <vector>
using namespace std;

class DAO_Employee
{
public:
    DAO_Employee();
    bool addEmployee(QString firstname, QString lastname, int idType);
    vector<vector<QString>> getAllEmployees();
    vector<QString> searchEmployee(int id);
    bool modifyEmployee(int id, QString firstname, QString lastname, int idType);
    bool deleteEmployee(int id);
};

#endif // DAO_EMPLOYEE_H
