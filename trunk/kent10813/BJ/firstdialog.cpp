#include "firstdialog.h"
#include "ui_firstdialog.h"

firstDialog::firstDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::firstDialog)
{
    ui->setupUi(this);
}

firstDialog::~firstDialog()
{
    delete ui;
}



void firstDialog::on_pushButton_clicked()
{
   MainWindow *dialog= new MainWindow;
   dialog->show();
   this->close();
}
