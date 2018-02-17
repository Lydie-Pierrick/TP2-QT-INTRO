#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //ui->tableView->
    ui->setupUi(this);
    ui->statusBar->showMessage("You logged in!");
    initTreeViewRessources();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbout_triggered()
{
    DialogAbout da;
    da.exec();

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
    DialogAddClient dc;
    dc.exec();

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
}

void MainWindow::initTreeViewRessources()
{
    QStandardItemModel* model = new QStandardItemModel(ui->treeView_Ressource);
    model->setHorizontalHeaderLabels((QStringList()<<QStringLiteral("Type")<<QStringLiteral("Nom")));

    QStandardItem* item;
    item = model->horizontalHeaderItem(0);
    item->setToolTip(QStringLiteral("Type of employees") );


    item = model->horizontalHeaderItem(1);
    item->setToolTip(QStringLiteral("Name of employees"));

    ui->treeView_Ressource->setModel(model);
}
