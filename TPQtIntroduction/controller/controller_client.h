#ifndef CONTROLLER_CLIENT_H
#define CONTROLLER_CLIENT_H

#include <QString>
#include <QDate>
#include "model/client.h"
#include "dao/dao_client.h"

class Controller_client
{
private:
    DAO_Client dao_Client;
public:
    Controller_client();
    bool addClient(QString firstname, QString lastname, int telephone,
                   QString address, QString city, int postalCode, int duration,
                   QDate dateAppointment, int priorityAppointment, QString comment);
    Client searchClientById(int id);
    //bool searchClient(QString firstname);
    //bool searchClient(QString lastname);
    //bool searchClient(QString dateAppointment);
};

#endif // CONTROLLER_CLIENT_H
