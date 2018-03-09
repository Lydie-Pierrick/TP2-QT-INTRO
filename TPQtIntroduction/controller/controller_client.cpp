#include "controller_client.h"

Controller_client::Controller_client()
{

}

bool Controller_client::addClient(QString firstname, QString lastname, int telephone,
                                  QString address, QString city, int postalCode, int duration,
                                  QDate dateAppointment, int priorityAppointment, QString comment)
{
    return daoClient.addClient(firstname, lastname, telephone, address, city, postalCode,
                                duration, dateAppointment, priorityAppointment, comment);
}

Client Controller_client::searchClientById(int id)
{
    map<QString,QString> m_attributsClient = daoClient.searchClientById(id);

    Client client = Client(m_attributsClient["firstname"], m_attributsClient["lastname"],
            m_attributsClient["telephone"].toInt(), m_attributsClient["address"], m_attributsClient["city"],
            m_attributsClient["postalCode"].toInt(), m_attributsClient["duration"].toInt(),
            QDate::fromString(m_attributsClient["date"]), m_attributsClient["priority"].toInt(), m_attributsClient["comment"]);

    return client;
}

vector<Client> Controller_client::searchClientsByName(QString name)
{
    vector<map<QString, QString>> v_m_attributsClients = daoClient.searchClientsByName(name);
    map<QString, QString> m_attributsClient;
    vector<Client> v_clients;

    for (unsigned int i = 0; i < v_m_attributsClients.size(); i++)
    {
        m_attributsClient = v_m_attributsClients[i];
        Client client = Client(m_attributsClient["firstname"], m_attributsClient["lastname"],
                    m_attributsClient["telephone"].toInt(), m_attributsClient["address"], m_attributsClient["city"],
                    m_attributsClient["postalCode"].toInt(), m_attributsClient["duration"].toInt(),
                    QDate::fromString(m_attributsClient["date"]), m_attributsClient["priority"].toInt(), m_attributsClient["comment"]);

        v_clients.push_back(client);
    }

    return v_clients;
}

vector<Client> Controller_client::searchClientsByDate(QDate date)
{
    vector<map<QString, QString>> v_m_attributsClients = daoClient.searchClientsByDate(date);
    map<QString, QString> m_attributsClient;
    vector<Client> v_clients;

    for (unsigned int i = 0; i < v_m_attributsClients.size(); i++)
    {
        m_attributsClient = v_m_attributsClients[i];
        Client client = Client(m_attributsClient["firstname"], m_attributsClient["lastname"],
                    m_attributsClient["telephone"].toInt(), m_attributsClient["address"], m_attributsClient["city"],
                    m_attributsClient["postalCode"].toInt(), m_attributsClient["duration"].toInt(),
                    QDate::fromString(m_attributsClient["date"]), m_attributsClient["priority"].toInt(), m_attributsClient["comment"]);

        v_clients.push_back(client);
    }

    return v_clients;
}
