/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionClient;
    QAction *actionQuit;
    QAction *actionEmployee;
    QAction *actionAbout;
    QAction *actionClient_2;
    QAction *actionEmployee_2;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuiFile;
    QMenu *menuAjouter;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        actionClient = new QAction(MainWindow);
        actionClient->setObjectName(QStringLiteral("actionClient"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionEmployee = new QAction(MainWindow);
        actionEmployee->setObjectName(QStringLiteral("actionEmployee"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionClient_2 = new QAction(MainWindow);
        actionClient_2->setObjectName(QStringLiteral("actionClient_2"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/icons/client.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClient_2->setIcon(icon);
        actionEmployee_2 = new QAction(MainWindow);
        actionEmployee_2->setObjectName(QStringLiteral("actionEmployee_2"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/icons/employee.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEmployee_2->setIcon(icon1);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        menuiFile = new QMenu(menuBar);
        menuiFile->setObjectName(QStringLiteral("menuiFile"));
        menuAjouter = new QMenu(menuiFile);
        menuAjouter->setObjectName(QStringLiteral("menuAjouter"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuiFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuiFile->addAction(menuAjouter->menuAction());
        menuiFile->addAction(actionQuit);
        menuAjouter->addAction(actionClient);
        menuAjouter->addAction(actionEmployee);
        menuHelp->addAction(actionAbout);
        mainToolBar->addAction(actionClient_2);
        mainToolBar->addAction(actionEmployee_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionClient->setText(QApplication::translate("MainWindow", "Client", nullptr));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", nullptr));
        actionEmployee->setText(QApplication::translate("MainWindow", "Employee", nullptr));
        actionAbout->setText(QApplication::translate("MainWindow", "About", nullptr));
        actionClient_2->setText(QApplication::translate("MainWindow", "Client", nullptr));
        actionEmployee_2->setText(QApplication::translate("MainWindow", "Employee", nullptr));
        menuiFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuAjouter->setTitle(QApplication::translate("MainWindow", "Add", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
