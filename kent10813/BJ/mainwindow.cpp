#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::MainWindow)
{
ui->setupUi(this);
im.load("../BJ/images/green.jpg");
game = new Game;



}

MainWindow::~MainWindow()
{
delete ui;
}
void MainWindow::paintEvent(QPaintEvent *event)
{
pen.begin(this);
pen.drawImage(0, 0, im.scaled(width(), height() ) );



 printFirstDispensation();
 pen.end();
}
void MainWindow::printFirstDispensation()
{
    game->plr.takeCards();
    game->plr.show(pen);
    pen.end();
}

void MainWindow::on_pushButton_clicked()
{
    game->plr.takeCards();
    game->plr.show(pen);
    this->repaint();
}

void MainWindow::on_pushButton_2_clicked()
{
    dealer_cards *dealer_crd= new dealer_cards;
    dealer_crd->show();
    this->close();
}