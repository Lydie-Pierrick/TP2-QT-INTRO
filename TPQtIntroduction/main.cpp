#include "mainwindow.h"
#include "dialogidentification.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DialogIdentification di;
    MainWindow mainWindow;
    if(di.exec() == QDialog::Accepted){
        mainWindow.show();
    }

    return a.exec();
}
