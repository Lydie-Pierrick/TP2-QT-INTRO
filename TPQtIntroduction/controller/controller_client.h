#ifndef CONTROLLER_CLIENT_H
#define CONTROLLER_CLIENT_H

#include <QString>
#include "model/client.h"

class Controller_client
{
public:
    Controller_client();
    bool addClient(QString firstname, QString lastname, QString telephone,
                   QString address, QString city, QString postalCode, QString duration,
                   QString dateAppointment, QString priorityAppointment,QString comment);
    bool searchClient(int id);
    //bool searchClient(QString firstname);
    //bool searchClient(QString lastname);
    //bool searchClient(QString dateAppointment);
};

#endif // CONTROLLER_CLIENT_H
