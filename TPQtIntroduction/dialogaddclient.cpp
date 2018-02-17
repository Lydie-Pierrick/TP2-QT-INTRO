#include "dialogaddclient.h"

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

void DialogAddClient::on_pushButton_reset_clicked()
{
    ui->lineEdit_firstName->clear();
    ui->lineEdit_lastName->clear();
    ui->lineEdit_telephone->clear();
    ui->lineEdit_address->clear();
    ui->lineEdit_city->clear();
    ui->lineEdit_postalCode->clear();
}

void DialogAddClient::on_pushButton_ok_clicked()
{
    // Call the controller employee and add employee
    if(controller_client.addClient(ui->lineEdit_firstName->text(), ui->lineEdit_lastName->text(), ui->lineEdit_telephone->text(), ui->lineEdit_address->text(), ui->lineEdit_city->text(), ui->lineEdit_postalCode->text()))
    {
        accept();
    }
    else
    {
        QMessageBox::critical(this, tr("Error"), tr("The following input errors have occurred:") + " add client");
    }
}

void DialogAddClient::on_pushButton_cancel_clicked()
{
    reject();
}
