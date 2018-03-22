#include "dialogaddemployee.h"

// Constructor
DialogAddEmployee::DialogAddEmployee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddEmployee)
{
    ui->setupUi(this);

    vector<map<QString, QString> > v_types = controllerEmployee.getAllTypes();

    for(unsigned int i = 0; i < v_types.size(); i++)
    {
        ui->comboBox_Type->setItemText(i, v_types[i]["label"]);
    }

    // Set label color
    QPalette palette;
    palette.setColor(QPalette::WindowText, Qt::red);
    ui->label_required->setPalette(palette);
}

// Destructor
DialogAddEmployee::~DialogAddEmployee()
{
    delete ui;
}

// When the user want to reset all fields
void DialogAddEmployee::on_pushBtn_reset_clicked()
{
    ui->lineEdit_firstName->clear();
    ui->lineEdit_lastName->clear();
}

// When the user want to cancel his action
void DialogAddEmployee::on_pushButton_cancel_clicked()
{
    reject();
}

// It's for color the field border when it's wrong
bool DialogAddEmployee::colorBoderFail()
{
    bool noEmptyField = true;
    if(ui->lineEdit_firstName->text().isEmpty())
    {
        ui->lineEdit_firstName->setStyleSheet("border: 1px solid red");
        noEmptyField = false;
    }
    else
        ui->lineEdit_firstName->setStyleSheet("");
    if(ui->lineEdit_lastName->text().isEmpty())
    {
        ui->lineEdit_lastName->setStyleSheet("border: 1px solid red");
        noEmptyField = false;
    }
    else
        ui->lineEdit_lastName->setStyleSheet("");
    if(ui->lineEdit_username->text().isEmpty() && ui->lineEdit_username->isEnabled())
    {
        ui->lineEdit_username->setStyleSheet("border: 1px solid red" );
        noEmptyField = false;
    }
    else
        ui->lineEdit_username->setStyleSheet("");
    if(ui->lineEdit_password->text().isEmpty() && ui->lineEdit_password->isEnabled())
    {
        ui->lineEdit_password->setStyleSheet("border: 1px solid red");
        noEmptyField = false;
    }
    else
        ui->lineEdit_password->setStyleSheet("");

    return noEmptyField;
}

// When the user comfirm. Treatment of employee data.
void DialogAddEmployee::on_pushButton_ok_clicked()
{
    // Get all the texts
    QString firstName = ui->lineEdit_firstName->text();
    if (!firstName.isEmpty())
        firstName[0] = firstName[0].toUpper();
    QString lastName = ui->lineEdit_lastName->text();
    if (!lastName.isEmpty())
        lastName[0] = lastName[0].toUpper();
    QString username = ui->lineEdit_username->text();
    if (!username.isEmpty())
        username[0] = username[0].toUpper();
    QString password = ui->lineEdit_password->text();

    // Call the controller employee and add employee
    if(colorBoderFail() && controllerEmployee.addEmployee(firstName, lastName, ui->comboBox_Type->currentIndex()+1, username, password))
    {
        QMessageBox::information(this, tr("Infomation"),tr("Operation accepted : Successfully added the employee !"));
        accept();
    }
    else
    {
        QMessageBox::critical(this, tr("Error"), tr("Fail to add the employee !"));
    }
}

// When the user want to create or update an IT Employee. It's to show fields.
void DialogAddEmployee::on_comboBox_Type_activated(const QString &arg1)
{
    if(arg1 == "Computer Scientist")
    {
        ui->label_username->setEnabled(true);
        ui->lineEdit_username->setEnabled(true);
        ui->label_password->setEnabled(true);
        ui->lineEdit_password->setEnabled(true);
    }
    else
    {
        ui->label_username->setEnabled(false);
        ui->lineEdit_username->setEnabled(false);
        ui->label_password->setEnabled(false);
        ui->lineEdit_password->setEnabled(false);
    }
}
