#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isFirstClick = true;
    isReadCoordinateEnd = false;
    game = new Player;
    //connect(game, SIGNAL(readMouseCoordiante()),*this,SLOT(readCoordinates()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

 void MainWindow::leftButtonPressEvent(QMouseEvent * event)
{
    if (isFirstClick)
    {
        QPoint p;
        p = event->pos();
        readCord.startX = (p.rx()-30+78)/78;
        readCord.startY = (p.ry()-11+78)/78;
        isReadCoordinateEnd = false;
        QMessageBox::information(this,"","Start coordinate is read");
    }
    else
    {
        QPoint p;
        p=event->pos();
        readCord.finishX = (p.rx()-30+78)/78;
        readCord.finishY = (p.ry()-11+78)/78;
        isReadCoordinateEnd = true;
        QMessageBox::information(this,"","Finish coordinate is read");
    }
    isFirstClick =!isFirstClick;

    if(isReadCoordinateEnd)
    {
       game->makePlayerTurn(readCord.startX,readCord.startY,readCord.finishX,readCord.finishY);
      // QMessageBox::information(this,"","make turn");
       repaint();
    }
}

void MainWindow::paintEvent(QPaintEvent *ev)
{
     qp.begin(this);
//    qp.drawRect(QRect(50, 70, 100, 120));
     desk.load("playingboard.jpg");
     qp.drawImage(40,60,desk);

     for(int i=0;i<32;i++)
     {
         if(game->desk->getFigure(i)->isEat() == false)
            game->desk->getFigure(i)->printFigure(qp);
     }
     qp.end();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
        leftButtonPressEvent(event);
}

