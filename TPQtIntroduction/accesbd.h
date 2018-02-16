#ifndef ACCESBD_H
#define ACCESBD_H

#include <stdlib.h>
#include <iostream>
#include <QString>
#include <QSqlDatabase>
#include <QDebug>

class AccesBD
{
public:
    AccesBD(const QString path);
private:
    QSqlDatabase m_db;
};

#endif // ACCESBD_H
