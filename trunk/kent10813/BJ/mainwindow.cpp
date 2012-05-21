#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "information.h"

MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::MainWindow)
{
ui->setupUi(this);
im.load("../BJ/images/green.jpg");
dealer_crd= new dealer_cards;
dealer_crd->gm->plr->takeCards();
dealer_crd->gm->plr->takeCards();
ui->label->setNum(dealer_crd->gm->playerScore());
}

MainWindow::~MainWindow()
{
delete ui;
}
void MainWindow::paintEvent(QPaintEvent *event)
{
pen.begin(this);
pen.drawImage(0, 0, im.scaled(width(), height() ) );
dealer_crd->gm->plr->show(pen);
pen.end();
}


void MainWindow::on_pushButton_clicked()
{
    pen.begin(this);

    dealer_crd->gm->plr->takeCards();
    dealer_crd->gm->plr->show(pen);
    ui->label->setNum(dealer_crd->gm->playerScore());
    pen.end();
    this->repaint();
}

void MainWindow::on_pushButton_2_clicked()
{
    dealer_crd->info->getLabel2()->setNum(dealer_crd->gm->playerScore());
    if (dealer_crd->gm->whoWon()==1)
        dealer_crd->info->getLabel4()->setText("You won");
    if (dealer_crd->gm->whoWon()==2)
         dealer_crd->info->getLabel4()->setText("Dealer won");
    if (dealer_crd->gm->whoWon()==3)
        dealer_crd->info->getLabel4()->setText("Draw");

    dealer_crd->show();
    this->close();
}

