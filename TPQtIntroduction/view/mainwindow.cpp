#include "mainwindow.h"
// Constructor
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Initialize the contenus of interface
    ui->statusBar->showMessage("You logged in!");
    ui->dateEdit_Planning->setDate(QDate::currentDate());
    ui->dateEdit_From->setDate(QDate::currentDate());
    ui->dateEdit_To->setDate(QDate::currentDate());

    // Initialize two pointers of tableView and treeView
    modelTreeView = new QStandardItemModel();
    modelTableView = new QStandardItemModel();

    // Initialize two tables : tableView and treeView
    initTreeViewRessources();
    initTableViewClients();

    // TP note
    ui->lineEdit_SearchByName->setText("His/Her firstname");
}

// Destructor
MainWindow::~MainWindow()
{
    // Close the database
    SingletonDB::closeDB();

    // Delete the pointers
    if(modelTreeView != NULL)
        delete modelTreeView;

    if(modelTableView != NULL)
        delete modelTableView;

    delete ui;
}

// Trigger action About
void MainWindow::on_actionAbout_triggered()
{
    // Change the text of statusBar
    ui->statusBar->showMessage("You have consulted \"about us\" !");
    DialogAbout da;
    da.exec();
}

// Trigger action Quit
void MainWindow::on_actionQuit_triggered()
{
    // Close the window
    close();
}

// Trigger action AddClient (Text)
void MainWindow::on_actionClient_triggered()
{
    // Call the function to add a client
    addClient();
}
// Trigger action AddClient (Icon)
void MainWindow::on_actionClient_2_triggered()
{
    // Call the function to add a client
    addClient();
}

// Function for adding a client
void MainWindow::addClient()
{
    DialogAddClient dac;

    // If the dialog of AddClient accepts the operations
    if(dac.exec() == QDialog::Accepted)
    {
        // Change the text of statusBar
        ui->statusBar->showMessage("You have added a client !");
        // Refresh the table view
        refreshTableViewClients(controllerClient.getAllClients());
    }
}

// Trigger action AddEmployee (Text)
void MainWindow::on_actionEmployee_triggered()
{
    // Add an employee
    addEmployee();
}

// Trigger action AddEmployee (Icon)
void MainWindow::on_actionEmployee_2_triggered()
{
    // Add an employee
    addEmployee();
}

// Funcion for adding an employee
void MainWindow::addEmployee()
{
    DialogAddEmployee dae;

    // If the dialog of AddEmployee accepts the operations
    if(dae.exec() == QDialog::Accepted)
    {
        // Change the text of statusBar
        ui->statusBar->showMessage("You have added an employee !");
        // Refresh the treeView
        initTreeViewRessources();
    }
}

// Funciton for modifying a client
void MainWindow::modifyClient()
{
    DialogModifyClient dmc;

    // If the dialog of AddEmployee accepts the operations
    if(dmc.exec() == QDialog::Accepted)
    {
        // Change the text of statusBar
        ui->statusBar->showMessage("You have modified a client !");
        // Refresh the tableView
        initTableViewClients();
    }
}

// Function for modifying an employee
void MainWindow::modifyEmployee()
{
    DialogModifyEmployee dme;

    // If the dialog of AddEmployee accepts the operations
    if(dme.exec() == QDialog::Accepted)
    {
        // Change the text of statusBar
        ui->statusBar->showMessage("You have modified an employee !");
        // Refresh the treeView
        initTreeViewRessources();
    }
}

// Funciton for initialising the treeView
void MainWindow::initTreeViewRessources()
{
    //deletePointersTreeView();
    // Set model for treeView
    ui->treeView_Ressource->setModel(modelTreeView);
    // The items cannot be edited
    ui->treeView_Ressource->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // Set header label
    modelTreeView->setHorizontalHeaderLabels((QStringList()<<QStringLiteral("ID")<<QStringLiteral("Name")));

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
            // Set itemId et itemName
            itemId = new QStandardItem(QString::number(v_employees[j].getId()));
            itemName = new QStandardItem(v_employees[j].getLastname());

            // Set children for itemType with itemId and itemName
            itemType->setChild(j, 0, itemId);
            itemType->setChild(j, 1, itemName);
            itemId = NULL;
            itemName = NULL;
        }
        // Set item for model
        modelTreeView->setItem(i, 0, itemType);
        v_pointersTreeView.push_back(itemType);
        itemType = NULL;
    }
    // Expand all the nodes
    ui->treeView_Ressource->expandAll();
}

// Funciton for initialising the tableView
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
    // Set horizontal header labels
    modelTableView->setHorizontalHeaderLabels((QStringList()<<QStringLiteral("ID")<<QStringLiteral("Firstname")<<
                                               QStringLiteral("Lastname")<<QStringLiteral("Ressources")));
    // Stretch the last section
    ui->tableView_SearchClient->horizontalHeader()->setStretchLastSection(true);
    // Get all clients
    vector<Client> v_clients = controllerClient.getAllClients();
    // Refresh the tableView
    refreshTableViewClients(v_clients);
    // Resizing the width of column 3 according the content
    ui->tableView_SearchClient->resizeColumnToContents(3);
    // Resizing the height of rows
    ui->tableView_SearchClient->resizeRowsToContents();

}

// Function for refreshing the tableView
void MainWindow::refreshTableViewClients(vector<Client> v_clients)
{
    //deletePointersTableView();
    vector<int> idsRes;
    QString namesRes;
    int id;

    // Clear all the existing rows
    modelTableView->removeRows(0, modelTableView->rowCount());

    QStandardItem * itemId;
    QStandardItem * itemFirstname;
    QStandardItem * itemLastname;
    QStandardItem * itemRes ;

    // Get information of each clients
    for(unsigned int i = 0; i < v_clients.size(); i++)
    {        
        // Get ressources IDs
        idsRes = v_clients[i].getIdRessources();
        namesRes = "";
        // Convert all IDs into a string
        for(unsigned int j = 0; j < idsRes.size() - 1; j ++)
        {
            id = idsRes[j];
            namesRes += controllerEmployee.searchEmployee(id).getLastname();
            namesRes += " / ";
        }
        // Convert the last ID into a string
        id = idsRes[idsRes.size()-1];
        namesRes += controllerEmployee.searchEmployee(id).getLastname();

        itemId = new QStandardItem(QString::number(v_clients[i].getId()));
        itemFirstname = new QStandardItem(v_clients[i].getFirstName());
        itemLastname = new QStandardItem(v_clients[i].getLastName());
        itemRes = new QStandardItem(namesRes);

        // Set items for model
        modelTableView->setItem(i, 0, itemId);
        modelTableView->setItem(i, 1, itemFirstname);
        modelTableView->setItem(i, 2, itemLastname);
        modelTableView->setItem(i, 3, itemRes);

        v_pointersTableView.push_back(itemId);
        v_pointersTableView.push_back(itemFirstname);
        v_pointersTableView.push_back(itemLastname);
        v_pointersTableView.push_back(itemRes);

        itemId = NULL;
        itemFirstname = NULL;
        itemLastname = NULL;
        itemRes = NULL;
    }
}

void MainWindow::initTableViewPlanning()
{
    // Set model for tableView
    ui->tableView_Planning->setModel(modelTableView);
    // Hide the vertical header
    ui->tableView_Planning->verticalHeader()->setVisible(false);
    // The items cannot be edited
    ui->tableView_Planning->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // One case chosen, one row chosen
    ui->tableView_Planning->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Set horizontal header labels
    modelTableView->setHorizontalHeaderLabels((QStringList()<<QStringLiteral("ID")<<QStringLiteral("Firstname")<<
                                               QStringLiteral("Lastname")<<QStringLiteral("Ressources")));
    // Stretch the last section
    ui->tableView_Planning->horizontalHeader()->setStretchLastSection(true);
    // Get clients of this date
    vector<Client> v_clients = controllerClient.searchClientsByDate(ui->dateEdit_Planning->date(),
                                                                    ui->dateEdit_Planning->date());
    // Refresh the tableView
    refreshTableViewClients(v_clients);
    // Resizing the width of column 3 according the content
    ui->tableView_Planning->resizeColumnToContents(3);
    // Resizing the height of rows
    ui->tableView_Planning->resizeRowsToContents();
}

// Funciton for deleting the pointer in treeView
void MainWindow::deletePointersTreeView()
{
    for(unsigned int i = 0 ; i < v_pointersTreeView.size(); i ++)
    {
        for(int j = 0; j < v_pointersTreeView[i]->rowCount(); j ++)
        {
            if(v_pointersTreeView[i]->child(j, 0) != NULL)
                delete v_pointersTreeView[i]->child(j, 0);
            if(v_pointersTreeView[i]->child(j, 1) != NULL)
                delete v_pointersTreeView[i]->child(j, 1);
        }

        if(v_pointersTreeView[i] != NULL)
            delete v_pointersTreeView[i];
    }

    v_pointersTreeView.clear();
}

// Funciton for deleting the pointer in tableView
void MainWindow::deletePointersTableView()
{
    for(unsigned int i = 0 ; i < v_pointersTableView.size(); i ++)
    {
        for(int j = 0; j < v_pointersTableView[i]->rowCount(); j ++)
        {
            if(v_pointersTableView[i]->child(j, 0) != NULL)
                delete v_pointersTableView[i]->child(j, 0);
            if(v_pointersTableView[i]->child(j, 1) != NULL)
                delete v_pointersTableView[i]->child(j, 1);
        }

        if(v_pointersTableView[i] != NULL)
            delete v_pointersTableView[i];
    }

    v_pointersTableView.clear();
}

// Slot : click the treeView (choose an employee)
void  MainWindow::on_treeView_Ressource_clicked(const QModelIndex &index)
{
    QAbstractItemModel* itemModel=(QAbstractItemModel*)index.model();
    // Get the parent of current index (Type of employees)
    QModelIndex indexParent = index.parent();

    // Check if the parent exists (for avoiding clicking the Type)
    if(indexParent.isValid())
    {
        // Set two buttons enable
        ui->pushBtn_DeleteEmployee->setEnabled(true);
        ui->pushBtn_ModifyEmployee->setEnabled(true);

        // Get content of the 1st column of selected line
        QModelIndex indexId = itemModel->index(index.row(), 0, indexParent);

        // Set selectedID
        int id = indexId.data().toInt();
        Controller_employee::selectedID = id;
    }
    else // If user click Type the two buttons will not be enabled
    {
        ui->pushBtn_DeleteEmployee->setEnabled(false);
        ui->pushBtn_ModifyEmployee->setEnabled(false);
    }
}

// Slot : double click the treeView (modify the employees)
void MainWindow::on_treeView_Ressource_doubleClicked(const QModelIndex &index)
{
    QAbstractItemModel* itemModel=(QAbstractItemModel*)index.model();
    // Get the parent of current index (Type of employees)
    QModelIndex indexParent = index.parent();

    // Check if the parent exists (for avoiding clicking the Type)
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

// Slot : click the button of modifyEmployee
void MainWindow::on_pushBtn_ModifyEmployee_clicked()
{
    modifyEmployee();
}

// Slot : click the button of deleteEmployee
void MainWindow::on_pushBtn_DeleteEmployee_clicked()
{
    // If successfully delete an employee
    if(controllerEmployee.deleteEmployee(Controller_employee::selectedID))
    {
        ui->statusBar->showMessage("You have removed an employee !");
        // Refresh the treeView
        initTreeViewRessources();
        QMessageBox::information(this, tr("Infomation"),tr("Operation accepted : Successfully deleted the employee !"));
    }
    else
    {
        QMessageBox::critical(this, tr("Error"), tr("Fail to delete the employee !"));
    }
}

// Slot : click the button of refreshEmployee
void MainWindow::on_pushBtn_RefreshEmployee_clicked()
{
    ui->statusBar->showMessage("You have refreshed the list of employee !");
    // Refresh the treeView
    initTreeViewRessources();
}

// Slot :click the button of searchByDate
void MainWindow::on_pushBtn_SearchByDate_clicked()
{
    // Get dates from interfaces
    QDate dateFrom = ui->dateEdit_From->date();
    QDate dateTo = ui->dateEdit_To->date();


    if(dateFrom > dateTo)
    {
        QMessageBox::critical(this, tr("Error"), tr("Error date searched ! Please check your field."));
    }
    else
    {
        // Search clients between two dates
        vector<Client> v_clients = controllerClient.searchClientsByDate(dateFrom, dateTo);

        // Refresh the tableView
        refreshTableViewClients(v_clients);

        ui->statusBar->showMessage("You have searched clients by date.");
    }
}

// Slot :click the button of refreshEmployee
void MainWindow::on_pushBtn_SearchByID_clicked()
{
    // Get ID from the interface
    int id = ui->lineEdit_SearchByID->text().toInt();
    // Get the client by ID
    vector<Client> v_clients = controllerClient.searchClientById(id);

    // If we find a client
    if(!v_clients.size() == 0)
    {
        ui->statusBar->showMessage("You have searched clients by id.");
    }
    else // If there isn't a client with this ID
    {
        ui->statusBar->showMessage("You have searched clients by id. No record was found !");
        QMessageBox::critical(this, tr("Error"), tr("No record was found !"));
    }

    // Refresh the tableView
    refreshTableViewClients(v_clients);
}

// Slot :click the button of searchClientByName
void MainWindow::on_pushBtn_SearchByName_clicked()
{
    // Get name from the interface
    QString name = ui->lineEdit_SearchByName->text();
    // Get clients by names
    vector<Client> v_clients = controllerClient.searchClientsByName(name);

    // If we find a client
    if(v_clients.size() != 0)
    {
        ui->statusBar->showMessage("You have searched clients by name.");
    }
    else // If there isn't a client with this name
    {
        ui->statusBar->showMessage("You have searched clients by name. No record was found !");
        QMessageBox::critical(this, tr("Error"), tr("No record was found !"));
    }

    refreshTableViewClients(v_clients);
}


// Slot :click the button of deleteClient
void MainWindow::on_pushBtn_DeleteClient_clicked()
{
    // If successfully delete an client
    if(controllerClient.deleteClient(Controller_client::selectedID))
    {
        ui->statusBar->showMessage("You have deleted a client !");
        // Refresh tableView
        initTableViewClients();
        QMessageBox::information(this, tr("Infomation"),tr("Operation accepted : Successfully deleted the client !"));
    }
    else
    {
        QMessageBox::critical(this, tr("Error"), tr("Fail to delete the client !"));
    }
}

// Slot :click the tableView (choose a client)
void MainWindow::on_tableView_SearchClient_clicked(const QModelIndex &index)
{
    QAbstractItemModel* itemModel=(QAbstractItemModel*)index.model();

    // If this index is valid
    if(index.isValid())
    {
        ui->pushBtn_DeleteClient->setEnabled(true);
        ui->pushBtn_ModifyClient->setEnabled(true);

        // Get content of the 1st column of selected line
        QModelIndex indexId = itemModel->index(index.row(), 0);

        // Set selectedID
        int id = indexId.data().toInt();
        Controller_client::selectedID = id;
    }
    else
    {
        ui->pushBtn_DeleteClient->setEnabled(false);
    }
}

// Slot :click the button of modifyClient
void MainWindow::on_pushBtn_ModifyClient_clicked()
{
    modifyClient();
}

// Slot : double click the tableView (modify a client)
void MainWindow::on_tableView_SearchClient_doubleClicked()
{
    modifyClient();
}

// Slot : click the tabBar
void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    if(index == 0) // Interface : search client
    {
        initTableViewClients();
    }
    else if(index == 1) // Interface : ressources
    {
        initTreeViewRessources();
    }
    else if(index == 2) // Interface : planning
    {
        initTableViewPlanning();
    }
}

// Slot : click the button plan
void MainWindow::on_pushBtn_Plan_clicked()
{
    QString fileName;
    // Set file name by default
    QString fileNameDefault = "Planning_" +
            ui->dateEdit_Planning->date().toString("ddMMyyyy");
    // Open file dialog and set the properties
    fileName = QFileDialog::getSaveFileName(this,
        tr("Save planning"), fileNameDefault, tr("Text (*.txt)"));

    if (!fileName.isEmpty()) // If the file name is not empty
    {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) { // If fail to open a file in "WriteOnly"
            QMessageBox::critical(this, tr("Error"), tr("Fail to open the file !"));
        } else { // If succeed
            QTextStream stream(&file);
            // Write the text into file
            stream << ui->dateEdit_Planning->date().toString("ddMMyyyy");
            stream.flush();
            // Close the file
            file.close();
            QMessageBox::information(this, tr("Infomation"),tr("Operation accepted : Successfully saved the file !"));
        }
    }
    ui->statusBar->showMessage("You have consulted the list of clients !");
}

// Slot : click
void MainWindow::on_pushBtn_ShowResult_clicked()
{
    initTableViewPlanning();
    ui->statusBar->showMessage("You have consulted the list of clients !");
}

// TP note
void MainWindow::on_pushBtn_Export_clicked()
{
    QString fileName;
    // Set file name by default
    QString fileNameDefault = "Ressources_" +
            QDate::currentDate().toString("ddMMyyyy");;
    // Open file dialog and set the properties
    fileName = QFileDialog::getSaveFileName(this,
        tr("Export Ressources"), fileNameDefault, tr("XML (*.xml)"));

    vector<Client> v_client = controllerClient.getAllClients();

    if (!fileName.isEmpty()) // If the file name is not empty
    {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly))
        { // If fail to open a file in "WriteOnly"
            QMessageBox::critical(this, tr("Error"), tr("Fail to open the file !"));
        }
        else
        {
            int size = v_client.size();

            QTextStream stream(&file);
            QString firstname, lastname;
            int id;

            // Write the text into file
            stream << "<TRessource>\n";

            for(int i = 0; i < size; i ++)
            {
                id = v_client[i].getId();
                firstname = v_client[i].getFirstName();
                lastname = v_client[i].getLastName();

                stream << "\t<Ressource Id = \"" + QString::number(id) + "\">\n";
                stream << "\t\t<Lastname>" + lastname + "<\/Lastname>\n";
                stream << "\t\t<Firstname>" + firstname + "<\/Firstname>\n";
                stream << "\t<\/Ressource>\n";
            }

            stream << "<TRessource>\n";

            stream.flush();
            // Close the file
            file.close();
        }
    }
    ui->statusBar->showMessage("You have exported the XML of clients !");
}

void MainWindow::on_pushButton_AddOtherEmployee_clicked()
{
    DialogOthers dialogOthers;
    if(dialogOthers.exec() == QDialog::Accepted) {
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
     cout << "Show number inserts SQL : " << (DAO_Employee::counter_insert + DAO_Employee::counter_insert) << endl;
}
