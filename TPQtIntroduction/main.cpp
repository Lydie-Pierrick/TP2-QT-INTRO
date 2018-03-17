#include "view/mainwindow.h"
#include "c_init_bd.h"

int Controller_employee::selectedID = 0;
int Controller_client::selectedID = 0;
int Controller_client::resNumber = 0;
bool Controller_client::windowChooseOpen = false;
bool Controller_client::firstChooseOpen = true;
vector<int> Controller_client::idsRes;

int main(int argc, char *argv[])
{
    // Initialiser BD
    //C_INIT_BD::Creation_BD();

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
