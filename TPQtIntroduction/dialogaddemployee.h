#ifndef DIALOGADDEMPLOYEE_H
#define DIALOGADDEMPLOYEE_H

#include <QDialog>
#include <QMessageBox>
#include <iostream>
#include "ui_dialogaddemployee.h"
#include "controller_employee.h"

using namespace std;

namespace Ui {
class DialogAddEmployee;
}

class DialogAddEmployee : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddEmployee(QWidget *parent = 0);
    ~DialogAddEmployee();

private slots:
    void on_pushBtn_reset_clicked();
    void on_pushButton_cancel_clicked();

    void on_pushButton_ok_clicked();

private:
    Ui::DialogAddEmployee *ui;
    Controller_employee controller_employee;
};

#endif // DIALOGADDEMPLOYEE_H
