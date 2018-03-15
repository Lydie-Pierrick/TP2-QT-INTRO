#include "dialogchooseressource.h"
#include "ui_dialogchooseressource.h"

DialogChooseRessource::DialogChooseRessource(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogChooseRessource)
{
    ui->setupUi(this);
}

DialogChooseRessource::~DialogChooseRessource()
{
    delete ui;
}
