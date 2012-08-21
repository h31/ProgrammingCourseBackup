#include<QtDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFile>
#include<QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    testVar=2;
    sizeBoard=40;
    plateX=800;plateY=400;
    number=8;
    denom=59;sum=77;
}

MainWindow::~MainWindow()
{
    delete ui;

}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
        leftButtonPressEvent(event);
}
void MainWindow::leftButtonPressEvent(QMouseEvent * event)
{
    if(testVar==1)
    {
    repaint();
    isReadCoordinateEnd = false;
   if (isFirstClick)
   {
       QPoint p;
       p = event->pos();
       readCord.x = (p.ry()-sum)/denom;
       readCord.y = (p.rx()-sum)/denom;
     }
   if(!isFirstClick)
   {
       QPoint p;
       p=event->pos();
      readCord.Px = (p.ry()-sum)/denom;
       readCord.Py = (p.rx()-sum)/denom;
      isReadCoordinateEnd = true;
   }
    repaint();
   if(game->test(readCord.x,readCord.y, *field)==false)
   isFirstClick =!isFirstClick;
    if(isReadCoordinateEnd==true)
    {
        if(game->getpox()!=-1 &&(readCord.x!=game->getpox() || readCord.y!=game->getpoy()))
             emit wrongMove();
        else
        {
       if (game->result(readCord.Px,readCord.Py,readCord.x,readCord.y,*field,checker,king,player)==true)
               repaint();
               /*if(time==true)
               {
              timer->stop();
              timer->start(5000);
               }*/
      game->findWinner(*field);
        }
    }
    }
}
void MainWindow::paintEvent(QPaintEvent *event)
{
        qpaint.begin(this);
    if(testVar==2 )
    {
            paint.load("paint.jpg");
            qpaint.drawImage(50,50,paint);
}
    if(testVar==1)
    {
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
  if (isFirstClick && !isReadCoordinateEnd)
   {
     qpaint.setPen(QPen(Qt::red,3));
      qpaint.drawRect(denom*readCord.y+sum, denom*readCord.x+sum,60,60);
   }
   if (!isFirstClick)
   {
     qpaint.setPen(QPen(Qt::red,3));
      qpaint.drawRect(denom*readCord.Py+sum, denom*readCord.Px+sum,60,60);
   }
}

    qpaint.end();
}
void MainWindow::printResult()
{
    //if(time==true)
    //timer->stop();
    next=5;
   int* Array=new int[next];
    QFile file("D://chernovik.txt");
     file.open(QIODevice::ReadOnly);
     QTextStream in(&file);
     for(int i=0;!in.atEnd();i++)
         Array[i]=in.readLine().toInt();
     file.close();
     QString string;
    if(game->winner==white)
    {
        string.append("Game over.White Player win!\r\n Your account:");
        string.append(QString::number(field->getSumWhite()));
        string.append("\r\n");
        for(int i=0;i<next;i++)
        {
            while(field->getSumWhite()>Array[i] &&(i==0 || field->getSumWhite()<Array[i-1]))
            {
                var=Array[i];
                Array[i]=field->getSumWhite();
                field->setSumWhite(var);
                if(i<next-1)
                i++;
            }
        }
    }
    if(game->winner==black)
    {
        string.append("Game over.Black Player win!\r\n Your account:");
        string.append(QString::number(field->getSumBlack()));
         string.append("\r\n");
        for(int i=0;i<next;i++)
        {
            while(field->getSumBlack()>Array[i] &&(i==0 || field->getSumBlack()<Array[i-1]))
            {
                var=Array[i];
                Array[i]=field->getSumBlack();
                field->setSumBlack(var);
                if(i<next-1)
                i++;
            }
        }
    }
    QMessageBox::information(this,"The end",string);
   file.open(QIODevice::WriteOnly | QIODevice::Truncate);
    QTextStream out(&file);
        for(int i=0;i<next;i++)
        {
       out<<Array[i]<<"\r\n";
        }
    file.close();
delete[] Array;
}
void MainWindow::turnIsFalse()
{
QMessageBox::information(this,"Error","Turn is false!");
}
void MainWindow::empty2()
{
QMessageBox::information(this,"Error","Empty!");
}
void MainWindow::strangeStroke()
{
QMessageBox::information(this,"Error","Strange stroke!");
}
void MainWindow::falseTurns()
{
    //timer->stop();
    QMessageBox::information(this,"Error","A checker should make <<shock>> move!");
   //timer->start(5000);
}
void MainWindow::wrong()
{
    QMessageBox::information(this,"Error","You have to walk a previous checker!");
}
void MainWindow::on_pushButton_4_clicked()
{
    next=5;
   int* Array=new int[next];
    QFile file("D://chernovik.txt");
     file.open(QIODevice::ReadOnly);
     QTextStream in(&file);
     for(int i=0;!in.atEnd();i++)
         Array[i]=in.readLine().toInt();
     file.close();
     QString str;
    for(int i=0;i<next;i++)
    {
        str.append(QString::number(i+1));
        str.append(")");
        str.append(QString::number(Array[i]));
         str.append("\r\n");
    }
 QMessageBox::information(this,"The best results", str);
     delete[] Array;
}

/*void MainWindow::onTimeout()
{
     //timer->stop();
    QMessageBox::information(this,"Timer","Your turn passes to the next player!");
    game->isWhiteTurn=!game->isWhiteTurn;
   //timer->start(5000);
    repaint();
}*/
void MainWindow::on_pushButton_2_clicked()
{
    if(testVar!=1)
            QMessageBox::information(this,"Error","Game is not save!");
    else
    {
    if (QMessageBox::question(this, "Question",
                              "Save game?",
                              QMessageBox::Yes,
                              QMessageBox::No)==QMessageBox::Yes )
        {
    QFile filek("D://saveGame.txt");
    filek.open(QIODevice::WriteOnly);
    QTextStream outText(&filek);
     outText<<game->isWhiteTurn<<"\r\n";
       for(int i=0;i<8;i++)
       {
        for(int j=0;j<8;j++)
        {
            outText<<i<<"\r\n";
            outText<<j<<"\r\n";
            outText<<field->gameField[i][j]<<"\r\n";

        }
      }
     filek.close();
}
}
}
void MainWindow::on_pushButton_3_clicked()
{
    if (QMessageBox::question(this, "Question",
                              "Open save game?",
                              QMessageBox::Yes,
                              QMessageBox::No)==QMessageBox::Yes)
    {
         //timer = new QTimer(this);
        testVar=1;
         isFirstClick =true;
        isReadCoordinateEnd = false;
        game=new Game;
       field=new Field;
       //QObject::connect(timer, SIGNAL(timeout()), SLOT(onTimeout()));
       QObject::connect(game,SIGNAL(printFalseTurn()),this,SLOT(turnIsFalse()));
       QObject::connect(game,SIGNAL(end()),this,SLOT(printResult()));
       QObject::connect(game,SIGNAL(falseTurn()),this,SLOT(falseTurns()));
       QObject::connect(this,SIGNAL(wrongMove()),this,SLOT(wrong()));
       QObject::connect(game,SIGNAL(empty1()),this,SLOT(empty2()));
       QObject::connect(game,SIGNAL(strangeStroke1()),this,SLOT(strangeStroke()));
       QFile filek("D://saveGame.txt");
       filek.open(QIODevice::ReadOnly);
       QTextStream inText(&filek);
       int typeOfShashka;int i;int j;
       game->isWhiteTurn=inText.readLine().toInt();
       while(!inText.atEnd())
       {

           i=inText.readLine().toInt();
           j=inText.readLine().toInt();
           typeOfShashka=inText.readLine().toInt();
           if(typeOfShashka==0)
                field->gameField[i][j]=empty;
           if(typeOfShashka==1)
                field->gameField[i][j]=whiteShashka;
           if(typeOfShashka==2)
                field->gameField[i][j]=blackShashka;
           if(typeOfShashka==8)
                field->gameField[i][j]=whiteKing;
           if(typeOfShashka==9)
                field->gameField[i][j]=blackKing;
       }
             filek.close();
    }

}

void MainWindow::on_pushButton_clicked()
{
    if (QMessageBox::question(this, "Question",
                              "Open a new game?",
                              QMessageBox::Yes,
                              QMessageBox::No)==QMessageBox::Yes)
    {
        /* timer = new QTimer(this);
         timer->stop();
        if (QMessageBox::question(this, "Question",
                               "Will you play with timer?",
                               QMessageBox::Yes,
                               QMessageBox::No)==QMessageBox::Yes)
        {
             timer->stop();
             timer->start(5000);
             time=true;
        }
        else
        {
         timer->stop();
        time=false;
        }*/
        testVar=1;
         isFirstClick = true;
        isReadCoordinateEnd = false;
        game=new Game;
        field=new Field;
        //QObject::connect(timer, SIGNAL(timeout()), SLOT(onTimeout()));
        QObject::connect(game,SIGNAL(printFalseTurn()),this,SLOT(turnIsFalse()));
        QObject::connect(game,SIGNAL(end()),this,SLOT(printResult()));
        QObject::connect(game,SIGNAL(falseTurn()),this,SLOT(falseTurns()));
        QObject::connect(this,SIGNAL(wrongMove()),this,SLOT(wrong()));
        QObject::connect(game,SIGNAL(empty1()),this,SLOT(empty2()));
        QObject::connect(game,SIGNAL(strangeStroke1()),this,SLOT(strangeStroke()));
}
}
