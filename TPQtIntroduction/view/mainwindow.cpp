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
//    QStandardItemModel* model = new QStandardItemModel(ui->treeView_Ressource);
    QStandardItemModel* model = new QStandardItemModel();

    QStandardItem* rootNode = model->invisibleRootItem();

    map<string,QStandardItem*> typeList;
    //for()

    QStandardItem* bankerA = new QStandardItem("bankerA");
    QStandardItem* bankerB = new QStandardItem("bankerA");
//    model->setHorizontalHeaderLabels((QStringList() << QStringLiteral("ID")<<QStringLiteral("Last name")<<QStringLiteral("First name")<<QStringLiteral("Type")));



    // Get all Employee
    vector<Employee> v_records = controllerEmployee.getAllEmployees();
    for(unsigned int i = 0; i < v_records.size(); i ++) {
        model->setItem(i, 0, new QStandardItem(QString::number(v_records[i].getId(),10)));
        model->setItem(i, 1, new QStandardItem(v_records[i].getFirstname()));
        model->setItem(i, 2, new QStandardItem(v_records[i].getLastname()));
        model->setItem(i, 3, new QStandardItem(v_records[i].getType()));
    }

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
    Controller_employee::selectedID = id;
}

void MainWindow::on_treeView_Ressource_doubleClicked(const QModelIndex &index)
{
    QAbstractItemModel* itemModel=(QAbstractItemModel*)index.model();
    // Get content of the 1st column of selected line
    QModelIndex modelIndex = itemModel->index(index.row(), 0);
    int id = modelIndex.data().toInt();
    // Set selectedID
    Controller_employee::selectedID = id;

    // Open the dialog
    DialogModifyEmployee dme;

    if(dme.exec() == QDialog::Accepted)
    {
        ui->statusBar->showMessage("You have modified an employee !");
        initTreeViewRessources();
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

void MainWindow::on_pushBtn_SearchByIDName_clicked()
{
    QString strIDName = ui->lineEdit_SearchByIDName->text();
    ui->statusBar->showMessage("You have searched clients.");
    //Controller_client controller_client;
    //controller_client.searchClient()
}

void MainWindow::on_pushBtn_SearchByDate_clicked()
{
    QString dateAppointment = ui->dateEdit->text();
    ui->statusBar->showMessage("You have searched clients by date.");
    //Controller_client controller_client;
    //controller_client.searchClient()
}

void MainWindow::on_pushBtn_Refresh_clicked()
{
    ui->statusBar->showMessage("You have refreshed the list of employee !");
    initTreeViewRessources();
}


