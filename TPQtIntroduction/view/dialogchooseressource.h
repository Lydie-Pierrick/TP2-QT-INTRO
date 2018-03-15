#ifndef DIALOGCHOOSERESSOURCE_H
#define DIALOGCHOOSERESSOURCE_H

#include <QDialog>

namespace Ui {
class DialogChooseRessource;
}

class DialogChooseRessource : public QDialog
{
    Q_OBJECT

public:
    explicit DialogChooseRessource(QWidget *parent = 0);
    ~DialogChooseRessource();

private:
    Ui::DialogChooseRessource *ui;
};

#endif // DIALOGCHOOSERESSOURCE_H
