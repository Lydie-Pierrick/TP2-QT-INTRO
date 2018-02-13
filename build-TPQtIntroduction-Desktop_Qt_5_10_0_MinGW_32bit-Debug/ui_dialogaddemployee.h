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
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_DialogAddEmployee
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogAddEmployee)
    {
        if (DialogAddEmployee->objectName().isEmpty())
            DialogAddEmployee->setObjectName(QStringLiteral("DialogAddEmployee"));
        DialogAddEmployee->resize(400, 300);
        buttonBox = new QDialogButtonBox(DialogAddEmployee);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(DialogAddEmployee);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogAddEmployee, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogAddEmployee, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogAddEmployee);
    } // setupUi

    void retranslateUi(QDialog *DialogAddEmployee)
    {
        DialogAddEmployee->setWindowTitle(QApplication::translate("DialogAddEmployee", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogAddEmployee: public Ui_DialogAddEmployee {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGADDEMPLOYEE_H
