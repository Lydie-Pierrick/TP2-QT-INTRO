#include "dialogidentification.h"
#include "controller/controller_employee.h"

DialogIdentification::DialogIdentification(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogIdentification)
{
    ui->setupUi(this);
    setFixedSize(this->width(), this->height());
    ui->lineEdit_Username->setText("Admin");
    ui->lineEdit_Password->setText("Password");
}

DialogIdentification::~DialogIdentification()
{
    delete ui;
}

void DialogIdentification::on_pushBtn_Cancel_clicked()
{
    reject();
}

void DialogIdentification::on_pushBtn_Login_clicked()
{
    checkLogin(ui->lineEdit_Username->text(), ui->lineEdit_Password->text());
}

void DialogIdentification::checkLogin(QString username, QString password)
{    
    if(controllerEmployee.checkLogin(username, password))
    {
        accept();
    }
    else
    {
        ui->lineEdit_Password->clear();
        QMessageBox::warning(this, tr("Error"), tr("The following input errors have occurred:") + " Login or password incorrect");;
    }
}
