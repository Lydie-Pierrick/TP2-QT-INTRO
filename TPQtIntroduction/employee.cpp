#include "employee.h"

Employee::Employee()
{

}

Employee::Employee(vector<QString> elementEmployee)
{
    id = elementEmployee[0].toInt();
    lastname = elementEmployee[1];
    firstname = elementEmployee[2];
    type = elementEmployee[3];
}

int Employee::getId() const
{
    return id;
}

void Employee::setId(int value)
{
    id = value;
}

QString Employee::getLastname() const
{
    return lastname;
}

void Employee::setLastname(const QString &value)
{
    lastname = value;
}

QString Employee::getFirstname() const
{
    return firstname;
}

void Employee::setFirstname(const QString &value)
{
    firstname = value;
}

QString Employee::getType() const
{
    return type;
}

void Employee::setType(QString value)
{
    type = value;
}
