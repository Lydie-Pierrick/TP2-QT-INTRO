#include "controller_client.h"

Controller_client::Controller_client()
{

}

bool Controller_client::addClient(QString firstname, QString lastname, int telephone,
                                  QString address, QString city, int postalCode, int duration,
                                  QDate dateAppointment, int priorityAppointment, QString comment)
{
    return dao_Client.addClient(firstname, lastname, telephone, address, city, postalCode,
                                duration, dateAppointment, priorityAppointment, comment);
}

Client Controller_client::searchClientById(int id)
{
    map<QString,QString> m_attributsClient = dao_Client.searchClientById(id);

    Client client = Client(m_attributsClient["firstname"], m_attributsClient["lastname"],
            m_attributsClient["telephone"].toInt(), m_attributsClient["address"], m_attributsClient["city"],
            m_attributsClient["postalCode"].toInt(), m_attributsClient["duration"].toInt(),
            m_attributsClient["date"], m_attributsClient["priority"].toInt(), m_attributsClient["comment"]);

    return client;
}
