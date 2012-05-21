
#include "dealer_cards.h"
#include "ui_dealer_cards.h"
dealer_cards::dealer_cards(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dealer_cards)
{
    ui->setupUi(this);
    image.load("../BJ/images/green.jpg");
    gm= new Game;
    info= new information;
    gm->dealerTakeCards();
    ui->label->setNum(gm->dealerScore());
}

dealer_cards::~dealer_cards()
{
    delete ui;
}

void dealer_cards::on_pushButton_clicked()
{
    info->getLabel()->setNum(gm->dealerScore());
    info->show();
    this->close();
}
void dealer_cards::paintEvent(QPaintEvent *ev)
{
    qp.begin(this);
    qp.drawImage(0, 0, image.scaled(width(), height() ) );


    gm->dlr->show(qp);
    qp.end();
}

