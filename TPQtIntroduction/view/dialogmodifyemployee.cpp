#include "dialogmodifyemployee.h"

// Constructor
DialogModifyEmployee::DialogModifyEmployee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogModifyEmployee)
{
    ui->setupUi(this);

    int id = Controller_employee::selectedID;
    Employee e = controllerEmployee.searchEmployee(id);

    ui->text_ID->setText(QString::number(id, 10));
    ui->lineEdit_lastname->setText(e.getLastname());
    ui->lineEdit_firstname->setText(e.getFirstname());;

    // All types
    vector<map<QString, QString> > v_types = controllerEmployee.getAllTypes();

    for(unsigned int i = 0; i < v_types.size(); i++)
    {
        ui->comboBox_Type->setItemText(i, v_types[i]["label"]);
    }

    ui->comboBox_Type->setCurrentText(e.getType());

    if(e.getType() == "Computer Scientist")
    {
        ui->label_onlyIT->setEnabled(true);
        ui->lineEdit_username->setEnabled(true);
        ui->lineEdit_password->setEnabled(true);

        ui->lineEdit_username->setText(e.getUsername());
        ui->lineEdit_password->setText(e.getPassword());
    }

    // Set label color
    QPalette palette;
    palette.setColor(QPalette::WindowText, Qt::red);
    ui->label_required->setPalette(palette);
}

//  Destructor
DialogModifyEmployee::~DialogModifyEmployee()
{
    delete ui;
}

// When the user comfirm. Treatment of employee data.
void DialogModifyEmployee::on_pushButton_ok_clicked()
{
    // Get all the texts
    int id = Controller_employee::selectedID;
    int idType = ui->comboBox_Type->currentIndex() + 1;

    QString firstname = ui->lineEdit_firstname->text();
    if (!firstname.isEmpty())
        firstname[0] = firstname[0].toUpper();
    QString lastname = ui->lineEdit_lastname->text();
    if (!lastname.isEmpty())
        lastname[0] = lastname[0].toUpper();
    QString username = ui->lineEdit_username->text();
    if (!username.isEmpty())
        username[0] = username[0].toUpper();
    QString password = ui->lineEdit_password->text();

    if(colorBoderFail() && controllerEmployee.modifyEmployee(id, lastname, firstname, idType, username, password))
    {
        accept();
        QMessageBox::information(this, tr("Infomation"),tr("Operation accepted : Successfully modified the employee !"));
    }
    else
    {
        QMessageBox::critical(this, tr("Error"), tr("Fail to modify the employee !"));
    }
}

// When the user want to cancel his action
void DialogModifyEmployee::on_pushButton_cancel_clicked()
{
    reject();
}

// When the user want to create or update an IT Employee. It's to show fields.
void DialogModifyEmployee::on_comboBox_Type_activated(const QString &arg1)
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

// It's for color the field border when it's wrong
bool DialogModifyEmployee::colorBoderFail()
{
    bool noEmptyField = true;
    if(ui->lineEdit_firstname->text().isEmpty())
    {
        ui->lineEdit_firstname->setStyleSheet("border: 1px solid red");
        noEmptyField = false;
    }
    else
        ui->lineEdit_firstname->setStyleSheet("");
    if(ui->lineEdit_lastname->text().isEmpty())
    {
        ui->lineEdit_lastname->setStyleSheet("border: 1px solid red");
        noEmptyField = false;
    }
    else
        ui->lineEdit_lastname->setStyleSheet("");
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
