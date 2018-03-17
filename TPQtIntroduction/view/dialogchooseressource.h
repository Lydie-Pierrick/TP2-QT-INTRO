#ifndef DIALOGCHOOSERESSOURCE_H
#define DIALOGCHOOSERESSOURCE_H

#include <QDialog>
#include <QStandardItemModel>
#include "ui_dialogchooseressource.h"
#include "controller/controller_employee.h"
#include "controller/controller_client.h"
namespace Ui {
class DialogChooseRessource;
}

class DialogChooseRessource : public QDialog
{
    Q_OBJECT

public:
    explicit DialogChooseRessource(QWidget *parent = 0);
    ~DialogChooseRessource();

    void initTreeViewRessources();

private slots:

    void on_pushBtn_Cancel_clicked();
    void on_pushBtn_OK_clicked();
private:

    Ui::DialogChooseRessource *ui;
    QStandardItemModel * modelTreeView;
    Controller_employee controllerEmployee;
};

#endif // DIALOGCHOOSERESSOURCE_H
