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
    // appeller fonction pour ajouter le client
}

void DialogAddClient::on_pushButton_clicked()
{
    ui->lineEdit_firstName->clear();
    ui->lineEdit_lastName->clear();
    ui->lineEdit_telephone->clear();
    ui->lineEdit_address->clear();
    ui->lineEdit_city->clear();
    ui->lineEdit_postalCode->clear();
}
