#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <QString>
#include <QDate>

using namespace std;

class Client
{
public:
    Client();
    Client(int id, QString firstname, QString lastname, int telephone,
            QString address, QString city, int postalCode, int duration,
            QDate dateAppointment, int priorityAppointment, QString comment);


    void setLastName(const QString &value);
    QString getLastName() const;
    void setFirstName(const QString &value);
    QString getFirstName() const;
    void setAddress(const QString &value);
    QString getAddress() const;
    void setCity(const QString &value);
    QString getCity() const;
    void setTelephone(int value);
    int getTelephone() const;
    void setPostalCode(int value);
    int getPostalCode() const;
    void setDuration(int value);
    int getDuration() const;
    void setDateAppointment(const QDate &value);
    QDate getDateAppointment() const;
    void setPriorityAppointment(int value);
    int getPriorityAppointment() const;
    void setComment(const QString &value);
    QString getComment() const;
    void setId(int value);
    int getId() const;

private:
    int id;
    QString lastName;
    QString firstName;
    QString address;
    QString city;
    int telephone;
    int postalCode;
    int duration;
    QDate dateAppointment;
    int priorityAppointment;
    QString comment;

    vector<int> idRessources;
};

#endif // CLIENT_H
