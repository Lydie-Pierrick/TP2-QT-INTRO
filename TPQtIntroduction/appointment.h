#ifndef APPOINTMENT_H
#define APPOINTMENT_H

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

class Appointment
{
public:
    Appointment();
private:
    time_t dateAppointment;
    unsigned int duration;
    priority priorityAppointment;
    vector<int> idRessources;
    string comment;
};

#endif // APPOINTMENT_H
