#ifndef DIALOGADDEMPLOYEE_H
#define DIALOGADDEMPLOYEE_H

#include <QDialog>
#include <iostream>

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
    void on_buttonBox_accepted();

private:
    Ui::DialogAddEmployee *ui;
};

#endif // DIALOGADDEMPLOYEE_H
