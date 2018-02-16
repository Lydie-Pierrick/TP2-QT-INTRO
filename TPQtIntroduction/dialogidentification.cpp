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
    close();
}

void DialogIdentification::on_pushBtn_Login_clicked()
{
    checkLogin(ui->lineEdit_Username->text(), ui->lineEdit_Password->text());
}

// On doit mettre dans un autre Cpp pour séparer de la vue
void DialogIdentification::checkLogin(QString username, QString password)
{    
    QMessageBox messageBox;

    messageBox.setText("Login or password incorrect!");
    messageBox.setWindowTitle("Error");

    Controller_employee controllerEmployee;

    if(controllerEmployee.checkLogin(username, password))
    {
        accept();
    }
    else
    {
        ui->lineEdit_Password->clear();
        messageBox.exec();
    }
}
