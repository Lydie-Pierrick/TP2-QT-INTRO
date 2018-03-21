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
    // Close the database
    SingletonDB::closeDB();

    // Delete the pointers
    if(modelTreeView != nullptr)
        delete modelTreeView;

    if(modelTableView != nullptr)
        delete modelTableView;

    deletePointersTableView();
    deletePointersTreeView();

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

void MainWindow::modifyClient()
{
    // Open the dialog
    DialogModifyClient dmc;

    if(dmc.exec() == QDialog::Accepted)
    {
        ui->statusBar->showMessage("You have modified a client !");
        initTableViewClients();
    }
}

void MainWindow::modifyEmployee()
{
    // Open the dialog
    DialogModifyEmployee dme;

    if(dme.exec() == QDialog::Accepted)
    {
        ui->statusBar->showMessage("You have modified an employee !");
        initTreeViewRessources();
    }
}

void MainWindow::initTreeViewRessources()
{
    deletePointersTreeView();
    // Set model for treeView
    ui->treeView_Ressource->setModel(modelTreeView);
    // The items cannot be edited
    ui->treeView_Ressource->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Set header label
    modelTreeView->setHorizontalHeaderLabels((QStringList()<<QStringLiteral("ID")<<QStringLiteral("Name")));
    // FUITES !!!!!!!!!!!!!!
    QStandardItem* itemType;
    QStandardItem* itemId;
    QStandardItem* itemName;

    // Get all types of employees
    vector<map<QString, QString> > v_types = controllerEmployee.getAllTypes();

    for(unsigned int i = 0; i < v_types.size(); i ++) {
        // Get employees by type
        vector<Employee> v_employees = controllerEmployee.getEmployeesByType(v_types[i]["id"].toInt());
        // Get the name of this type and initialize a new item
        itemType = new QStandardItem(v_types[i]["label"]);

        // Add the lastnames and ID as the child of Type
        for(unsigned int j = 0; j < v_employees.size(); j ++){
            itemId = new QStandardItem(QString::number(v_employees[j].getId()));
            itemName = new QStandardItem(v_employees[j].getLastname());

            itemType->setChild(j, 0, itemId);
            itemType->setChild(j, 1, itemName);

            // Store the pointers
            //v_pointersTreeView.push_back(itemId);
            //v_pointersTreeView.push_back(itemName);

            //delete itemId;
            //delete itemName;
            //itemId = nullptr;
            //itemName = nullptr;
        }
        modelTreeView->setItem(i, 0, itemType);


        //pointersTreeView.push_back(itemType);
        //itemType = nullptr_t();
    }
    // Expand all the nodes
    ui->treeView_Ressource->expandAll();
}

void MainWindow::initTableViewClients()
{
    //deletePointersTableView();

    // Set model for tableView
    ui->tableView_SearchClient->setModel(modelTableView);
    // Hide the vertical header
    ui->tableView_SearchClient->verticalHeader()->setVisible(false);
    // The items cannot be edited
    ui->tableView_SearchClient->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // One case chosen, one row chosen
    ui->tableView_SearchClient->setSelectionBehavior(QAbstractItemView::SelectRows);

    // Set horizontal header labels
    modelTableView->setHorizontalHeaderLabels((QStringList()<<QStringLiteral("ID")<<QStringLiteral("Firstname")<<
                                               QStringLiteral("Lastname")<<QStringLiteral("Address")<<
                                               QStringLiteral("City")<<QStringLiteral("Telephone")<<
                                               QStringLiteral("Postal Code")<<QStringLiteral("Duration")<<
                                               QStringLiteral("Date")<<QStringLiteral("Priority")<<
                                               QStringLiteral("Comment")<<QStringLiteral("Ressources")));

    // Get all clients
    vector<Client> v_clients = controllerClient.getAllClients();
    // Refresh the tableView
    refreshTableViewClients(v_clients);

}

void MainWindow::refreshTableViewClients(vector<Client> v_clients)
{
    vector<int> idsRes;
    QString namesRes;
    int id;
    // Clear all the existing rows
    modelTableView->removeRows(0, modelTableView->rowCount());

    for(unsigned int i = 0; i < v_clients.size(); i++)
    {
        idsRes = v_clients[i].getIdRessources();
        namesRes = "";
        for(unsigned int j = 0; j < idsRes.size() - 1; j ++)
        {
            id = idsRes[j];
            namesRes += controllerEmployee.searchEmployee(id).getLastname();
            namesRes += " / ";
        }
        id = idsRes[idsRes.size()-1];
        namesRes += controllerEmployee.searchEmployee(id).getLastname();

        QStandardItem * itemId = new QStandardItem(QString::number(v_clients[i].getId()));
        QStandardItem * itemFirstname = new QStandardItem(v_clients[i].getFirstName());
        QStandardItem * itemLastname = new QStandardItem(v_clients[i].getLastName());
        QStandardItem * itemAddr = new QStandardItem(v_clients[i].getAddress());
        QStandardItem * itemCity = new QStandardItem(v_clients[i].getCity());
        QStandardItem * itemTele = new QStandardItem(QString::number(v_clients[i].getTelephone()));
        QStandardItem * itemPC = new QStandardItem(QString::number(v_clients[i].getPostalCode()));
        QStandardItem * itemDuration = new QStandardItem(QString::number(v_clients[i].getDuration()));
        QStandardItem * itemDate = new QStandardItem(v_clients[i].getDateAppointment().toString("yyyy-MM-dd"));
        QStandardItem * itemPriority = new QStandardItem(QString::number(v_clients[i].getPriorityAppointment()));
        QStandardItem * itemComment = new QStandardItem(v_clients[i].getComment());
        QStandardItem * itemRes = new QStandardItem(namesRes);

        modelTableView->setItem(i, 0, itemId);
        modelTableView->setItem(i, 1, itemFirstname);
        modelTableView->setItem(i, 2, itemLastname);
        modelTableView->setItem(i, 3, itemAddr);
        modelTableView->setItem(i, 4, itemCity);
        modelTableView->setItem(i, 5, itemTele);
        modelTableView->setItem(i, 6, itemPC);
        modelTableView->setItem(i, 7, itemDuration);
        modelTableView->setItem(i, 8, itemDate);
        modelTableView->setItem(i, 9, itemPriority);
        modelTableView->setItem(i, 10, itemComment);
        modelTableView->setItem(i, 11, itemRes);
    }

    ui->tableView_SearchClient->resizeColumnsToContents();
    ui->tableView_SearchClient->resizeRowsToContents();
}

///////////////////////////////////////////////////////////////////////////////////
// Problems
void MainWindow::deletePointersTreeView()
{
    for(unsigned int i = 0; i < v_pointersTreeView.size(); i ++)
    {
        if(v_pointersTreeView[i] != nullptr)
            delete v_pointersTreeView[i];
    }
    v_pointersTreeView.clear();
}

void MainWindow::deletePointersTableView()
{
    for(unsigned int i = 0; i < v_pointersTableView.size(); i ++)
    {
        if(v_pointersTableView[i] != nullptr)
            delete v_pointersTableView[i];
    }
    v_pointersTableView.clear();
}
/////////////////////////////////////////////////////////////////////////////////

void  MainWindow::on_treeView_Ressource_clicked(const QModelIndex &index)
{
    QAbstractItemModel* itemModel=(QAbstractItemModel*)index.model();
    QModelIndex indexParent = index.parent();

    if(indexParent.isValid())
    {
        ui->pushBtn_DeleteEmployee->setEnabled(true);
        ui->pushBtn_ModifyEmployee->setEnabled(true);

        // Get content of the 1st column of selected line
        QModelIndex indexId = itemModel->index(index.row(), 0, indexParent);

        // Set selectedID
        int id = indexId.data().toInt();
        Controller_employee::selectedID = id;
    }
    else
    {
        ui->pushBtn_DeleteEmployee->setEnabled(false);
        ui->pushBtn_ModifyEmployee->setEnabled(false);
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

        modifyEmployee();
    }
}

void MainWindow::on_pushBtn_ModifyEmployee_clicked()
{
    modifyEmployee();
}

void MainWindow::on_pushBtn_DeleteEmployee_clicked()
{
    if(controllerEmployee.deleteEmployee(Controller_employee::selectedID))
    {
        ui->statusBar->showMessage("You have removed an employee !");
        initTreeViewRessources();
        QMessageBox::information(this, tr("Infomation"),tr("Operation accepted : Successfully deleted the employee !"));
    }
    else
    {
        QMessageBox::critical(this, tr("Error"), tr("Fail to delete the employee !"));
    }
}

void MainWindow::on_pushBtn_RefreshEmployee_clicked()
{
    ui->statusBar->showMessage("You have refreshed the list of employee !");
    initTreeViewRessources();
}

void MainWindow::on_pushBtn_SearchByDate_clicked()
{
    QDate dateFrom = ui->dateEdit_From->date();
    QDate dateTo = ui->dateEdit_To->date();

    vector<Client> v_clients = controllerClient.searchClientsByDate(dateFrom, dateTo);

    refreshTableViewClients(v_clients);

    ui->statusBar->showMessage("You have searched clients by date.");
}

void MainWindow::on_pushBtn_SearchByID_clicked()
{
   int id = ui->lineEdit_SearchByID->text().toInt();
   vector<Client> v_clients = controllerClient.searchClientById(id);

   if(!v_clients.size() == 0)
   {
      ui->statusBar->showMessage("You have searched clients by id.");
   }
   else
   {
      ui->statusBar->showMessage("You have searched clients by id. No record was found !");
      QMessageBox::critical(this, tr("Error"), tr("No record was found !"));
   }

  refreshTableViewClients(v_clients);
}

void MainWindow::on_pushBtn_SearchByName_clicked()
{
     QString name = ui->lineEdit_SearchByName->text();
     vector<Client> v_clients = controllerClient.searchClientsByName(name);

     if(v_clients.size() != 0)
     {
        ui->statusBar->showMessage("You have searched clients by name.");
     }
     else
     {
        ui->statusBar->showMessage("You have searched clients by name. No record was found !");
        QMessageBox::critical(this, tr("Error"), tr("No record was found !"));
     }

    refreshTableViewClients(v_clients);
}

void MainWindow::on_pushBtn_DeleteClient_clicked()
{
    if(controllerClient.deleteClient(Controller_client::selectedID))
    {
        ui->statusBar->showMessage("You have deleted a client !");
        initTableViewClients();
        QMessageBox::information(this, tr("Infomation"),tr("Operation accepted : Successfully deleted the client !"));
    }
    else
    {
        QMessageBox::critical(this, tr("Error"), tr("Fail to delete the client !"));
    }
}

void MainWindow::on_tableView_SearchClient_clicked(const QModelIndex &index)
{
    QAbstractItemModel* itemModel=(QAbstractItemModel*)index.model();
    QModelIndex indexParent = index.parent();

    if(index.isValid())
    {
        ui->pushBtn_DeleteClient->setEnabled(true);
        ui->pushBtn_ModifyClient->setEnabled(true);

        // Get content of the 1st column of selected line
        QModelIndex indexId = itemModel->index(index.row(), 0, indexParent);

        // Set selectedID
        int id = indexId.data().toInt();
        Controller_client::selectedID = id;
    }
    else
    {
        ui->pushBtn_DeleteClient->setEnabled(false);
    }
}

void MainWindow::on_pushBtn_ModifyClient_clicked()
{
    modifyClient();
}

void MainWindow::on_tableView_SearchClient_doubleClicked(const QModelIndex &index)
{
    modifyClient();
}
