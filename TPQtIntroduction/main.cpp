#include "view/mainwindow.h"
#include "c_init_bd.h"
#include <map>
#include <iostream>
#include <string>
using namespace std;

int Controller_employee::selectedID = 0;
int Controller_client::selectedID = 0;
int Controller_client::resNumber = 0;
int DAO_Client::counter_insert = 0;
int DAO_Employee::counter_insert = 0;
vector<int> Controller_client::idsRes;

int main(int argc, char *argv[])
{

    QFile file("./base_tmp.sqli");
    if(! file.exists())
    {
        // Initialiser BD
        C_INIT_BD::Creation_BD();
    }

    QApplication a(argc, argv);

    DialogIdentification di;
    MainWindow mainWindow;
    if(di.exec() == QDialog::Accepted) {
        mainWindow.show();
    }
    else {
        return 0;
    }

    // TP note
    multimap<int, string> map;
    multimap<int, string>::iterator it;
    map.insert(pair<int, string>(1, "titi"));
    map.insert(pair<int, string>(4, "toto"));
    map.insert(pair<int, string>(3, "tutu"));
    map.insert(pair<int, string>(4, "tata"));
    map.erase(3);
    map.insert(pair<int, string>(0, "tete"));

    for(it = map.begin(); it != map.end(); it ++)
    {
        cout<<(*it).second<<endl;
    }

    return a.exec();
}
