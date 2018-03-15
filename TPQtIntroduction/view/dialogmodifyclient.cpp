#include "dialogmodifyclient.h"
#include "ui_dialogmodifyclient.h"


DialogModifyClient::DialogModifyClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogModifyClient)
{
    ui->setupUi(this);

    int id = Controller_client::selectedID;

    vector<Client> v_clients = controllerClient.searchClientById(id);

    if(v_clients.size())
    {
        Client client = v_clients[0];
        qDebug()<<client.getLastName();
        ui->text_ID->setText(QString::number(id));
        ui->lineEdit_lastname->setText(client.getLastName());
        ui->lineEdit_firstname->setText(client.getFirstName());
        ui->lineEdit_telephone->setText(QString::number(client.getTelephone()));
        ui->lineEdit_address->setText(client.getAddress());
        ui->lineEdit_city->setText(client.getCity());
        ui->lineEdit_postalCode->setText(QString::number(client.getPostalCode()));
        ui->lineEdit_duration->setText(QString::number(client.getDuration()));
        ui->comboBox_priority->setCurrentText(QString::number(client.getPriorityAppointment()));
        ui->textEdit->setText(client.getComment());
    }
}

DialogModifyClient::~DialogModifyClient()
{
    delete ui;
}

void DialogModifyClient::on_pushButton_ok_clicked()
{
    if(controllerClient.modifyClient(Controller_client::selectedID,
                                     ui->lineEdit_firstname->text(),
                                     ui->lineEdit_lastname->text(),
                                     ui->lineEdit_telephone->text().toInt(),
                                     ui->lineEdit_address->text(),
                                     ui->lineEdit_city->text(),
                                     ui->lineEdit_postalCode->text().toInt(),
                                     ui->lineEdit_duration->text().toInt(),
                                      ui->dateEdit->date(),
                                     ui->comboBox_priority->currentText().toInt(),
                                     ui->textEdit->toPlainText()))
    {
        QMessageBox::information(this, tr("Infomation"),tr("Operation accepted : Successfully modified the client !"));
        accept();
    }
    else
    {
        QMessageBox::critical(this, tr("Error"), tr("Fail to modify the client !"));
    }
}

void DialogModifyClient::on_pushButton_cancel_clicked()
{
    reject();
}

void DialogModifyClient::on_pushButton_reset_clicked()
{
    ui->lineEdit_firstname->clear();
    ui->lineEdit_lastname->clear();
    ui->lineEdit_telephone->clear();
    ui->lineEdit_address->clear();
    ui->lineEdit_city->clear();
    ui->lineEdit_postalCode->clear();
    ui->lineEdit_duration->clear();
    ui->comboBox_priority->setCurrentIndex(0);
    ui->textEdit->clear();
}
