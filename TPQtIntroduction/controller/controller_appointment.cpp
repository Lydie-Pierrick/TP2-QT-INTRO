#include "controller_appointment.h"

Controller_Appointment::Controller_Appointment()
{
    clients = controllerClient.getAllClients();

    for(unsigned int i = 0; i < clients.size(); i ++)
    {
        Client client = clients[i];
        int priority = client.getPriorityAppointment();


    }
}
