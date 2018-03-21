#ifndef CONTROLLER_CLIENT_H
#define CONTROLLER_CLIENT_H

#include <QString>
#include <QDate>
#include "model/client.h"
#include "dao/dao_client.h"

using namespace std;

class Controller_client
{
private:
    DAO_Client daoClient;
public:
    static int selectedID;
    static int resNumber;
    static vector<int> idsRes;
    Controller_client();
    Client getClient(map<QString, QString> m_attributesClient);
    bool addClient(QString firstname, QString lastname, int telephone,
                   QString address, QString city, int postalCode, int duration,
                   QDate dateAppointment, int priorityAppointment, QString comment, vector<int> idsRes);
    vector<Client> searchClientById(int id);
    vector<Client> searchClientsByName(QString name);
    vector<Client> searchClientsByDate(QDate dateFrom, QDate dateTo);
    vector<Client> getAllClients();
    bool deleteClient(int id);
    bool modifyClient(int id, QString firstname, QString lastname, int telephone,
                      QString address, QString city, int postalCode, int duration,
                      QDate dateAppointment, int priorityAppointment, QString comment, vector<int> idsRes);
    bool addRessources(int idClient, vector<int> idsRessources);
    vector<int> searchRessourcesID(int idClient);
};

#endif // CONTROLLER_CLIENT_H
