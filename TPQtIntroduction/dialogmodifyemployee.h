#ifndef DIALOGMODIFYEMPLOYEE_H
#define DIALOGMODIFYEMPLOYEE_H

#include <QDialog>
#include <QMessageBox>
#include "controller_employee.h"

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
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::DialogModifyEmployee *ui;
    Controller_employee controllerEmployee;
};

#endif // DIALOGMODIFYEMPLOYEE_H
