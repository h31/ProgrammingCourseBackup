
#include "firstdialog.h"
#include "ui_firstdialog.h"
#include "Game.h"
firstDialog::firstDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::firstDialog)
{
    ui->setupUi(this);
    wn= new MainWindow;


}

firstDialog::~firstDialog()
{
    delete ui;
}



QString firstDialog::on_pushButton_clicked()
{
    bool ok1;
    QString default_name="Player";
    QString names = QInputDialog::getText(this, tr("Enter name"),
    tr("Your  name:"), QLineEdit::Normal, default_name, &ok1);
    if (!ok1||!names.isEmpty())
        names=default_name;
    return names;

}



int firstDialog::on_pushButton_2_clicked()
{
    bool ok2;
    int default_bet= 100;
    int bets= QInputDialog::getInt(this,tr("Bet"),tr("Your bet"),default_bet,0,200000000,100,&ok2);
    if (!ok2||bets<0)
        bets=default_bet;
        return bets;
}
void firstDialog::on_pushButton_3_clicked()
{
    name= ui->lineEdit->text();

   // QMessageBox::information(this,"",str);
 //   MainWindow *wn= new MainWindow;
    wn->show();
    this->close();
}

