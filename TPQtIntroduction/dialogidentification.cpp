#include "dialogidentification.h"

DialogIdentification::DialogIdentification(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogIdentification)
{
    ui->setupUi(this);
    setFixedSize(this->width(), this->height());
}

DialogIdentification::~DialogIdentification()
{
    delete ui;
}

void DialogIdentification::on_pushBtn_Cancel_clicked()
{
    close();
}

void DialogIdentification::on_pushBtn_Login_clicked()
{
    checkLogin(ui->lineEdit_Username->text(), ui->lineEdit_Password->text());
}

bool DialogIdentification::checkLogin(QString username, QString password)
{
    MainWindow mainWindow;

    QMessageBox messageBox;

    messageBox.setText("Login or password incorrect!");
    messageBox.setWindowTitle("Error");

    if(username == "lydie" && password == "ahah")
    {
        this->hide();
        mainWindow = new MainWindow;
        mainWindow.show();
    }
    else
    {
        ui->lineEdit_Password->clear();
        messageBox.exec();
    }
}
