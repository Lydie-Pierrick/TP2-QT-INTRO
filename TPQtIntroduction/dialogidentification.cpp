#include "dialogidentification.h"
#include "controller_employee.h"

DialogIdentification::DialogIdentification(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogIdentification)
{
    ui->setupUi(this);
    setFixedSize(this->width(), this->height());
    ui->lineEdit_Username->setText("lydie");
    ui->lineEdit_Password->setText("ahah");
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

// On doit mettre dans un autre Cpp pour séparer de la vue
void DialogIdentification::checkLogin(QString username, QString password)
{    
    if(controllerEmployee.checkLogin(username, password))
    {
        accept();
    }
    else
    {
        ui->lineEdit_Password->clear();
        QMessageBox::critical(this, tr("Error"), tr("The following input errors have occurred:") + " Login or password incorrect");;
    }
}
