#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QString>

using namespace std;

class Employee
{
public:
    Employee();
    Employee(int id, QString lastname, QString fisrtname, QString type, QString username, QString password);
    int getId() const;
    void setId(int value);

    QString getLastname() const;
    void setLastname(const QString &value);

    QString getFirstname() const;
    void setFirstname(const QString &value);

    QString getType() const;
    void setType(QString value);

    QString getUsername() const;
    void setUsername(const QString &value);

    QString getPassword() const;
    void setPassword(const QString &value);

private:
    int id;
    QString lastname;
    QString firstname;
    QString type;
    QString username;
    QString password;
};

#endif // EMPLOYEE_H
