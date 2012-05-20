#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::MainWindow)
{
ui->setupUi(this);
im.load("../BJ/images/green.jpg");
game = new Game;
dealer_crd= new dealer_cards;
game->plr->takeCards();
game->plr->takeCards();
ui->label->setNum(game->playerScore());

}

MainWindow::~MainWindow()
{
delete ui;
}
void MainWindow::paintEvent(QPaintEvent *event)
{
pen.begin(this);
pen.drawImage(0, 0, im.scaled(width(), height() ) );
game->plr->show(pen);

pen.end();
}


void MainWindow::on_pushButton_clicked()
{
    pen.begin(this);
    game->plr->takeCards();
    game->plr->show(pen);
    ui->label->setNum(game->playerScore());
    pen.end();
    this->repaint();
}

void MainWindow::on_pushButton_2_clicked()
{

    dealer_crd->show();
    this->close();
}

