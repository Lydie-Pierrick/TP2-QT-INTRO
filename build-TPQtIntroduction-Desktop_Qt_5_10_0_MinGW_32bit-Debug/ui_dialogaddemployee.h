/********************************************************************************
** Form generated from reading UI file 'dialogaddemployee.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGADDEMPLOYEE_H
#define UI_DIALOGADDEMPLOYEE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
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

class Ui_DialogAddEmployee
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_lastName;
    QLabel *label_type;
    QLineEdit *lineEdit_firstName;
    QLabel *label_firstName;
    QLineEdit *lineEdit_lastName;
    QComboBox *comboBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushBtn_reset;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogAddEmployee)
    {
        if (DialogAddEmployee->objectName().isEmpty())
            DialogAddEmployee->setObjectName(QStringLiteral("DialogAddEmployee"));
        DialogAddEmployee->resize(400, 300);
        gridLayoutWidget = new QWidget(DialogAddEmployee);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(19, 19, 367, 231));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_lastName = new QLabel(gridLayoutWidget);
        label_lastName->setObjectName(QStringLiteral("label_lastName"));

        gridLayout->addWidget(label_lastName, 1, 0, 1, 1);

        label_type = new QLabel(gridLayoutWidget);
        label_type->setObjectName(QStringLiteral("label_type"));

        gridLayout->addWidget(label_type, 2, 0, 1, 1);

        lineEdit_firstName = new QLineEdit(gridLayoutWidget);
        lineEdit_firstName->setObjectName(QStringLiteral("lineEdit_firstName"));

        gridLayout->addWidget(lineEdit_firstName, 0, 1, 1, 1);

        label_firstName = new QLabel(gridLayoutWidget);
        label_firstName->setObjectName(QStringLiteral("label_firstName"));

        gridLayout->addWidget(label_firstName, 0, 0, 1, 1);

        lineEdit_lastName = new QLineEdit(gridLayoutWidget);
        lineEdit_lastName->setObjectName(QStringLiteral("lineEdit_lastName"));

        gridLayout->addWidget(lineEdit_lastName, 1, 1, 1, 1);

        comboBox = new QComboBox(gridLayoutWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout->addWidget(comboBox, 2, 1, 1, 1);

        horizontalLayoutWidget = new QWidget(DialogAddEmployee);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 260, 361, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushBtn_reset = new QPushButton(horizontalLayoutWidget);
        pushBtn_reset->setObjectName(QStringLiteral("pushBtn_reset"));

        horizontalLayout->addWidget(pushBtn_reset);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(horizontalLayoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        retranslateUi(DialogAddEmployee);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogAddEmployee, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogAddEmployee, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogAddEmployee);
    } // setupUi

    void retranslateUi(QDialog *DialogAddEmployee)
    {
        DialogAddEmployee->setWindowTitle(QApplication::translate("DialogAddEmployee", "Dialog", nullptr));
        label_lastName->setText(QApplication::translate("DialogAddEmployee", "Last Name :", nullptr));
        label_type->setText(QApplication::translate("DialogAddEmployee", "Type:", nullptr));
        label_firstName->setText(QApplication::translate("DialogAddEmployee", "First Name : ", nullptr));
        comboBox->setItemText(0, QApplication::translate("DialogAddEmployee", "Banker A", nullptr));
        comboBox->setItemText(1, QApplication::translate("DialogAddEmployee", "Banker B", nullptr));
        comboBox->setItemText(2, QApplication::translate("DialogAddEmployee", "Housing Insurer", nullptr));
        comboBox->setItemText(3, QApplication::translate("DialogAddEmployee", "Car Insurer", nullptr));
        comboBox->setItemText(4, QApplication::translate("DialogAddEmployee", "Life Insurer", nullptr));
        comboBox->setItemText(5, QApplication::translate("DialogAddEmployee", "Computer Scientist", nullptr));
        comboBox->setItemText(6, QApplication::translate("DialogAddEmployee", "Other", nullptr));

        pushBtn_reset->setText(QApplication::translate("DialogAddEmployee", "Reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogAddEmployee: public Ui_DialogAddEmployee {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGADDEMPLOYEE_H
