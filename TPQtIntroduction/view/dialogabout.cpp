#include "dialogabout.h"
#include "ui_dialogabout.h"

// Constructor
DialogAbout::DialogAbout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAbout)
{
    ui->setupUi(this);
}

// Destructor
DialogAbout::~DialogAbout()
{
    delete ui;
}

// When the user close About Windows, just close
void DialogAbout::on_pushButton_Close_clicked()
{
    close();
}
