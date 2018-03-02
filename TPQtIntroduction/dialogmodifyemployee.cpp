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
    int idType = ui->comboBox_Types->currentIndex();
    controllerEmployee.modifyEmployee(id, lastname, firstname, idType);
}

void DialogModifyEmployee::on_buttonBox_rejected()
{

}
