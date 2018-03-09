#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusBar->showMessage("You logged in!");
    initTreeViewRessources();
    initTableViewClients();
}

MainWindow::~MainWindow()
{
    SingletonDB::closeDB();
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
    /*if(ClientBD::addClientBD())
        ui->statusBar->showMessage("You have added a client !");*/
    DialogAddClient dc;
    dc.exec();
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
    QStandardItemModel* model = new QStandardItemModel();

    // Set header label
    model->setHorizontalHeaderLabels((QStringList()<<QStringLiteral("ID")<<QStringLiteral("Name")));

    QStandardItem* itemType;

    // Get all types of employees
    vector<map<QString, QString>> v_types = controllerEmployee.getAllTypes();

    for(unsigned int i = 0; i < v_types.size(); i ++) {
        // Get lastname of employees
        vector<Employee> v_employees = controllerEmployee.getEmployeesByType(v_types[i]["id"].toInt());
        itemType = new QStandardItem(v_types[i]["label"]);

        // Add the lastnames as the child of Type
        for(unsigned int j = 0; j < v_employees.size(); j ++){
            QStandardItem* itemId = new QStandardItem(QString::number(v_employees[j].getId()));
            QStandardItem* itemName = new QStandardItem(v_employees[j].getLastname());

            itemType->appendRow(itemId);
            itemType->setChild(j, 1, itemName);
        }
        model->setItem(i, 0, itemType);

    }

    // The items cannot be modified
    ui->treeView_Ressource->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->treeView_Ressource->setModel(model);
}

void MainWindow::initTableViewClients()
{
    QStandardItemModel * model = new QStandardItemModel();

    // We cannot edit this TableView
    ui->tableView_SearchClient->setEditTriggers(QAbstractItemView::NoEditTriggers);

    model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("ID")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("Firstname")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("Lastname")));
    model->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("Address")));
    model->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("City")));
    model->setHorizontalHeaderItem(5, new QStandardItem(QObject::tr("Telephone")));
    model->setHorizontalHeaderItem(6, new QStandardItem(QObject::tr("Postal Code")));
    model->setHorizontalHeaderItem(7, new QStandardItem(QObject::tr("Duration")));
    model->setHorizontalHeaderItem(8, new QStandardItem(QObject::tr("Date")));
    model->setHorizontalHeaderItem(9, new QStandardItem(QObject::tr("Priority")));
    model->setHorizontalHeaderItem(10, new QStandardItem(QObject::tr("Comment")));

    //ui->tableView_SearchClient->setColumnWidth(0, 10);

    vector<Client> v_clients = controllerClient.getAllClients();
    showClients(model, v_clients);

    ui->tableView_SearchClient->setModel(model);
}

void MainWindow::refreshTableViewClients()
{
//    QStandardItemModel * model = new QStandardItemModel();

//    // We cannot edit this TableView
//    ui->tableView_SearchClient->setEditTriggers(QAbstractItemView::NoEditTriggers);

//    model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("ID")));
//    model->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("Firstname")));
//    model->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("Lastname")));
//    model->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("Address")));
//    model->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("City")));
//    model->setHorizontalHeaderItem(5, new QStandardItem(QObject::tr("Telephone")));
//    model->setHorizontalHeaderItem(6, new QStandardItem(QObject::tr("Postal Code")));
//    model->setHorizontalHeaderItem(7, new QStandardItem(QObject::tr("Duration")));
//    model->setHorizontalHeaderItem(8, new QStandardItem(QObject::tr("Date")));
//    model->setHorizontalHeaderItem(9, new QStandardItem(QObject::tr("Priority")));
//    model->setHorizontalHeaderItem(10, new QStandardItem(QObject::tr("Comment")));

//    ui->tableView_SearchClient->setModel(model);
}

void MainWindow::showClients(QStandardItemModel * model, vector<Client> v_clients)
{
    for(unsigned int i = 0; i < v_clients.size(); i ++)
    {
        model->setItem(i, 0, new QStandardItem(QString::number(v_clients[i].getId())));
        model->setItem(i, 1, new QStandardItem(v_clients[i].getFirstName()));
        model->setItem(i, 2, new QStandardItem(v_clients[i].getLastName()));
        model->setItem(i, 3, new QStandardItem(v_clients[i].getAddress()));
        model->setItem(i, 4, new QStandardItem(v_clients[i].getCity()));
        model->setItem(i, 5, new QStandardItem(QString::number(v_clients[i].getTelephone())));
        model->setItem(i, 6, new QStandardItem(QString::number(v_clients[i].getPostalCode())));
        model->setItem(i, 7, new QStandardItem(QString::number(v_clients[i].getDuration())));
        model->setItem(i, 8, new QStandardItem(v_clients[i].getDateAppointment().toString()));
        model->setItem(i, 9, new QStandardItem(QString::number(v_clients[i].getPriorityAppointment())));
        model->setItem(i, 10, new QStandardItem(v_clients[i].getComment()));
    }
    ui->tableView_SearchClient->setModel(model);
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
    qDebug()<<date;

    vector<Client> v_clients = controllerClient.searchClientsByDate(date);

    //ui->tableView_SearchClient->setColumnWidth(0, 10);

    refreshTableViewClients();
    //showClients(QStandardItemModel * model, v_clients);
}



void MainWindow::on_pushBtn_SearchByID_clicked()
{
    int id = ui->lineEdit_SearchByID->text().toInt();

    Client client = controllerClient.searchClientById(id);

    //ui->tableView_SearchClient->set
    cout<<client.getPostalCode()<<endl;
    ui->statusBar->showMessage("You have searched clients by ID.");
}

void MainWindow::on_pushBtn_SearchByName_clicked()
{
     QString name = ui->lineEdit_SearchByName->text();
     vector<Client> v_clients = controllerClient.searchClientsByName(name);

     for(int i = 0; i < v_clients.size(); i++){
         cout<<v_clients[i].getPostalCode()<<endl;
     }
      ui->statusBar->showMessage("You have searched clients by name.");
}
