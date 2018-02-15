/********************************************************************************
** Form generated from reading UI file 'dialogidentification.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGIDENTIFICATION_H
#define UI_DIALOGIDENTIFICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogIdentification
{
public:
    QWidget *gridLayoutWidget_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *label_Username;
    QLineEdit *lineEdit_Username;
    QLabel *label_Password;
    QLineEdit *lineEdit_Password;
    QPushButton *pushBtn_Cancel;
    QPushButton *pushBtn_Login;

    void setupUi(QDialog *DialogIdentification)
    {
        if (DialogIdentification->objectName().isEmpty())
            DialogIdentification->setObjectName(QStringLiteral("DialogIdentification"));
        DialogIdentification->resize(400, 179);
        gridLayoutWidget_2 = new QWidget(DialogIdentification);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(65, 40, 271, 101));
        verticalLayout = new QVBoxLayout(gridLayoutWidget_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_Username = new QLabel(gridLayoutWidget_2);
        label_Username->setObjectName(QStringLiteral("label_Username"));
        QFont font;
        font.setPointSize(12);
        label_Username->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_Username);

        lineEdit_Username = new QLineEdit(gridLayoutWidget_2);
        lineEdit_Username->setObjectName(QStringLiteral("lineEdit_Username"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_Username);

        label_Password = new QLabel(gridLayoutWidget_2);
        label_Password->setObjectName(QStringLiteral("label_Password"));
        label_Password->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_Password);

        lineEdit_Password = new QLineEdit(gridLayoutWidget_2);
        lineEdit_Password->setObjectName(QStringLiteral("lineEdit_Password"));
        lineEdit_Password->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_Password);


        gridLayout->addLayout(formLayout, 0, 0, 1, 2);

        pushBtn_Cancel = new QPushButton(gridLayoutWidget_2);
        pushBtn_Cancel->setObjectName(QStringLiteral("pushBtn_Cancel"));
        QFont font1;
        font1.setPointSize(11);
        pushBtn_Cancel->setFont(font1);
        pushBtn_Cancel->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushBtn_Cancel, 1, 1, 1, 1);

        pushBtn_Login = new QPushButton(gridLayoutWidget_2);
        pushBtn_Login->setObjectName(QStringLiteral("pushBtn_Login"));
        pushBtn_Login->setFont(font1);

        gridLayout->addWidget(pushBtn_Login, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(DialogIdentification);

        QMetaObject::connectSlotsByName(DialogIdentification);
    } // setupUi

    void retranslateUi(QDialog *DialogIdentification)
    {
        DialogIdentification->setWindowTitle(QApplication::translate("DialogIdentification", "Login", nullptr));
        label_Username->setText(QApplication::translate("DialogIdentification", "Username", nullptr));
        label_Password->setText(QApplication::translate("DialogIdentification", "Password", nullptr));
        pushBtn_Cancel->setText(QApplication::translate("DialogIdentification", "Cancel", nullptr));
        pushBtn_Login->setText(QApplication::translate("DialogIdentification", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogIdentification: public Ui_DialogIdentification {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGIDENTIFICATION_H
