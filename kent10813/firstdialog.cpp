#include "firstdialog.h"
#include "ui_firstdialog.h"
#include "Game.h"
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



QString firstDialog::on_pushButton_clicked()
{
    bool ok1;
    QString default_name=" Enter name";
    QString names = QInputDialog::getText(this, tr("Player"),
    tr("Your  name:"), QLineEdit::Normal, default_name, &ok1);
    //if (ok1&&!name.isEmpty())
    return names;

}



int firstDialog::on_pushButton_2_clicked()
{
    bool ok2;
    int default_bet= 100;
    int bet= QInputDialog::getInt(this,tr("Bet"),tr("Your bet"),default_bet,0,200000000,100,&ok2);
   // if (ok2&&bet>0)
        return bet;
}


void firstDialog::on_pushButton_3_clicked()
{
    MainWindow *wn= new MainWindow;
    wn->show();
    this->close();
}
