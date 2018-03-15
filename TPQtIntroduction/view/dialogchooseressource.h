#ifndef DIALOGCHOOSERESSOURCE_H
#define DIALOGCHOOSERESSOURCE_H

#include <QDialog>
#include <QStandardItemModel>
#include "controller/controller_employee.h"
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

private:
    Ui::DialogChooseRessource *ui;
    QStandardItemModel * modelTreeView;
    Controller_employee controllerEmployee;
};

#endif // DIALOGCHOOSERESSOURCE_H
