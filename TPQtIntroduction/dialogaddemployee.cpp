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
    ui->lineEdit_firstName->clear();
    ui->lineEdit_lastName->clear();
}

void DialogAddEmployee::on_pushButton_ok_clicked()
{
    // Call the controller employee and add employee
    if(controller_employee.addEmployee(ui->lineEdit_firstName->text(), ui->lineEdit_lastName->text(), ui->comboBoxType->currentIndex()))
    {
        accept();
    }
    else
    {
        QMessageBox::critical(this, tr("Error"), tr("The following input errors have occurred:") + " add employee");
    }
}

void DialogAddEmployee::on_pushButton_cancel_clicked()
{
    reject();
}
