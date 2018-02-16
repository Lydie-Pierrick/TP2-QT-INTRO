/********************************************************************************
** Form generated from reading UI file 'dialogaddclient.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGADDCLIENT_H
#define UI_DIALOGADDCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogAddClient
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_lastName;
    QLineEdit *lineEdit_firstName;
    QLineEdit *lineEdit_address;
    QLineEdit *lineEdit_postalCode;
    QLineEdit *lineEdit_city;
    QLineEdit *lineEdit_telephone;
    QLabel *label_firstName;
    QLabel *label_lastName;
    QLabel *label_telephone;
    QLabel *label_address;
    QLabel *labe_city;
    QLabel *label_postalCode;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogAddClient)
    {
        if (DialogAddClient->objectName().isEmpty())
            DialogAddClient->setObjectName(QStringLiteral("DialogAddClient"));
        DialogAddClient->resize(400, 300);
        gridLayoutWidget = new QWidget(DialogAddClient);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(19, 9, 351, 231));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_lastName = new QLineEdit(gridLayoutWidget);
        lineEdit_lastName->setObjectName(QStringLiteral("lineEdit_lastName"));

        gridLayout->addWidget(lineEdit_lastName, 1, 1, 1, 1);

        lineEdit_firstName = new QLineEdit(gridLayoutWidget);
        lineEdit_firstName->setObjectName(QStringLiteral("lineEdit_firstName"));

        gridLayout->addWidget(lineEdit_firstName, 0, 1, 1, 1);

        lineEdit_address = new QLineEdit(gridLayoutWidget);
        lineEdit_address->setObjectName(QStringLiteral("lineEdit_address"));

        gridLayout->addWidget(lineEdit_address, 3, 1, 1, 1);

        lineEdit_postalCode = new QLineEdit(gridLayoutWidget);
        lineEdit_postalCode->setObjectName(QStringLiteral("lineEdit_postalCode"));

        gridLayout->addWidget(lineEdit_postalCode, 5, 1, 1, 1);

        lineEdit_city = new QLineEdit(gridLayoutWidget);
        lineEdit_city->setObjectName(QStringLiteral("lineEdit_city"));

        gridLayout->addWidget(lineEdit_city, 4, 1, 1, 1);

        lineEdit_telephone = new QLineEdit(gridLayoutWidget);
        lineEdit_telephone->setObjectName(QStringLiteral("lineEdit_telephone"));

        gridLayout->addWidget(lineEdit_telephone, 2, 1, 1, 1);

        label_firstName = new QLabel(gridLayoutWidget);
        label_firstName->setObjectName(QStringLiteral("label_firstName"));

        gridLayout->addWidget(label_firstName, 0, 0, 1, 1);

        label_lastName = new QLabel(gridLayoutWidget);
        label_lastName->setObjectName(QStringLiteral("label_lastName"));

        gridLayout->addWidget(label_lastName, 1, 0, 1, 1);

        label_telephone = new QLabel(gridLayoutWidget);
        label_telephone->setObjectName(QStringLiteral("label_telephone"));

        gridLayout->addWidget(label_telephone, 2, 0, 1, 1);

        label_address = new QLabel(gridLayoutWidget);
        label_address->setObjectName(QStringLiteral("label_address"));

        gridLayout->addWidget(label_address, 3, 0, 1, 1);

        labe_city = new QLabel(gridLayoutWidget);
        labe_city->setObjectName(QStringLiteral("labe_city"));

        gridLayout->addWidget(labe_city, 4, 0, 1, 1);

        label_postalCode = new QLabel(gridLayoutWidget);
        label_postalCode->setObjectName(QStringLiteral("label_postalCode"));

        gridLayout->addWidget(label_postalCode, 5, 0, 1, 1);

        horizontalLayoutWidget = new QWidget(DialogAddClient);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(24, 250, 341, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(horizontalLayoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        retranslateUi(DialogAddClient);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogAddClient, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogAddClient, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogAddClient);
    } // setupUi

    void retranslateUi(QDialog *DialogAddClient)
    {
        DialogAddClient->setWindowTitle(QApplication::translate("DialogAddClient", "Dialog", nullptr));
        label_firstName->setText(QApplication::translate("DialogAddClient", "First Name :", nullptr));
        label_lastName->setText(QApplication::translate("DialogAddClient", "Last Name :", nullptr));
        label_telephone->setText(QApplication::translate("DialogAddClient", "Telephone : ", nullptr));
        label_address->setText(QApplication::translate("DialogAddClient", "Address :", nullptr));
        labe_city->setText(QApplication::translate("DialogAddClient", "City :", nullptr));
        label_postalCode->setText(QApplication::translate("DialogAddClient", "Postal Code :", nullptr));
        pushButton->setText(QApplication::translate("DialogAddClient", "Reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogAddClient: public Ui_DialogAddClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGADDCLIENT_H
