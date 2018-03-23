#ifndef DIALOGOTHERS_H
#define DIALOGOTHERS_H

#include <QDialog>
#include <QMessageBox>
#include "controller/controller_employee.h"

namespace Ui {
class DialogOthers;
}

class DialogOthers : public QDialog
{
    Q_OBJECT

public:
    explicit DialogOthers(QWidget *parent = 0);
    ~DialogOthers();

private slots:
    void on_pushButton_Ok_clicked();

    void on_pushButton_Cancel_clicked();

private:
    Ui::DialogOthers *ui;
    Controller_employee controllerEmployee;
};

#endif // DIALOGOTHERS_H
