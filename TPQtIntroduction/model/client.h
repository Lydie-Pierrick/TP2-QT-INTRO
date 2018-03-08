#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <QString>
using namespace std;

enum priority{
    priority1=1,
    priority2=2,
    priority3=3,
    priority4=4,
    priority5=5
};

class Client
{
public:
    Client(QString firstname, QString lastname, int telephone,
            QString address, QString city, int postalCode, int duration,
            QString dateAppointment, int priorityAppointment, QString comment);

    void setLastName(const QString &value);
    QString getLastName() const;
    void setFirstName(const QString &value);
    QString getFirstName() const;
    void setAddress(const QString &value);
    QString getAddress() const;
    void setCity(const QString &value);
    int getTelephone() const;
    void setPostalCode(int value);
    int getPostalCode() const;
    void setDuration(int value);
    int getDuration() const;
    void setDateAppointment(const QString &value);
    QString getDateAppointment() const;
    void setPriorityAppointment(int value);
    int getPriorityAppointment() const;
    void setComment(const QString &value);
    QString getComment() const;

private:
    QString lastName;
    QString firstName;
    QString address;
    QString city;
    int telephone;
    int postalCode;
    int duration;
    QString dateAppointment;
    int priorityAppointment;
    QString comment;

    vector<int> idRessources;
};

#endif // CLIENT_H
