#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::MainWindow)
{
ui->setupUi(this);
im.load("../BJ/images/green.jpg");
game = new Game;
rpl =new RealPlayer;
dlr= new Dealer;



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
    rpl->takeCards();
    rpl->show(pen);
    pen.end();
}

void MainWindow::on_pushButton_clicked()
{
    rpl->takeCards();
    rpl->show(pen);
    this->repaint();
}

void MainWindow::on_pushButton_2_clicked()
{
    dealer_cards *dealer_crd= new dealer_cards;
    dealer_crd->show();
    this->close();
}
