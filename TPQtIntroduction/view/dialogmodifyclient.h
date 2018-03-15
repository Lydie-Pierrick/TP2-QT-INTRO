#ifndef DIALOGMODIFYCLIENT_H
#define DIALOGMODIFYCLIENT_H
#include <QDialog>
#include "controller/controller_client.h"
#include <QMessageBox>
#include "ui_dialogmodifyclient.h"

namespace Ui {
class DialogModifyClient;
}

class DialogModifyClient : public QDialog
{
    Q_OBJECT

public:
    explicit DialogModifyClient(QWidget *parent = 0);
    ~DialogModifyClient();

private slots:
    void on_pushButton_ok_clicked();
    void on_pushButton_cancel_clicked();
    void on_pushButton_reset_clicked();
    bool colorBoderFail();

private:
    Ui::DialogModifyClient *ui;
    Controller_client controllerClient;
};

#endif // DIALOGMODIFYCLIENT_H
