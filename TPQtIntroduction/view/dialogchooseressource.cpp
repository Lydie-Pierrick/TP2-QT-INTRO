#include "dialogchooseressource.h"

// Constructor
DialogChooseRessource::DialogChooseRessource(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogChooseRessource)
{
    ui->setupUi(this);

    modelTreeView = new QStandardItemModel();
    initTreeViewRessources();
}

// Destructor
DialogChooseRessource::~DialogChooseRessource()
{
    delete ui;

    // Delete the pointer
    deletePointers();
}

// To init the tree view with data from Database
void DialogChooseRessource::initTreeViewRessources()
{
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
            itemId = new QStandardItem(QString::number(v_employees[j].getId()));
            itemName = new QStandardItem(v_employees[j].getLastname());

            itemType->setChild(j, 0, itemId);
            itemType->setChild(j, 1, itemName);

            // Set checkbox
            itemId->setCheckable(true);

            for(unsigned int k = 0; k < Controller_client::idsRes.size(); k ++)
            {
                // Get all the item checked
                if(itemId->text().toInt() == Controller_client::idsRes[k])
                    itemId->setCheckState(Qt::Checked);
            }

            itemId = NULL;
            itemName = NULL;
        }
        // Set item for model
        modelTreeView->setItem(i, 0, itemType);
        // Add pointer into vector
        v_pointers.push_back(itemType);
        itemType = NULL;
    }

    // Expand all the nodes
    ui->treeView_Ressource->expandAll();
}

// Funciton for deleting the pointer in treeView
void DialogChooseRessource::deletePointers()
{
    for(int i = 0 ; i < v_pointers.size(); i ++)
    {
        for(int j = 0; j < v_pointers[i]->rowCount(); j ++)
        {
            if(v_pointers[i]->child(j, 0) != NULL)
                delete v_pointers[i]->child(j, 0);
            if(v_pointers[i]->child(j, 1) != NULL)
                delete v_pointers[i]->child(j, 1);
        }

        if(v_pointers[i] != NULL)
        {
            delete v_pointers[i];
        }
    }

    v_pointers.clear();

    if(modelTreeView != NULL)
        delete modelTreeView;
}

// When the user want to cancel his action
void DialogChooseRessource::on_pushBtn_Cancel_clicked()
{
    reject();
}

// When the user comfirm. Treatment of client data.
void DialogChooseRessource::on_pushBtn_OK_clicked()
{
    int counter = 0;
    int id;
    vector<int> idsRes;

    for(int i = 0; i < modelTreeView->rowCount(); i ++)
    {
        for(int j= 0; j < modelTreeView->item(i, 0)->rowCount(); j ++)
        {
            if(modelTreeView->item(i, 0)->child(j, 0)->checkState() == Qt::Checked)
            {

                // Count the number of checked box
                counter ++;
                // Get selected ID
                id = modelTreeView->item(i, 0)->child(j, 0)->text().toInt();
                idsRes.push_back(id);
            }
        }
    }

    // Update Controller_client::idsRes and Controller_client::resNumber
    Controller_client::idsRes = idsRes;
    Controller_client::resNumber = counter;

    accept();
}
