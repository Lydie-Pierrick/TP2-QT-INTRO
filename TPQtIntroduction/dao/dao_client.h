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
                   QDate dateAppointment, int priorityAppointment, QString comment);
    map<QString, QString> searchClientById(int id);
    bool searchClientExistById(int id);
    vector<map<QString, QString> > searchClientsByName(QString name);
    vector<map<QString, QString> > searchClientsByDate(QDate date);
    vector<map<QString, QString> > getAllClients();
    bool deleteClient(int id);
private:
    QSqlDatabase db;
    map<QString, QString> collectInfosClient(QSqlQuery sqlQuery);
};

#endif // DAO_CLIENT_H
