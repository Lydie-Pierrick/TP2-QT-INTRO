#include "controller_client.h"

Controller_client::Controller_client()
{

}

bool Controller_client::addClient(QString firstname, QString lastname, QString telephone,
                                  QString address, QString city, QString postalCode, QString duration,
                                  QString dateAppointment, QString priorityAppointment, QString comment)
{
    string str_lastname = lastname.toStdString();
    string str_firstname = firstname.toStdString();
    string str_address = address.toStdString();
    string str_city = city.toStdString();
    unsigned int int_telephone = telephone.toInt();
    unsigned int int_postalCode = postalCode.toInt();
    unsigned int int_duration = duration.toInt();
    //time_t time_dateApp = dateAppointment;
    unsigned int int_priorityApp = priorityAppointment.toInt();
    string str_comment = comment.toStdString();
    cout << "test add Client" << endl;

    return true;
}
