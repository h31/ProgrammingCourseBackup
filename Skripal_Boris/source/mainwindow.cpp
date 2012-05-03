#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::paintEvent(QPaintEvent *event)
{
     qp.begin(this);
    // qp.setPen(QPen(red));
     qp.drawRect(QRect(50, 70, 100, 120));
     desk.load("playingboard.jpg");
     qp.drawImage(40,60,desk);

//     QPixmap blackrook;
//     blackrook.load("rookblack.png");
//     qp.drawPixmap(50,70,blackrook);

//     QPixmap blackknight;
//     blackknight.load("knightblack.png");
//     qp.drawPixmap(130,70,blackknight);

     for(int i=0;i<32;i++)
     {
         game.desk.getFigure(i)->printFigure(qp);
     }

    // pic.play(qp);
     qp.end();
}
