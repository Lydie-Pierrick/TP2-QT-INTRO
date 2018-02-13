#ifndef DIALOGIDENTIFICATION_H
#define DIALOGIDENTIFICATION_H

#include <QDialog>
#include <QMessageBox>
#include <QString>
#include <mainwindow.h>
#include <ui_dialogidentification.h>

using namespace std;

namespace Ui {
class DialogIdentification;
}

class DialogIdentification : public QDialog
{
    Q_OBJECT

public:
    explicit DialogIdentification(QWidget *parent = 0);
    ~DialogIdentification();

private slots:
    void on_pushBtn_Cancel_clicked();

    void on_pushBtn_Login_clicked();

private:
    Ui::DialogIdentification *ui;
    void checkLogin(QString username, QString password);
};

#endif // DIALOGIDENTIFICATION_H
