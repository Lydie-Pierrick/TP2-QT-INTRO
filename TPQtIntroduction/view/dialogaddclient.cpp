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
    // Get all the texts
    QString firstName = ui->lineEdit_firstName->text();
    QString lastName = ui->lineEdit_lastName->text();
    QString address = ui->lineEdit_address->text();
    QString city = ui->lineEdit_city->text();
    int telephone = ui->lineEdit_telephone->text().toInt();
    int postalCode = ui->lineEdit_postalCode->text().toInt();
    int duration = ui->lineEdit_duration->text().toInt();
    QDate dateAppointment = ui->dateEdit->date();
    int priorityAppointment = ui->comboBox_priority->currentText().toInt();
    QString comment = ui->textEdit->toPlainText();

    // Call the controller employee and add employee
    if(controller_client.addClient(firstName, lastName, telephone, address, city, postalCode,
                                   duration, dateAppointment, priorityAppointment, comment))
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
