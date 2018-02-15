/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
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
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab_SearchClient;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_SearchClient;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_SearchClient;
    QSpacerItem *verticalSpacer;
    QTableView *tableView_SearchClient;
    QLineEdit *lineEdit_SearchClient;
    QWidget *tab_Planification;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QTableView *tableView_Planification;
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
        MainWindow->resize(750, 617);
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
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 721, 531));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(gridLayoutWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QPalette palette;
        QBrush brush(QColor(240, 240, 240, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush);
        tabWidget->setPalette(palette);
        tabWidget->setAutoFillBackground(false);
        tab_SearchClient = new QWidget();
        tab_SearchClient->setObjectName(QStringLiteral("tab_SearchClient"));
        gridLayoutWidget_2 = new QWidget(tab_SearchClient);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(0, 0, 711, 501));
        gridLayout_SearchClient = new QGridLayout(gridLayoutWidget_2);
        gridLayout_SearchClient->setSpacing(6);
        gridLayout_SearchClient->setContentsMargins(11, 11, 11, 11);
        gridLayout_SearchClient->setObjectName(QStringLiteral("gridLayout_SearchClient"));
        gridLayout_SearchClient->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(400, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_SearchClient->addItem(horizontalSpacer, 1, 0, 1, 1);

        pushButton_SearchClient = new QPushButton(gridLayoutWidget_2);
        pushButton_SearchClient->setObjectName(QStringLiteral("pushButton_SearchClient"));

        gridLayout_SearchClient->addWidget(pushButton_SearchClient, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_SearchClient->addItem(verticalSpacer, 0, 0, 1, 1);

        tableView_SearchClient = new QTableView(gridLayoutWidget_2);
        tableView_SearchClient->setObjectName(QStringLiteral("tableView_SearchClient"));

        gridLayout_SearchClient->addWidget(tableView_SearchClient, 3, 0, 1, 4);

        lineEdit_SearchClient = new QLineEdit(gridLayoutWidget_2);
        lineEdit_SearchClient->setObjectName(QStringLiteral("lineEdit_SearchClient"));

        gridLayout_SearchClient->addWidget(lineEdit_SearchClient, 1, 1, 1, 1);

        tabWidget->addTab(tab_SearchClient, QString());
        tab_Planification = new QWidget();
        tab_Planification->setObjectName(QStringLiteral("tab_Planification"));
        gridLayoutWidget_3 = new QWidget(tab_Planification);
        gridLayoutWidget_3->setObjectName(QStringLiteral("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(0, 0, 711, 501));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        tableView_Planification = new QTableView(gridLayoutWidget_3);
        tableView_Planification->setObjectName(QStringLiteral("tableView_Planification"));

        gridLayout_3->addWidget(tableView_Planification, 0, 0, 1, 1);

        tabWidget->addTab(tab_Planification, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 750, 21));
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

        tabWidget->setCurrentIndex(0);


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
        pushButton_SearchClient->setText(QApplication::translate("MainWindow", "Search", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_SearchClient), QApplication::translate("MainWindow", "Client Search", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Planification), QApplication::translate("MainWindow", "Planification", nullptr));
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
