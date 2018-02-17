#ifndef CONTROLLER_CLIENT_H
#define CONTROLLER_CLIENT_H

#include <QString>
#include "client.h"

class Controller_client
{
public:
    Controller_client();
    bool addClient(QString firstname, QString lastname, QString telephone, QString address, QString city, QString postalCode);
};

#endif // CONTROLLER_CLIENT_H
