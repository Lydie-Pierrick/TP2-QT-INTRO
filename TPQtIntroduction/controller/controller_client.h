#ifndef CONTROLLER_CLIENT_H
#define CONTROLLER_CLIENT_H

#include <QString>
#include <QDate>
#include "model/client.h"
#include "dao/dao_client.h"

class Controller_client
{
private:
    DAO_Client daoClient;
public:
    Controller_client();
    Client getClient(map<QString, QString> m_attributesClient);
    bool addClient(QString firstname, QString lastname, int telephone,
                   QString address, QString city, int postalCode, int duration,
                   QDate dateAppointment, int priorityAppointment, QString comment);
    Client searchClientById(int id);
    vector<Client> searchClientsByName(QString name);
    vector<Client> searchClientsByDate(QDate date);
    vector<Client> getAllClients();

};

#endif // CONTROLLER_CLIENT_H
