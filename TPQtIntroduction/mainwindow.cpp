#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusBar->showMessage("You are logged !");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbout_triggered()
{
    ui->statusBar->showMessage("You have consulted \"about us\" !");
}

void MainWindow::on_actionQuit_triggered()
{
    close();
}

// ADD CLIENT

void MainWindow::on_actionClient_triggered()
{
    addClient();
}

void MainWindow::on_actionClient_2_triggered()
{
    addClient();
}

void MainWindow::addClient()
{
    DialogAbout da;
    da.exec();

    /*if(ClientBD::addClientBD())
        ui->statusBar->showMessage("You have added a client !");*/
}

// ADD EMPLOYEE

void MainWindow::on_actionEmployee_triggered()
{
    addEmployee();
}

void MainWindow::on_actionEmployee_2_triggered()
{
    addEmployee();
}

void MainWindow::addEmployee()
{
    DialogAddEmployee de;
    de.exec();

    /*if(EmployeeBD::addEmployeeBD())
        ui->statusBar->showMessage("You have added an employee !");*/
}
