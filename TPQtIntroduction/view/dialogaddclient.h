#ifndef DIALOGADDCLIENT_H
#define DIALOGADDCLIENT_H

#include <QDialog>
#include <QMessageBox>
#include <iostream>
#include "ui_dialogaddclient.h"
#include "controller/controller_client.h"
#include "dialogchooseressource.h"

using namespace std;

namespace Ui {
class DialogAddClient;
}

class DialogAddClient : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddClient(QWidget *parent = 0);
    ~DialogAddClient();

private slots:
    void on_pushButton_reset_clicked();
    void on_pushButton_ok_clicked();
    void on_pushButton_cancel_clicked();
    bool colorBoderFail();

    void on_pushBtn_choose_clicked();

private:
    Ui::DialogAddClient *ui;
    Controller_client controller_client;
};

#endif // DIALOGADDCLIENT_H
