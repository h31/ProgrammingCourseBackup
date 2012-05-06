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
   // connect(game->desk,SIGNAL(printShah()),this,SLOT(checkShah()));
    QMessageBox::information(this,"","White figures turn");
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
        readCord.startY = (p.ry()-11)/78;
        isReadCoordinateEnd = false;
       // QMessageBox::information(this,"",QString( QString(readCord.startX+'0') + " " + QString(readCord.startY+'0') ));
    }
    else
    {
        QPoint p;
        p=event->pos();
        readCord.finishX = (p.rx()-30+78)/78;
        readCord.finishY = (p.ry()-11)/78;
        isReadCoordinateEnd = true;
       // QMessageBox::information(this,"","Finish coordinate is read");
    }
    isFirstClick =!isFirstClick;

    if(isReadCoordinateEnd)
    {
       game->makePlayerTurn(readCord.startX,readCord.startY,readCord.finishX,readCord.finishY);
      // QMessageBox::information(this,"","make turn");
       repaint();
       if(game->getWhitePlayerTurnNow())
           QMessageBox::information(this,"","White figures turn");
       else
            QMessageBox::information(this,"","Black figures turn");
    }
}

void MainWindow::paintEvent(QPaintEvent *ev)
{
     qp.begin(this);
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

//void MainWindow::checkShah()
//{
//    QMessageBox::information(this,"","Вам шах");
//}


void MainWindow::on_actionNewGame_activated()
{
    isFirstClick = true;
    isReadCoordinateEnd = false;
    game->newGame();
    repaint();
}
