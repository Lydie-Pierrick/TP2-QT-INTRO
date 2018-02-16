#ifndef DIALOGADDCLIENT_H
#define DIALOGADDCLIENT_H

#include <QDialog>
#include <iostream>

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

    void on_buttonBox_accepted();

    void on_pushButton_clicked();

private:
    Ui::DialogAddClient *ui;
};

#endif // DIALOGADDCLIENT_H
