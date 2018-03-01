#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <ctime>
#include <vector>
#include <string>
using namespace std;

enum priority{
    priority1=1,
    priority2=2,
    priority3=3,
    priority4=4,
    priority5=5
};

class Client
{
public:
    Client();

private:
    string lastName;
    string firstName;
    string address;
    string city;
    unsigned int telephone;
    unsigned int postalCode;
    unsigned int duration;
    time_t dateAppointment;
    priority priorityAppointment;
    vector<int> idRessources;
    string comment;
};

#endif // CLIENT_H
