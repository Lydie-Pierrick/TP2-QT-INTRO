#include "dialogaddemployee.h"

DialogAddEmployee::DialogAddEmployee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddEmployee)
{
    ui->setupUi(this);

    vector<map<QString, QString>> v_types = controllerEmployee.getAllTypes();

    for(int i = 0; i < v_types.size(); i++)
    {
        ui->comboBox_Type->setItemText(i, v_types[i]["label"]);
    }
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

bool DialogAddEmployee::colorBoderFail()
{
    bool noEmptyField = true;
    if(ui->lineEdit_Firstname->text().isEmpty())
    {
        ui->lineEdit_Firstname->setStyleSheet("border: 1px solid red");
        noEmptyField = false;
    }
    else
        ui->lineEdit_Firstname->setStyleSheet("");
    if(ui->lineEdit_Lastname->text().isEmpty())
    {
        ui->lineEdit_Lastname->setStyleSheet("border: 1px solid red");
        noEmptyField = false;
    }
    else
        ui->lineEdit_Lastname->setStyleSheet("");
    if(ui->lineEdit_Username->text().isEmpty() && ui->lineEdit_Username->isEnabled())
    {
        ui->lineEdit_Username->setStyleSheet("border: 1px solid red" );
        noEmptyField = false;
    }
    else
        ui->lineEdit_Username->setStyleSheet("");
    if(ui->lineEdit_Password->text().isEmpty() && ui->lineEdit_Password->isEnabled())
    {
        ui->lineEdit_Password->setStyleSheet("border: 1px solid red");
        noEmptyField = false;
    }
    else
        ui->lineEdit_Password->setStyleSheet("");

    return noEmptyField;
}

void DialogAddEmployee::on_pushButton_ok_clicked()
{
    // Call the controller employee and add employee
    if(colorBoderFail() && controllerEmployee.addEmployee(ui->lineEdit_Firstname->text(), ui->lineEdit_Lastname->text(), ui->comboBox_Type->currentIndex()+1, ui->lineEdit_Username->text(), ui->lineEdit_Password->text()))
    {
        QMessageBox::information(this, tr("Infomation"),tr("Operation accepted : Successfully added the employee !"));
        accept();
    }
    else
    {
        QMessageBox::critical(this, tr("Error"), tr("Fail to add the employee !"));
    }
}

void DialogAddEmployee::on_comboBox_Type_activated(const QString &arg1)
{
    if(arg1 == "Computer Scientist")
    {
        ui->label_Username->setEnabled(true);
        ui->lineEdit_Username->setEnabled(true);
        ui->label_Password->setEnabled(true);
        ui->lineEdit_Password->setEnabled(true);
    }
    else
    {
        ui->label_Username->setEnabled(false);
        ui->lineEdit_Username->setEnabled(false);
        ui->label_Password->setEnabled(false);
        ui->lineEdit_Password->setEnabled(false);
    }
}
