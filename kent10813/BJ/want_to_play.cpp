#include "want_to_play.h"

#include "ui_want_to_play.h"

want_to_play::want_to_play(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::want_to_play)
{
    ui->setupUi(this);
    dialog= new firstDialog;
}

want_to_play::~want_to_play()
{
    delete ui;
}

void want_to_play::on_pushButton_clicked()
{

    dialog->show();
    this->close();
}

void want_to_play::on_pushButton_2_clicked()
{
    this->close();
}
