#include "dialogmodifyemployee.h"
#include "ui_dialogmodifyemployee.h"

DialogModifyEmployee::DialogModifyEmployee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogModifyEmployee)
{
    ui->setupUi(this);

    int id = Controller_employee::selectedID;
    vector<QString> v_record = controllerEmployee.searchEmployee(id);

    ui->text_ID->setText(QString::number(id, 10));
    if(v_record.size()){
        ui->lineEdit_Lastname->setText(v_record[0]);
        ui->lineEdit_Firstname->setText(v_record[1]);
        //revoir ici
        ui->comboBox_Types->setCurrentIndex(v_record[2].toInt()-1);
    }
}

DialogModifyEmployee::~DialogModifyEmployee()
{
    delete ui;
}


void DialogModifyEmployee::on_buttonBox_accepted()
{
    int id = Controller_employee::selectedID;
    QString lastname = ui->lineEdit_Lastname->text();
    QString firstname = ui->lineEdit_Firstname->text();
    int idType = ui->comboBox_Types->currentIndex() + 1;

    if(controllerEmployee.modifyEmployee(id, lastname, firstname, idType))
    {
        QMessageBox::information(this, tr("Infomation"),tr("Operation accepted : Successfully modified the employee !"));
    }
    else
    {
        QMessageBox::critical(this, tr("Error"), tr("Fail to modify the employee !"));
    }
}

void DialogModifyEmployee::on_buttonBox_rejected()
{

}
