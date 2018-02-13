#include "dialogaddclient.h"
#include "ui_dialogaddclient.h"

DialogAddClient::DialogAddClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddClient)
{
    ui->setupUi(this);
}

DialogAddClient::~DialogAddClient()
{
    delete ui;
}


void DialogAddClient::on_buttonBox_accepted()
{
    std::cout << "Add Client" << endl;
}
