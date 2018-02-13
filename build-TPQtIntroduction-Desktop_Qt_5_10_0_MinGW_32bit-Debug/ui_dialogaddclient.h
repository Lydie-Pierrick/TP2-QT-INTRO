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
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_DialogAddClient
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogAddClient)
    {
        if (DialogAddClient->objectName().isEmpty())
            DialogAddClient->setObjectName(QStringLiteral("DialogAddClient"));
        DialogAddClient->resize(400, 300);
        buttonBox = new QDialogButtonBox(DialogAddClient);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(DialogAddClient);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogAddClient, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogAddClient, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogAddClient);
    } // setupUi

    void retranslateUi(QDialog *DialogAddClient)
    {
        DialogAddClient->setWindowTitle(QApplication::translate("DialogAddClient", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogAddClient: public Ui_DialogAddClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGADDCLIENT_H
