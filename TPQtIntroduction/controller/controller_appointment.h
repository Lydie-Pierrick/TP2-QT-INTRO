#ifndef CONTROLLERAPPOINTMENT_H
#define CONTROLLERAPPOINTMENT_H

#include <model/client.h>
#include <controller/controller_client.h>

class Controller_Appointment
{
public:
    Controller_Appointment();
private:
    vector<Client> clients;
    Controller_client controllerClient;
};

#endif // CONTROLLERAPPOINTMENT_H
