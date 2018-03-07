#include "dialogmodifyemployee.h"
#include "ui_dialogmodifyemployee.h"

DialogModifyEmployee::DialogModifyEmployee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogModifyEmployee)
{
    ui->setupUi(this);

    int id = Controller_employee::selectedID;
    int index = -1;
    Employee v_record = controllerEmployee.searchEmployee(id);



    ui->text_ID->setText(QString::number(id, 10));
    ui->lineEdit_Lastname->setText(v_record.getLastname());
    ui->lineEdit_Firstname->setText(v_record.getFirstname());

    index = ui->comboBox_Types->findText(v_record.getType());
    ui->comboBox_Types->setCurrentIndex(index);
}

DialogModifyEmployee::~DialogModifyEmployee()
{
    delete ui;
}

void DialogModifyEmployee::on_pushButton_ok_clicked()
{
    int id = Controller_employee::selectedID;
    QString lastname = ui->lineEdit_Lastname->text();
    QString firstname = ui->lineEdit_Firstname->text();
    int idType = ui->comboBox_Types->currentIndex() + 1;

    if(controllerEmployee.modifyEmployee(id, lastname, firstname, idType))
    {
        QMessageBox::information(this, tr("Infomation"),tr("Operation accepted : Successfully modified the employee !"));
        accept();
    }
    else
    {
        QMessageBox::critical(this, tr("Error"), tr("Fail to modify the employee !"));
    }
}

void DialogModifyEmployee::on_pushButton_cancel_clicked()
{
    reject();
}
