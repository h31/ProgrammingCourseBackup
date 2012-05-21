#include "play_again.h"
#include "ui_play_again.h"
#include "firstdialog.h"
play_again::play_again(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::play_again)
{
    ui->setupUi(this);
}

play_again::~play_again()
{
    delete ui;
}

void play_again::on_pushButton_clicked()
{
    firstDialog *frst_dialog= new firstDialog;
    frst_dialog->show();
    this->close();
}

void play_again::on_pushButton_2_clicked()
{
    this->close();
}

