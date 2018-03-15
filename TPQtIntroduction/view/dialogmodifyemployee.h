#ifndef DIALOGMODIFYEMPLOYEE_H
#define DIALOGMODIFYEMPLOYEE_H
#include <QDialog>
#include <QMessageBox>
#include "controller/controller_employee.h"
#include "ui_dialogmodifyemployee.h"

namespace Ui {
class DialogModifyEmployee;
}

class DialogModifyEmployee : public QDialog
{
    Q_OBJECT

public:
    explicit DialogModifyEmployee(QWidget *parent = 0);
    ~DialogModifyEmployee();

private slots:
    void on_pushButton_ok_clicked();
    void on_pushButton_cancel_clicked();
    void on_comboBox_Type_activated(const QString &arg1);

private:
    Ui::DialogModifyEmployee *ui;
    Controller_employee controllerEmployee;
    bool colorBoderFail();
};

#endif // DIALOGMODIFYEMPLOYEE_H
