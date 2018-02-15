#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

using namespace std;

enum typeEmployee{
    bankerA = 1,
    bankerB = 2,
    housingInsurer = 3,
    carInsurer = 4,
    lifeInsurer = 5,
    computerScientist = 6,
    other = 7
};

class Employee
{
public:
    Employee();
private:
    string lastname;
    string firstname;
    typeEmployee type;
};

#endif // EMPLOYEE_H
