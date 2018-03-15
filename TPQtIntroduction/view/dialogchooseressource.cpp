#include "dialogchooseressource.h"
#include "ui_dialogchooseressource.h"

DialogChooseRessource::DialogChooseRessource(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogChooseRessource)
{
    ui->setupUi(this);

    modelTreeView = new QStandardItemModel();
    initTreeViewRessources();
}

DialogChooseRessource::~DialogChooseRessource()
{
    delete ui;

    // Delete the pointer
    if(modelTreeView != nullptr_t())
        delete modelTreeView;
}

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
        }
        modelTreeView->setItem(i, 0, itemType);
    }
}
