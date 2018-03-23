#include "dialogothers.h"
#include "ui_dialogothers.h"

DialogOthers::DialogOthers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogOthers)
{
    ui->setupUi(this);
}

DialogOthers::~DialogOthers()
{
    delete ui;
}

void DialogOthers::on_pushButton_Ok_clicked()
{
    // Get all the texts
    QString firstName = ui->lineEdit_firstname->text();
    if (!firstName.isEmpty())
        firstName[0] = firstName[0].toUpper();
    QString lastName = ui->lineEdit_name->text();
    if (!lastName.isEmpty())
        lastName[0] = lastName[0].toUpper();

    // Call the controller employee and add employee
    if(controllerEmployee.addEmployeeOther(firstName, lastName))
    {
        QMessageBox::information(this, tr("Infomation"),tr("Operation accepted : Successfully added the other employee !"));
        accept();
    }
    else
    {
        QMessageBox::critical(this, tr("Error"), tr("Fail to add the other employee !"));
    }
}

void DialogOthers::on_pushButton_Cancel_clicked()
{
    reject();
}
