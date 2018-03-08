#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QStandardItemModel>
#include <QStringList>
#include <QApplication>
#include <map>
#include "ui_mainwindow.h"
#include "dialogaddclient.h"
#include "dialogabout.h"
#include "dialogaddemployee.h"
#include "controller/controller_employee.h"
#include "dialogidentification.h"
#include "dialogmodifyemployee.h"

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
    void initTreeViewRessources();
    void on_actionAbout_triggered();
    void on_actionQuit_triggered();
    void on_actionClient_triggered();
    void on_actionClient_2_triggered();
    void on_actionEmployee_triggered();
    void on_actionEmployee_2_triggered();
    void on_treeView_Ressource_clicked(const QModelIndex &index);
    void on_pushBtn_Modify_clicked();
    void on_pushBtn_Delete_clicked();
    void on_pushBtn_SearchByIDName_clicked();
    void on_pushBtn_SearchByDate_clicked();

    void on_pushBtn_Refresh_clicked();

    void on_treeView_Ressource_doubleClicked(const QModelIndex &index);

    void on_pushBtn_SearchByID_clicked();

private:
    Ui::MainWindow *ui;
    Controller_employee controllerEmployee;
    Controller_client controllerClient;
};

#endif // MAINWINDOW_H
