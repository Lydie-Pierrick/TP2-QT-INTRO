#ifndef DAO_CLIENT_H
#define DAO_CLIENT_H
#include "singletondb.h"
#include <QDate>

class DAO_Client
{
public:
    DAO_Client();
    bool addClient(QString firstname, QString lastname, int telephone,
                   QString address, QString city, int postalCode, int duration,
                   QDate dateAppointment, int priorityAppointment, QString comment, vector<int> idsRes);
    vector<map<QString, QString> > searchClientById(int id);
    vector<map<QString, QString> > searchClientsByName(QString name);
    vector<map<QString, QString> > searchClientsByDate(QDate date);
    vector<map<QString, QString> > getAllClients();
    bool deleteClient(int id);
    bool modifyClient(int id, QString firstname, QString lastname, int telephone,
                      QString address, QString city, int postalCode, int duration,
                      QDate dateAppointment, int priorityAppointment, QString comment, vector<int> idsRes);
    bool addRessources(int idClient, vector<int> idRessources);
    bool modifyRessources(int idClient, vector<int> idRessources);
    vector<int> searchRessourcesID(int idClient);
private:
    QSqlDatabase db;
    map<QString, QString> collectInfosClient(QSqlQuery sqlQuery);
};

#endif // DAO_CLIENT_H
