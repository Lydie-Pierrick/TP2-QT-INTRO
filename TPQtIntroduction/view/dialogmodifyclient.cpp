#include "dialogmodifyclient.h"

// Constructor
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
        ui->text_ID->setText(QString::number(id));
        ui->lineEdit_lastname->setText(client.getLastName());
        ui->lineEdit_firstname->setText(client.getFirstName());
        ui->lineEdit_telephone->setText(QString::number(client.getTelephone()));
        ui->lineEdit_address->setText(client.getAddress());
        ui->lineEdit_city->setText(client.getCity());
        ui->lineEdit_postalCode->setText(QString::number(client.getPostalCode()));
        ui->dateEdit->setDate(client.getDateAppointment());
        ui->lineEdit_duration->setText(QString::number(client.getDuration()));
        ui->comboBox_priority->setCurrentText(QString::number(client.getPriorityAppointment()));
        ui->textEdit->setPlainText(client.getComment());
    }

    Controller_client::idsRes = controllerClient.searchRessourcesID(id);
    Controller_client::resNumber = Controller_client::idsRes.size();
    ui->label_status->setText(QString::number(Controller_client::resNumber) + " ressources choosen.");

    // Set label color
    QPalette palette;
    palette.setColor(QPalette::WindowText, Qt::red);
    ui->label_required->setPalette(palette);
}

// Destructor
DialogModifyClient::~DialogModifyClient()
{
    delete ui;
}

// When the user comfirm. Treatment of client data.
void DialogModifyClient::on_pushButton_ok_clicked()
{
    // Get all the texts
    QString firstName = ui->lineEdit_firstname->text();
    if (!firstName.isEmpty())
        firstName[0] = firstName[0].toUpper();
    QString lastName = ui->lineEdit_lastname->text();
    if (!lastName.isEmpty())
        lastName[0] = lastName[0].toUpper();
    QString city = ui->lineEdit_city->text();
    if (!city.isEmpty())
        city[0] = city[0].toUpper();

    if(colorBoderFail() && controllerClient.modifyClient(Controller_client::selectedID, firstName, lastName, ui->lineEdit_telephone->text().toInt(), ui->lineEdit_address->text(), city, ui->lineEdit_postalCode->text().toInt(), ui->lineEdit_duration->text().toInt(), ui->dateEdit->date(), ui->comboBox_priority->currentText().toInt(), ui->textEdit->toPlainText(), Controller_client::idsRes))
    {
        accept();
        QMessageBox::information(this, tr("Infomation"),tr("Operation accepted : Successfully modified the client !"));
    }
    else
    {
        QMessageBox::critical(this, tr("Error"), tr("Fail to modify the client !"));
    }
}

// When the user want to cancel his action
void DialogModifyClient::on_pushButton_cancel_clicked()
{
    reject();
}

// When the user want to reset all fields
void DialogModifyClient::on_pushButton_reset_clicked()
{
    ui->lineEdit_firstname->clear();
    ui->lineEdit_lastname->clear();
    ui->lineEdit_telephone->clear();
    ui->lineEdit_address->clear();
    ui->lineEdit_city->clear();
    ui->lineEdit_postalCode->clear();
    ui->lineEdit_duration->clear();
    ui->dateEdit->setDate(QDate::currentDate());
    ui->comboBox_priority->setCurrentIndex(0);
    ui->textEdit->clear();
}

// It's for color the field border when it's wrong
bool DialogModifyClient::colorBoderFail()
{
    bool noEmptyField = true;
    if(ui->lineEdit_firstname->text().isEmpty())
    {
        ui->lineEdit_firstname->setStyleSheet("border: 1px solid red");
        noEmptyField = false;
    }
    else
        ui->lineEdit_firstname->setStyleSheet("");
    if(ui->lineEdit_lastname->text().isEmpty())
    {
        ui->lineEdit_lastname->setStyleSheet("border: 1px solid red");
        noEmptyField = false;
    }
    else
        ui->lineEdit_lastname->setStyleSheet("");
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
    if(!ui->lineEdit_telephone->text().isEmpty() && (QString::number(ui->lineEdit_telephone->text().toInt()) == "0"))
    {
        ui->lineEdit_telephone->setStyleSheet("border: 1px solid red");
        noEmptyField = false;
    }
    else
        ui->lineEdit_telephone->setStyleSheet("");
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
    if(ui->label_status->text() == "0 ressources choosen.")
    {
        ui->label_status->setStyleSheet("border: 1px solid red");
        noEmptyField = false;
    }
    else
        ui->label_status->setStyleSheet("");

    return noEmptyField;
}

// It's a button to open a new windows for the ressource selection
void DialogModifyClient::on_pushBtn_choose_clicked()
{
    DialogChooseRessource dcr;

    if(dcr.exec() == QDialog::Accepted)
        ui->label_status->setText(QString::number(Controller_client::resNumber) + " ressources choosen.");
}
