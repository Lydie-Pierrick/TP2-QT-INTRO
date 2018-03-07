#include "employee.h"

Employee::Employee()
{

}

Employee::Employee(int id, QString lastname, QString firstname, QString type)
{
    this->id = id;
    this->firstname = firstname;
    this->lastname = lastname;
    this->type = type;
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
