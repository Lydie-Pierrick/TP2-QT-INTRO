#ifndef DIALOGMODIFYCLIENT_H
#define DIALOGMODIFYCLIENT_H
#include <QDialog>
#include "ui_dialogmodifyclient.h"
#include "controller/controller_client.h"
#include <QMessageBox>
#include "dialogchooseressource.h"

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

    void on_pushBtn_choose_clicked();

private:
    Ui::DialogModifyClient *ui;
    Controller_client controllerClient;
    DialogChooseRessource *dcr;
    DialogChooseRessource *dcrsave;
};

#endif // DIALOGMODIFYCLIENT_H
