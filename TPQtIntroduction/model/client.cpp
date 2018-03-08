#include "client.h"

Client::Client(QString firstname, QString lastname, int telephone,
               QString address, QString city, int postalCode, int duration,
               QString dateAppointment, int priorityAppointment, QString comment)
{
    this->firstName = firstname;
    this->lastName = lastname;
    this->telephone = telephone;
    this->address = address;
    this->city = city;
    this->postalCode = postalCode;
    this->duration = duration;
    this->dateAppointment = dateAppointment;
    this->priorityAppointment = priorityAppointment;
    this->comment = comment;
}

void Client::setLastName(const QString &value)
{
    lastName = value;
}

QString Client::getLastName() const
{
    return lastName;
}

void Client::setFirstName(const QString &value)
{
    firstName = value;
}

QString Client::getFirstName() const
{
    return firstName;
}

void Client::setAddress(const QString &value)
{
    address = value;
}

QString Client::getAddress() const
{
    return address;
}

void Client::setCity(const QString &value)
{
    city = value;
}

int Client::getTelephone() const
{
    return telephone;
}

void Client::setPostalCode(int value)
{
    postalCode = value;
}

int Client::getPostalCode() const
{
    return postalCode;
}

void Client::setDuration(int value)
{
    duration = value;
}

int Client::getDuration() const
{
    return duration;
}

void Client::setDateAppointment(const QString &value)
{
    dateAppointment = value;
}

QString Client::getDateAppointment() const
{
    return dateAppointment;
}

void Client::setPriorityAppointment(int value)
{
    priorityAppointment = value;
}

int Client::getPriorityAppointment() const
{
    return priorityAppointment;
}

void Client::setComment(const QString &value)
{
    comment = value;
}

QString Client::getComment() const
{
    return comment;
}
