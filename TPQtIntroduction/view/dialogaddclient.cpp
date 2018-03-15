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
    ui->lineEdit_duration->clear();
    ui->comboBox_priority->setCurrentIndex(0);
    ui->textEdit->clear();
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
    if(colorBoderFail() && controller_client.addClient(firstName, lastName, telephone, address, city, postalCode,
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

bool DialogAddClient::colorBoderFail()
{
    bool noEmptyField = true;
    if(ui->lineEdit_firstName->text().isEmpty())
    {
        ui->lineEdit_firstName->setStyleSheet("border: 1px solid red");
        noEmptyField = false;
    }
    else
        ui->lineEdit_firstName->setStyleSheet("");
    if(ui->lineEdit_lastName->text().isEmpty())
    {
        ui->lineEdit_lastName->setStyleSheet("border: 1px solid red");
        noEmptyField = false;
    }
    else
        ui->lineEdit_lastName->setStyleSheet("");
    if(ui->lineEdit_address->text().isEmpty())
    {
        ui->lineEdit_address->setStyleSheet("border: 1px solid red");
        noEmptyField = false;
    }
    else
        ui->lineEdit_address->setStyleSheet("");
    if(ui->lineEdit_address->text().isEmpty())
    {
        ui->lineEdit_address->setStyleSheet("border: 1px solid red");
        noEmptyField = false;
    }
    else
        ui->lineEdit_address->setStyleSheet("");
    if(ui->lineEdit_city->text().isEmpty())
    {
        ui->lineEdit_city->setStyleSheet("border: 1px solid red");
        noEmptyField = false;
    }
    else
        ui->lineEdit_city->setStyleSheet("");
    if(ui->lineEdit_postalCode->text().isEmpty())
    {
        ui->lineEdit_postalCode->setStyleSheet("border: 1px solid red");
        noEmptyField = false;
    }
    else
        ui->lineEdit_postalCode->setStyleSheet("");
    if(ui->lineEdit_duration->text().isEmpty())
    {
        ui->lineEdit_duration->setStyleSheet("border: 1px solid red");
        noEmptyField = false;
    }
    else
        ui->lineEdit_duration->setStyleSheet("");

    return noEmptyField;
}

void DialogAddClient::on_pushBtn_choose_clicked()
{
    DialogChooseRessource dcr;
    dcr.exec();
}
