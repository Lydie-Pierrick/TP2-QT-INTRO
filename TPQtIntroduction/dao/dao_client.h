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
private:
    QSqlDatabase db = SingletonDB::getInstance();
};

#endif // DAO_CLIENT_H
