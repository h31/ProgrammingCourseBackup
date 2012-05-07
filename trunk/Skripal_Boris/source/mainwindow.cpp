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
    leftUp.setX(0);
    leftUp.setY(0);
   // connect(game->desk,SIGNAL(printShah()),this,SLOT(checkShah()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

 void MainWindow::leftButtonPressEvent(QMouseEvent * event)
{
     repaint();
    if (isFirstClick)
    {
        QPoint p;

        p = event->pos();
        readCord.startX = (p.rx()-50+77)/77;
        readCord.startY = (p.ry()+5)/77;
        leftUp.setX(readCord.startX*77-25);
        leftUp.setY(readCord.startY*77-7);
        isReadCoordinateEnd = false;
       //QMessageBox::information(this,"",QString( QString(readCord.startX+'0') + " " + QString(readCord.startY+'0') ));
    }
    else
    {
        QPoint p;
        p=event->pos();
        readCord.finishX = (p.rx()-50+77)/77;
        readCord.finishY = (p.ry()+5)/77;
        isReadCoordinateEnd = true;
       // QMessageBox::information(this,"","Finish coordinate is read");
    }
    isFirstClick =!isFirstClick;
    if(isReadCoordinateEnd)
    {
       game->makePlayerTurn(readCord.startX,readCord.startY,readCord.finishX,readCord.finishY);
      // QMessageBox::information(this,"","make turn");
       repaint();
//       if(game->getWhitePlayerTurnNow())
//           QMessageBox::information(this,"","White figures turn");
//       else
//            QMessageBox::information(this,"","Black figures turn");
    }
    repaint();
}

void MainWindow::paintEvent(QPaintEvent *ev)
{
     qp.begin(this);
     desk.load("playingboard.jpg");
     qp.drawImage(40,60,desk);

     if(game->getWhitePlayerTurnNow())
         turnPicture.load("whiteturn.jpg");
     else
         turnPicture.load("blackturn.jpg");

     qp.drawImage(800,300,turnPicture);
     for(int i=0;i<32;i++)
     {
         if(game->desk->getFigure(i)->isEat() == false)
            game->desk->getFigure(i)->printFigure(qp);
     }
     if(isFirstClick==false)
         qp.drawRect(leftUp.rx(),leftUp.ry(),77,77);
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

void MainWindow::on_actionPlayerWins_activated()
{
    QMessageBox::information(this,"Players wins",QString("White player wins: "+QString(game->getWhitePlayerWins()+'0')+ " "+"Black player wins: "+QString(game->getBlackPlayerWins()+'0')));
}
