#include "mainwindow.h"
#include "dialogidentification.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DialogIdentification di;
    di.exec();

    return a.exec();
}
