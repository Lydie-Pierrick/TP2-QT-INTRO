#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <vector>
#include "appointment.h"



class Client
{
public:
    Client();

private:
    string lastname;
    string firstname;
    string address;
    string city;
    unsigned int telephone;
    unsigned int postalCode;
    vector<Appointment> appointment;
};


#endif // CLIENT_H
