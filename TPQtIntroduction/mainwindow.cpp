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
    model->setHorizontalHeaderLabels((QStringList()<<QStringLiteral("ID")<<QStringLiteral("Last name")<<QStringLiteral("First name")<<QStringLiteral("Type")));

    QStandardItem* itemHeader;
    itemHeader = model->horizontalHeaderItem(0);
    itemHeader->setToolTip(QStringLiteral("ID of employees"));

    itemHeader = model->horizontalHeaderItem(1);
    itemHeader->setToolTip(QStringLiteral("Last name of employees"));

    itemHeader = model->horizontalHeaderItem(2);
    itemHeader->setToolTip(QStringLiteral("First name of employees"));

    itemHeader = model->horizontalHeaderItem(3);
    itemHeader->setToolTip(QStringLiteral("Type of employees"));

    vector<vector<QString>> v_records = controllerEmployee.getAllEmployees();
    for(int i = 0; i < v_records.size(); i ++){
        for(int j = 0; j < v_records[i].size(); j ++){
             model->setItem(i, j, new QStandardItem(v_records[i][j]));
        }
    }

    // The items cannot be modified
    ui->treeView_Ressource->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->treeView_Ressource->setModel(model);
}

void MainWindow::showEmpolyees()
{
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
    //controllerEmployee.setSelectedID(id);
    Controller_employee::selectedID = id;
}

void MainWindow::on_pushBtn_Modify_clicked()
{
    // Open the dialog
    DialogModifyEmployee dme;
    dme.exec();

    //controllerEmployee.modifyEmployee(controllerEmployee.getSelectedID());
    //controllerEmployee.showAllEmployees();
}

void MainWindow::on_pushBtn_Delete_clicked()
{
    //controllerEmployee.deleteEmployee(controllerEmployee.getSelectedID());
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
