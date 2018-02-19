#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QString>

using namespace std;

//enum typeEmployee{
//    bankerA = 0,
//    bankerB = 1,
//    housingInsurer = 2,
//    carInsurer = 3,
//    lifeInsurer = 4,
//    computerScientist = 5,
//    other = 6
//};

class Employee
{
public:
    Employee();
    int getId() const;
    void setId(int value);

    QString getLastname() const;
    void setLastname(const QString &value);

    QString getFirstname() const;
    void setFirstname(const QString &value);

    int getType() const;
    void setType(int value);

private:
    int id;
    QString lastname;
    QString firstname;
    int type;
};

#endif // EMPLOYEE_H
