#include "dialogaddemployee.h"

DialogAddEmployee::DialogAddEmployee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddEmployee)
{
    ui->setupUi(this);
}

DialogAddEmployee::~DialogAddEmployee()
{
    delete ui;
}

void DialogAddEmployee::on_pushBtn_reset_clicked()
{
    ui->lineEdit_Firstname->clear();
    ui->lineEdit_Lastname->clear();
}

void DialogAddEmployee::on_pushButton_cancel_clicked()
{
    reject();
}

void DialogAddEmployee::on_pushButton_ok_clicked()
{
    // Call the controller employee and add employee
    if(controller_employee.addEmployee(ui->lineEdit_Firstname->text(), ui->lineEdit_Lastname->text(), ui->comboBox_Type->currentIndex()+1))
    {
        QMessageBox::information(this, tr("Infomation"),tr("Operation accepted : Successfully added the employee !"));
        accept();
    }
    else
    {
        QMessageBox::critical(this, tr("Error"), tr("Fail to add the employee !"));
    }
}