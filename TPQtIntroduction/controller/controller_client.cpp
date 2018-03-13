#include "controller_client.h"

Controller_client::Controller_client()
{

}

Client Controller_client::getClient(map<QString, QString> m_attributesClient)
{
    Client client = Client(m_attributesClient["id"].toInt(),m_attributesClient["firstname"], m_attributesClient["lastname"],
            m_attributesClient["telephone"].toInt(), m_attributesClient["address"], m_attributesClient["city"],
            m_attributesClient["postalCode"].toInt(), m_attributesClient["duration"].toInt(),
            QDate::fromString(m_attributesClient["date"], "yyyy-MM-dd"), m_attributesClient["priority"].toInt(), m_attributesClient["comment"]);

    return client;
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
    map<QString,QString> m_attributesClient = daoClient.searchClientById(id);

    return getClient(m_attributesClient);
}

vector<Client> Controller_client::searchClientsByName(QString name)
{
    vector<map<QString, QString>> v_m_attributesClients = daoClient.searchClientsByName(name);
    map<QString, QString> m_attributesClient;
    vector<Client> v_clients;

    for (unsigned int i = 0; i < v_m_attributesClients.size(); i++)
    {
        m_attributesClient = v_m_attributesClients[i];
        Client client = getClient(m_attributesClient);

        v_clients.push_back(client);
    }

    return v_clients;
}

vector<Client> Controller_client::searchClientsByDate(QDate date)
{
    vector<map<QString, QString>> v_m_attributesClients = daoClient.searchClientsByDate(date);
    map<QString, QString> m_attributesClient;
    vector<Client> v_clients;

    for (unsigned int i = 0; i < v_m_attributesClients.size(); i++)
    {
        m_attributesClient = v_m_attributesClients[i];
        Client client = getClient(m_attributesClient);

        v_clients.push_back(client);
    }

    return v_clients;
}

vector<Client> Controller_client::getAllClients()
{
    vector<map<QString, QString>> v_m_attributesClients = daoClient.getAllClients();
    map<QString, QString> m_attributesClient;
    vector<Client> v_clients;

    for (unsigned int i = 0; i < v_m_attributesClients.size(); i++)
    {
        m_attributesClient = v_m_attributesClients[i];
        Client client = getClient(m_attributesClient);

        v_clients.push_back(client);
    }

    return v_clients;
}

bool Controller_client::deleteClient(int id)
{
    return daoClient.deleteClient(id);
}
