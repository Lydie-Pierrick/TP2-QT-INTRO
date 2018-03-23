#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QStandardItemModel>
#include <QStringList>
#include <QApplication>
#include <QFileDialog>
#include <map>
#include "ui_mainwindow.h"
#include "dialogaddclient.h"
#include "dialogabout.h"
#include "dialogaddemployee.h"
#include "controller/controller_employee.h"
#include "controller/controller_client.h"
#include "dialogidentification.h"
#include "dialogmodifyemployee.h"
#include "dialogmodifyclient.h"
#include "dialogothers.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void addClient();
    void addEmployee();
    void modifyClient();
    void modifyEmployee();
    void initTreeViewRessources();
    void initTableViewClients();
    void refreshTableViewClients(vector<Client> v_clients);
    void initTableViewPlanning();
    void deletePointersTreeView();
    void deletePointersTableView();

    void on_actionAbout_triggered();
    void on_actionQuit_triggered();
    void on_actionClient_triggered();
    void on_actionClient_2_triggered();
    void on_actionEmployee_triggered();
    void on_actionEmployee_2_triggered();
    void on_treeView_Ressource_clicked(const QModelIndex &index);
    void on_pushBtn_ModifyEmployee_clicked();
    void on_pushBtn_DeleteEmployee_clicked();
    void on_pushBtn_SearchByDate_clicked();
    void on_pushBtn_RefreshEmployee_clicked();
    void on_treeView_Ressource_doubleClicked(const QModelIndex &index);
    void on_pushBtn_SearchByID_clicked();
    void on_pushBtn_SearchByName_clicked();
    void on_pushBtn_DeleteClient_clicked();
    void on_tableView_SearchClient_clicked(const QModelIndex &index);
    void on_pushBtn_ModifyClient_clicked();
    void on_tableView_SearchClient_doubleClicked();
    void on_tabWidget_tabBarClicked(int index);
    void on_pushBtn_Plan_clicked();
    void on_pushBtn_ShowResult_clicked();

    void on_pushBtn_Export_clicked();
    void on_pushButton_AddOtherEmployee_clicked();

    bool compareDate(Client const * c1, Client const * c2);

private:
    Ui::MainWindow *ui;
    Controller_employee controllerEmployee;
    Controller_client controllerClient;
    QStandardItemModel* modelTreeView;
    QStandardItemModel* modelTableView;

    vector<QStandardItem*> v_pointersTreeView;
    vector<QStandardItem*> v_pointersTableView;
};

#endif // MAINWINDOW_H
