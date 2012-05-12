#include "information.h"
#include "ui_information.h"

information::information(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::information)
{
    ui->setupUi(this);
    pl=new RealPlayer;
    dealer= new Dealer;
    gm= new Game;
    //ui->label_6->setNum(gm->setCash());
    //QObject::connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(on_label_6_linkActivated(QString)));
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

void information::showBets()
{
   // ui->label_6->setNum(gm->plr.makeBets());
}

void information::on_label_7_linkActivated(const QString &link)
{
    if (gm->dealerScore()>gm->playerScore())
        ui->label_7->setText("Дилер выиграл");
    if (gm->dealerScore()<gm->playerScore())
        ui->label_7->setText("Вы выиграли");
    if (gm->dealerScore()==gm->playerScore())
        ui->label_7->setText("Ничья");
}
void information::on_label_linkActivated(const QString &link)
{
    ui->label->setNum(gm->playerScore());
}
void information::on_label_4_linkActivated(const QString &link)
{
    ui->label_4->setNum(gm->dealerScore());
}
void information::on_label_6_linkActivated(const QString &link)
{
    ui->label_6->setNum(gm->plr.makeBets());
}
