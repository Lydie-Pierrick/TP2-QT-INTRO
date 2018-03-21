#include "controller_client.h"

// Constructor
Controller_client::Controller_client()
{

}

// Get infos of clients
Client Controller_client::getClient(map<QString, QString> m_attributesClient)
{
    Client client = Client(m_attributesClient["id"].toInt(),m_attributesClient["firstname"], m_attributesClient["lastname"],
            m_attributesClient["telephone"].toInt(), m_attributesClient["address"], m_attributesClient["city"],
            m_attributesClient["postalCode"].toInt(), m_attributesClient["duration"].toInt(),
            QDate::fromString(m_attributesClient["date"], "yyyy-MM-dd"), m_attributesClient["priority"].toInt(), m_attributesClient["comment"]);
    client.setIdRessources(daoClient.searchRessourcesID(client.getId()));
    return client;
}

// Add a client
bool Controller_client::addClient(QString firstname, QString lastname, int telephone,
                                  QString address, QString city, int postalCode, int duration,
                                  QDate dateAppointment, int priorityAppointment, QString comment,
                                  vector<int> idsRes)
{
    return daoClient.addClient(firstname, lastname, telephone, address, city, postalCode,
                                duration, dateAppointment, priorityAppointment, comment, idsRes);
}

// Search client by ID
vector<Client> Controller_client::searchClientById(int id)
{
    vector<map<QString, QString> > v_m_attributesClients = daoClient.searchClientById(id);
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

// Search clients by name
vector<Client> Controller_client::searchClientsByName(QString name)
{
    vector<map<QString, QString> > v_m_attributesClients = daoClient.searchClientsByName(name);
    map<QString, QString> m_attributesClient;
    vector<Client> v_clients;

    for (unsigned int i = 0; i < v_m_attributesClients.size(); i++)
    {
        m_attributesClient = v_m_attributesClients[i];
        Client client = getClient(m_attributesClient);
        // Add client into the vector
        v_clients.push_back(client);
    }

    return v_clients;
}

// Search clients by date
vector<Client> Controller_client::searchClientsByDate(QDate dateFrom, QDate dateTo)
{
    vector<map<QString, QString> > v_m_attributesClients = daoClient.searchClientsByDate(dateFrom, dateTo);
    map<QString, QString> m_attributesClient;
    vector<Client> v_clients;

    for (unsigned int i = 0; i < v_m_attributesClients.size(); i++)
    {
        m_attributesClient = v_m_attributesClients[i];
        Client client = getClient(m_attributesClient);
        // Add client into the vector
        v_clients.push_back(client);
    }

    return v_clients;
}

// Get all clients
vector<Client> Controller_client::getAllClients()
{
    vector<map<QString, QString> > v_m_attributesClients = daoClient.getAllClients();
    map<QString, QString> m_attributesClient;
    vector<Client> v_clients;

    for (unsigned int i = 0; i < v_m_attributesClients.size(); i++)
    {
        m_attributesClient = v_m_attributesClients[i];
        Client client = getClient(m_attributesClient);
        // Add client into the vector
        v_clients.push_back(client);
    }

    return v_clients;
}

// Delete a client
bool Controller_client::deleteClient(int id)
{
    return daoClient.deleteClient(id);
}

// Modify a client
bool Controller_client::modifyClient(int id, QString firstname, QString lastname, int telephone,
                                     QString address, QString city, int postalCode, int duration,
                                     QDate dateAppointment, int priorityAppointment, QString comment,
                                     vector<int> idsRes)
{
    return daoClient.modifyClient(id, firstname, lastname, telephone, address, city,  postalCode,
                                  duration, dateAppointment, priorityAppointment, comment, idsRes);
}

// Add ressources to a client
bool Controller_client::addRessources(int idClient, vector<int> idsRessources)
{
    return daoClient.addRessources(idClient, idsRessources);
}

// Search ressources ID by client
vector<int> Controller_client::searchRessourcesID(int idClient)
{
    return daoClient.searchRessourcesID(idClient);
}
