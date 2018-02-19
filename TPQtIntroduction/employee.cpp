#include "employee.h"

Employee::Employee()
{

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

int Employee::getType() const
{
    return type;
}

void Employee::setType(int value)
{
    type = value;
}
