#include "employee.h"

// Default Constructor
Employee::Employee()
{

}

// Constructor
Employee::Employee(int id, QString lastname, QString firstname, QString type, QString username, QString password)
{
    this->id = id;
    this->firstname = firstname;
    this->lastname = lastname;
    this->type = type;
    this->username = username;
    this->password = password;
}

// Getter Setter
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

QString Employee::getUsername() const
{
    return username;
}

void Employee::setUsername(const QString &value)
{
    username = value;
}

QString Employee::getPassword() const
{
    return password;
}

void Employee::setPassword(const QString &value)
{
    password = value;
}
