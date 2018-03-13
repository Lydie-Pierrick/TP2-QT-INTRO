#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusBar->showMessage("You logged in!");

    modelTreeView = new QStandardItemModel();
    modelTableView = new QStandardItemModel();

    initTreeViewRessources();
    initTableViewClients();  
}

MainWindow::~MainWindow()
{
    SingletonDB::closeDB();
    if(modelTreeView != nullptr_t())
        delete modelTreeView;
    if(modelTableView != nullptr_t())
        delete modelTableView;
    delete ui;
}

void MainWindow::on_actionAbout_triggered()
{
    ui->statusBar->showMessage("You have consulted \"about us\" !");
    DialogAbout da;
    da.exec();
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
    DialogAddClient dac;

    if(dac.exec() == QDialog::Accepted)
    {
        ui->statusBar->showMessage("You have added a client !");
        refreshTableViewClients(controllerClient.getAllClients());
    }
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
    DialogAddEmployee dae;

    if(dae.exec() == QDialog::Accepted)
    {
        ui->statusBar->showMessage("You have added an employee !");
        initTreeViewRessources();
    }
}

void MainWindow::initTreeViewRessources()
{
    // Set model for treeView
    ui->treeView_Ressource->setModel(modelTreeView);
    // The items cannot be edited
    ui->treeView_Ressource->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Set header label
    modelTreeView->setHorizontalHeaderLabels((QStringList()<<QStringLiteral("ID")<<QStringLiteral("Name")));
    // FUITES !!!!!!!!!!!!!!
    QStandardItem* itemType;

    // Get all types of employees
    vector<map<QString, QString>> v_types = controllerEmployee.getAllTypes();

    for(unsigned int i = 0; i < v_types.size(); i ++) {
        // Get employees by type
        vector<Employee> v_employees = controllerEmployee.getEmployeesByType(v_types[i]["id"].toInt());
        // Get the name of this type and initialize a new item
        itemType = new QStandardItem(v_types[i]["label"]);

        // Add the lastnames and ID as the child of Type
        for(unsigned int j = 0; j < v_employees.size(); j ++){
            QStandardItem* itemId = new QStandardItem(QString::number(v_employees[j].getId()));
            QStandardItem* itemName = new QStandardItem(v_employees[j].getLastname());

            itemType->appendRow(itemId);
            itemType->setChild(j, 1, itemName);
        }
        modelTreeView->setItem(i, 0, itemType);
    }
}

void MainWindow::initTableViewClients()
{
    // Set model for tableView
    ui->tableView_SearchClient->setModel(modelTableView);
    // Hide the vertical header
    ui->tableView_SearchClient->verticalHeader()->setVisible(false);
    // The items cannot be edited
    ui->tableView_SearchClient->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // One case chosen, one row chosen
    ui->tableView_SearchClient->setSelectionBehavior(QAbstractItemView::SelectRows);

    // Set horizontal header items
    modelTableView->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("ID")));
    modelTableView->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("Firstname")));
    modelTableView->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("Lastname")));
    modelTableView->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("Address")));
    modelTableView->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("City")));
    modelTableView->setHorizontalHeaderItem(5, new QStandardItem(QObject::tr("Telephone")));
    modelTableView->setHorizontalHeaderItem(6, new QStandardItem(QObject::tr("Postal Code")));
    modelTableView->setHorizontalHeaderItem(7, new QStandardItem(QObject::tr("Duration")));
    modelTableView->setHorizontalHeaderItem(8, new QStandardItem(QObject::tr("Date")));
    modelTableView->setHorizontalHeaderItem(9, new QStandardItem(QObject::tr("Priority")));
    modelTableView->setHorizontalHeaderItem(10, new QStandardItem(QObject::tr("Comment")));

    // Get all clients
    vector<Client> v_clients = controllerClient.getAllClients();
    // Refresh the tableView
    refreshTableViewClients(v_clients);
}

void MainWindow::refreshTableViewClients(vector<Client> v_clients)
{
    // Clear all the existing rows
    modelTableView->removeRows(0,modelTableView->rowCount());

    for(unsigned int i = 0; i < v_clients.size(); i ++)
    {
        modelTableView->setItem(i, 0, new QStandardItem(QString::number(v_clients[i].getId())));
        modelTableView->setItem(i, 1, new QStandardItem(v_clients[i].getFirstName()));
        modelTableView->setItem(i, 2, new QStandardItem(v_clients[i].getLastName()));
        modelTableView->setItem(i, 3, new QStandardItem(v_clients[i].getAddress()));
        modelTableView->setItem(i, 4, new QStandardItem(v_clients[i].getCity()));
        modelTableView->setItem(i, 5, new QStandardItem(QString::number(v_clients[i].getTelephone())));
        modelTableView->setItem(i, 6, new QStandardItem(QString::number(v_clients[i].getPostalCode())));
        modelTableView->setItem(i, 7, new QStandardItem(QString::number(v_clients[i].getDuration())));
        modelTableView->setItem(i, 8, new QStandardItem(v_clients[i].getDateAppointment().toString("yyyy-MM-dd")));
        modelTableView->setItem(i, 9, new QStandardItem(QString::number(v_clients[i].getPriorityAppointment())));
        modelTableView->setItem(i, 10, new QStandardItem(v_clients[i].getComment()));
    }
}

void  MainWindow::on_treeView_Ressource_clicked(const QModelIndex &index)
{
    QAbstractItemModel* itemModel=(QAbstractItemModel*)index.model();
    QModelIndex indexParent = index.parent();

    if(indexParent.isValid())
    {
        ui->pushBtn_Delete->setEnabled(true);
        ui->pushBtn_Modify->setEnabled(true);

        // Get content of the 1st column of selected line
        QModelIndex indexId = itemModel->index(index.row(), 0, indexParent);

        // Set selectedID
        int id = indexId.data().toInt();
        Controller_employee::selectedID = id;
    }
    else
    {
        ui->pushBtn_Delete->setEnabled(false);
        ui->pushBtn_Modify->setEnabled(false);
    }
}

void MainWindow::on_treeView_Ressource_doubleClicked(const QModelIndex &index)
{
    QAbstractItemModel* itemModel=(QAbstractItemModel*)index.model();
    QModelIndex indexParent = index.parent();

    if(indexParent.isValid())
    {
        // Get content of the 1st column of selected line
        QModelIndex indexId = itemModel->index(index.row(), 0, indexParent);

        // Set selectedID
        int id = indexId.data().toInt();
        Controller_employee::selectedID = id;

        // Open the dialog
        DialogModifyEmployee dme;

        if(dme.exec() == QDialog::Accepted)
        {
            ui->statusBar->showMessage("You have modified an employee !");
            initTreeViewRessources();
        }
    }
}

void MainWindow::on_pushBtn_Modify_clicked()
{
    // Open the dialog
    DialogModifyEmployee dme;

    if(dme.exec() == QDialog::Accepted)
    {
        ui->statusBar->showMessage("You have modified an employee !");
        initTreeViewRessources();
    }
}

void MainWindow::on_pushBtn_Delete_clicked()
{
    if(controllerEmployee.deleteEmployee(Controller_employee::selectedID))
    {
        ui->statusBar->showMessage("You have removed an employee !");
        QMessageBox::information(this, tr("Infomation"),tr("Operation accepted : Successfully deleted the employee !"));
    }
    else
    {
        QMessageBox::critical(this, tr("Error"), tr("Fail to delete the employee !"));
    }
    initTreeViewRessources();
}

void MainWindow::on_pushBtn_Refresh_clicked()
{
    ui->statusBar->showMessage("You have refreshed the list of employee !");
    initTreeViewRessources();
}

void MainWindow::on_pushBtn_SearchByDate_clicked()
{
    QDate date = ui->dateEdit->date();

    vector<Client> v_clients = controllerClient.searchClientsByDate(date);

    refreshTableViewClients(v_clients);

    ui->statusBar->showMessage("You have searched clients by date.");
}

void MainWindow::on_pushBtn_SearchByID_clicked()
{
    int id = ui->lineEdit_SearchByID->text().toInt();

    Client client = controllerClient.searchClientById(id);
    vector<Client> v_clients;
    v_clients.push_back(client);
    refreshTableViewClients(v_clients);

    ui->statusBar->showMessage("You have searched clients by ID.");
}

void MainWindow::on_pushBtn_SearchByName_clicked()
{
     QString name = ui->lineEdit_SearchByName->text();
     vector<Client> v_clients = controllerClient.searchClientsByName(name);

     refreshTableViewClients(v_clients);
      ui->statusBar->showMessage("You have searched clients by name.");
}

void MainWindow::on_pushBtn_DeleteClient_clicked()
{

}

void MainWindow::on_tableView_SearchClient_clicked(const QModelIndex &index)
{

}
