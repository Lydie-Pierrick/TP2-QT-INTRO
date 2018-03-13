 #ifndef DIALOGADDEMPLOYEE_H
#define DIALOGADDEMPLOYEE_H
#include <QDialog>
#include <QMessageBox>
#include <iostream>
#include "ui_dialogaddemployee.h"
#include "controller/controller_employee.h"

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
    void on_comboBox_Type_activated(const QString &arg1);

private:
    Ui::DialogAddEmployee *ui;
    Controller_employee controllerEmployee;
    bool colorBoderFail();
};

#endif // DIALOGADDEMPLOYEE_H
