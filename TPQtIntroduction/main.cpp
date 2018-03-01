#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DialogIdentification di;
    MainWindow mainWindow;

    if(di.exec() == QDialog::Accepted) {
        mainWindow.show();
    }
    else {
        return 0;
    }

    return a.exec();
}
