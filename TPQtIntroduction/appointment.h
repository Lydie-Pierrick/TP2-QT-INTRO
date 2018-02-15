#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <ctime>
#include <vector>
#include <string>

using namespace std;

class Appointment
{
public:
    Appointment();
private:
    time_t dateAppointment;
    unsigned int duration;
    unsigned int priority;
    vector<int> idRessources;
    string comment;
};

#endif // APPOINTMENT_H
