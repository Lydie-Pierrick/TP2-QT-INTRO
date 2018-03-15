#include "dialogmodifyemployee.h"

DialogModifyEmployee::DialogModifyEmployee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogModifyEmployee)
{
    ui->setupUi(this);

    int id = Controller_employee::selectedID;
    Employee e = controllerEmployee.searchEmployee(id);

    ui->text_ID->setText(QString::number(id, 10));
    ui->lineEdit_Lastname->setText(e.getLastname());
    ui->lineEdit_Firstname->setText(e.getFirstname());;

    // All types
    vector<map<QString, QString> > v_types = controllerEmployee.getAllTypes();

    for(unsigned int i = 0; i < v_types.size(); i++)
    {
        ui->comboBox_Type->setItemText(i, v_types[i]["label"]);
    }

    ui->comboBox_Type->setCurrentText(e.getType());

    if(e.getType() == "Computer Scientist")
    {
        ui->label_OnlyIT->setEnabled(true);
        ui->lineEdit_Username->setEnabled(true);
        ui->lineEdit_Password->setEnabled(true);

        ui->lineEdit_Username->setText(e.getUsername());
        ui->lineEdit_Password->setText(e.getPassword());
    }
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
    int idType = ui->comboBox_Type->currentIndex() + 1;
    QString username = ui->lineEdit_Username->text();
    QString password = ui->lineEdit_Password->text();

    if(colorBoderFail() && controllerEmployee.modifyEmployee(id, lastname, firstname, idType, username, password))
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

void DialogModifyEmployee::on_comboBox_Type_activated(const QString &arg1)
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

bool DialogModifyEmployee::colorBoderFail()
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
