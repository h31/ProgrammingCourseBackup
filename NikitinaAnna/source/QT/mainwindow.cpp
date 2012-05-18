#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isFirstClick = true;
   isReadCoordinateEnd = false;
   game=new Game;
   field=new Field;
   QObject::connect(game,SIGNAL(printFalseTurn()),this,SLOT(turnIsFalse()));
   QObject::connect(game,SIGNAL(end()),this,SLOT(printResult()));
}

MainWindow::~MainWindow()
{
    delete ui;

}
void MainWindow::paintEvent(QPaintEvent *event)
{
    qpaint.begin(this);
    playingBoard.load("board.jpg");
    qpaint.drawImage(40,40,playingBoard);
    if(game->isWhiteTurn)
    {
         turnPicture.load("whiteturn.jpg");
         qpaint.drawImage(800,400,turnPicture);
    }
    else
    {
         turnPicture.load("blackturn.jpg");
         qpaint.drawImage(800,400,turnPicture);
    }
 for(int i=0;i<8;i++)
  {
   for (int j=0; j<8; j++)
   {
       if(field->gameField[i][j]==whiteShashka)
       {
           int x = 60*i+74;
           int y = 60*j+74;
           shashka.load("whiteshashka.png");
           qpaint.drawPixmap(y,x,shashka);
       }
       if(field->gameField[i][j]==blackShashka)
       {
           int x = 60*i+74;
           int y = 60*j+74;
           shashka.load("blackshashka.png");
           qpaint.drawPixmap(y,x,shashka);
       }
       if(field->gameField[i][j]==blackKing)
       {
           int x = 60*i+74;
           int y = 60*j+74;
           shashka.load("blackking.png");
           qpaint.drawPixmap(y,x,shashka);
       }
       if(field->gameField[i][j]==whiteKing)
       {
           int x = 60*i+74;
           int y = 60*j+74;
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
       readCord.x = (p.ry()-74)/60;
       readCord.y = (p.rx()-74)/60;
       isReadCoordinateEnd = false;
       }
   }
   else
   {
       QPoint p;
       p=event->pos();
      readCord.Px = (p.ry()-74)/60;
       readCord.Py = (p.rx()-74)/60;
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
void MainWindow::printResult()
{
    if(game->winner==white)
        QMessageBox::information(this,"The end","White Player win!");
    if(game->winner==black)
        QMessageBox::information(this,"The end"," Black Player win!");
}
void MainWindow::turnIsFalse()
{

    QMessageBox::information(this,"Error","Turn is false!");
}

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
