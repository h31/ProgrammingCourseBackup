#include "information.h"
#include "ui_information.h"

information::information(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::information)
{
    ui->setupUi(this);
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
