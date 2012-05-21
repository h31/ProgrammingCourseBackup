#include "information.h"
#include "ui_information.h"
#include "play_again.h"
information::information(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::information)
{
    ui->setupUi(this);
}

QLabel* information::getLabel()
{
    return ui->label_4;
}
QLabel* information::getLabel2()
{
    return ui->label;
}
QLabel* information::getLabel3()
{
    return ui->label_6;
}
QLabel* information::getLabel4()
{
    return ui->label_7;
}
information::~information()
{
    delete ui;
}

void information::on_pushButton_clicked()
{
    play_again  *play= new play_again;
    play->show();
    this->close();
}
