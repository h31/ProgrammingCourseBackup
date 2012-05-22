#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sizeBoard=40;
    plateX=800;plateY=400;
    number=8;
    denom=60;sum=74;
    isFirstClick = true;
   isReadCoordinateEnd = false;
   game=new Game;
   field=new Field;
   //QObject::connect(game,SIGNAL(printFalseTurn()),this,SLOT(turnIsFalse()));
   //QObject::connect(game,SIGNAL(end()),this,SLOT(printResult()));
}

MainWindow::~MainWindow()
{
    delete ui;

}
void MainWindow::paintEvent(QPaintEvent *event)
{
    qpaint.begin(this);
    playingBoard.load("board.jpg");
    qpaint.drawImage(sizeBoard,sizeBoard,playingBoard);
    if(game->isWhiteTurn)
    {
         turnPicture.load("whiteturn.jpg");
         qpaint.drawImage(plateX,plateY,turnPicture);
    }
    else
    {
         turnPicture.load("blackturn.jpg");
         qpaint.drawImage(plateX,plateY,turnPicture);
    }
 for(int i=0;i<number;i++)
  {
   for (int j=0; j<number; j++)
   {
       if(field->gameField[i][j]==whiteShashka)
       {
           int x = denom*i+sum;
           int y = denom*j+sum;
           shashka.load("whiteshashka.png");
           qpaint.drawPixmap(y,x,shashka);
       }
       if(field->gameField[i][j]==blackShashka)
       {
           int x = denom*i+sum;
           int y = denom*j+sum;
           shashka.load("blackshashka.png");
           qpaint.drawPixmap(y,x,shashka);
       }
       if(field->gameField[i][j]==blackKing)
       {
           int x = denom*i+sum;
           int y = denom*j+sum;
           shashka.load("blackking.png");
           qpaint.drawPixmap(y,x,shashka);
       }
       if(field->gameField[i][j]==whiteKing)
       {
           int x = denom*i+sum;
           int y = denom*j+sum;
           shashka.load("whiteking.png");
           qpaint.drawPixmap(y,x,shashka);
       }
   }
  }
    qpaint.end();
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
        leftButtonPressEvent(event);
}
void MainWindow::leftButtonPressEvent(QMouseEvent * event)
{
    repaint();
    int variable=0;
   if (isFirstClick)
   {
       if(variable==1)
       {
           readCord.x =readCord.Px;
           readCord.y =readCord.Py;
       }
       else
       {
       QPoint p;

       p = event->pos();
       readCord.x = (p.ry()-sum)/denom;
       readCord.y = (p.rx()-sum)/denom;
       isReadCoordinateEnd = false;
       }
   }
   else
   {
       QPoint p;
       p=event->pos();
      readCord.Px = (p.ry()-sum)/denom;
       readCord.Py = (p.rx()-sum)/denom;
       isReadCoordinateEnd = true;
   }
   isFirstClick =!isFirstClick;
    if(isReadCoordinateEnd)
    {
       if (game->result(readCord.Px,readCord.Py,readCord.x,readCord.y,variable,*field,checker,king,player)==true)
               repaint();
      game->findWinner(*field);
    }
      repaint();
}
/*void MainWindow::printResult()
{
    if(game->winner==white)
        QMessageBox::information(this,"The end","White Player win!");
    if(game->winner==black)
        QMessageBox::information(this,"The end"," Black Player win!");
}
void MainWindow::turnIsFalse()
{

    QMessageBox::information(this,"Error","Turn is false!");
}*/

void MainWindow::on_pushButton_clicked()
{
    if (QMessageBox::question(this, "Question",
                              "Open a new game?",
                              QMessageBox::Yes,
                              QMessageBox::No)==QMessageBox::Yes)
    {
   field=new Field;
   game=new Game;
   repaint();
    }
}
