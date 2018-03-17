#include "dialogaddclient.h"

DialogAddClient::DialogAddClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddClient)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());

    Controller_client::idsRes.clear();
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
    ui->dateEdit->setDate(QDate::currentDate());
}

void DialogAddClient::on_pushButton_ok_clicked()
{
    // Get all the texts
    QString firstName = ui->lineEdit_firstName->text();
    if (!firstName.isEmpty())
        firstName[0] = firstName[0].toUpper();
    QString lastName = ui->lineEdit_lastName->text();
    if (!lastName.isEmpty())
        lastName[0] = lastName[0].toUpper();
    QString address = ui->lineEdit_address->text();
    QString city = ui->lineEdit_city->text();
    if (!city.isEmpty())
        city[0] = city[0].toUpper();
    int telephone = ui->lineEdit_telephone->text().toInt();
    int postalCode = ui->lineEdit_postalCode->text().toInt();
    int duration = ui->lineEdit_duration->text().toInt();
    QDate dateAppointment = ui->dateEdit->date();
    int priorityAppointment = ui->comboBox_priority->currentText().toInt();
    QString comment = ui->textEdit->toPlainText();

    // Call the controller client and add client
    if(colorBoderFail()
            && controller_client.addClient(firstName, lastName, telephone, address, city, postalCode,
                                   duration, dateAppointment, priorityAppointment, comment, Controller_client::idsRes))
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
    if(ui->lineEdit_postalCode->text().isEmpty() || (QString::number(ui->lineEdit_postalCode->text().toInt()) == "0"))
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
    if(ui->dateEdit->date() < QDate::currentDate())
    {
        ui->dateEdit->setStyleSheet("border: 1px solid red");
        noEmptyField = false;
    }
    else
        ui->dateEdit->setStyleSheet("");
    if(ui->label_status->text() == "0 ressources choosen.")
    {
        ui->label_status->setStyleSheet("border: 1px solid red");
        noEmptyField = false;
    }
    else
        ui->label_status->setStyleSheet("");

    return noEmptyField;
}

void DialogAddClient::on_pushBtn_choose_clicked()
{
    DialogChooseRessource dcr;
    if(dcr.exec() == QDialog::Accepted)
    {
        qDebug()<<Controller_client::resNumber;
        ui->label_status->setText(QString::number(Controller_client::resNumber) + " ressources choosen.");
    }
}
