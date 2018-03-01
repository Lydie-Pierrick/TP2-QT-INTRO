#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
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
    model->setHorizontalHeaderLabels((QStringList()<<QStringLiteral("ID")<<QStringLiteral("Name")<<QStringLiteral("Type")));

    QStandardItem* itemHeader;
    itemHeader = model->horizontalHeaderItem(0);
    itemHeader->setToolTip(QStringLiteral("ID of employees"));

    itemHeader = model->horizontalHeaderItem(1);
    itemHeader->setToolTip(QStringLiteral("Name of employees"));

    itemHeader = model->horizontalHeaderItem(2);
    itemHeader->setToolTip(QStringLiteral("Type of employees"));

    // Revoir quand on peut acceder a la base de donnes
    // IDs
    model->setItem(0, 0, new QStandardItem("1"));
    model->setItem(1, 0, new QStandardItem("2"));
    model->setItem(2, 0, new QStandardItem("3"));
    model->setItem(3, 0, new QStandardItem("4"));

    // Names
    model->setItem(0, 1, new QStandardItem("A"));
    model->setItem(1, 1, new QStandardItem("B"));
    model->setItem(2, 1, new QStandardItem("C"));
    model->setItem(3, 1, new QStandardItem("D"));

    // Types
    model->setItem(0, 2, new QStandardItem("Bnaker A"));
    model->setItem(1, 2, new QStandardItem("Bnaker B"));
    model->setItem(2, 2, new QStandardItem("Bnaker C"));
    model->setItem(3, 2, new QStandardItem("Bnaker D"));

    // The items cannot be modified
    ui->treeView_Ressource->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->treeView_Ressource->setModel(model);
}

void  MainWindow::on_treeView_Ressource_clicked(const QModelIndex &index)
{
    ui->pushBtn_Delete->setEnabled(true);
    ui->pushBtn_Modify->setEnabled(true);

    QAbstractItemModel* itemModel=(QAbstractItemModel*)index.model();
    // Get content of the 1st column of selected line
    QModelIndex modelIndex = itemModel->index(index.row(), 0);
    int id = modelIndex.data().toInt();
    // Set selectedID
    selectedID = id;
    cout<<id<<endl;
}

void MainWindow::on_pushBtn_Modify_clicked()
{
    Controller_employee controllerEmployee;
    controllerEmployee.modifyEmployee(selectedID);
}

void MainWindow::on_pushBtn_Delete_clicked()
{
    Controller_employee controllerEmployee;
    controllerEmployee.deleteEmployee(selectedID);
}

void MainWindow::on_pushBtn_SearchByIDName_clicked()
{
    QString strIDName = ui->lineEdit_SearchByIDName->text();
    //Controller_client controller_client;
    //controller_client.searchClient()
}

void MainWindow::on_pushBtn_SearchByDate_clicked()
{
    QString dateAppointment = ui->dateEdit->text();
    //Controller_client controller_client;
    //controller_client.searchClient()
}
