
#include "firstdialog.h"
#include "ui_firstdialog.h"
#include "Game.h"
firstDialog::firstDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::firstDialog)
{
    ui->setupUi(this);
    wn= new MainWindow;
    ui->lineEdit_2->text();
}

firstDialog::~firstDialog()
{
    delete ui;
}



void firstDialog::on_pushButton_3_clicked()
{
    name= ui->lineEdit->text();
    wn->dealer_crd->info->getLabel3()->setNum(2*(ui->lineEdit->text().toInt()));
   // QMessageBox::information(this,"",str);
 //   MainWindow *wn= new MainWindow;
    wn->show();
    this->close();
}

