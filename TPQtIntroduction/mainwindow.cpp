#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    createStatusBar();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionClient_triggered()
{
    DialogAddClient dc;

    dc.exec();
}

void MainWindow::on_actionAbout_triggered()
{
    DialogAbout da;

    da.exec();
}

void MainWindow::on_actionQuit_triggered()
{
    close();
}

void MainWindow::on_actionClient_2_triggered()
{
    on_actionClient_triggered();
}

void MainWindow::on_actionEmployee_triggered()
{
    DialogAddEmployee de;

    de.exec();
}

void MainWindow::on_actionEmployee_2_triggered()
{
    on_actionEmployee_triggered();
}

void MainWindow::createStatusBar()
{
    statusBar()->showMessage(tr("Ready"));
}
