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
    test = new Test;
    leftUp.setX(0);
    leftUp.setY(0);
    QObject::connect(game->desk,SIGNAL(printShah()),this,SLOT(shahIsTrue()));
    QObject::connect(game,SIGNAL(printShah()),this,SLOT(shahIsTrue()));
    QObject::connect(game,SIGNAL(printFalseTurn()),this,SLOT(turnIsFalse()));
    QObject::connect(test,SIGNAL(testIsTrue()),this,SLOT(testIsTrue()));
    QObject::connect(test,SIGNAL(testIsFalse()),this,SLOT(turnIsFalse()));
    QObject::connect(game,SIGNAL(printMat()),this,SLOT(printMat()));
    QObject::connect(game,SIGNAL(turnWarTrue()),this,SLOT(appendTurn()));

    std::ifstream sett("setting.txt");
    sett>>hours>>minutes>>seconds>>blink;
    sett.close();
    timeWhite = new QTime;
    timeBlack = new QTime;
    timeWhite->setHMS(hours,minutes,seconds);
    timeBlack->setHMS(hours,minutes,seconds);
    QTime timeS;
    timeS.setHMS(hours,minutes,seconds);
    ui->timeEdit->setTime(timeS);
    ui->timeEdit_2->setTime(timeS);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(onTimerIsEnd()));
    connect(timer,SIGNAL(timeout()),this,SLOT(checkTimeOut()));
    timer->start(1000);

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
        Figure *checkFigure;
        checkFigure = NULL;
        for(int i=0;i<32;i++)
            if(game->desk->getFigure(i)->getX()==readCord.startX && game->desk->getFigure(i)->getY()==readCord.startY && game->desk->getFigure(i)->isEat()==false)
                checkFigure = game->desk->getFigure(i);
        if(checkFigure==NULL)
            isFirstClick=!isFirstClick;
        //delete checkFigure;
        isReadCoordinateEnd = false;
        blinkFigure=NULL;
        for(int i=0;i<32;i++)
        {
            if(game->desk->getFigure(i)->getX()==readCord.startX && game->desk->getFigure(i)->getY()==readCord.startY && game->desk->getFigure(i)->isEat()==false)
                blinkFigure = game->desk->getFigure(i);
        }
        blinkTimer = new QTimer;
        connect(blinkTimer,SIGNAL(timeout()),this,SLOT(blinkTimeOut()));
        if(blinkFigure!=NULL)
            blinkTimer->start(blink);
       //QMessageBox::information(this,"",QString( QString(readCord.startX+'0') + " " + QString(readCord.startY+'0') ));

    }
    else
    {
        QPoint p;
        p=event->pos();
        readCord.finishX = (p.rx()-50+77)/77;
        readCord.finishY = (p.ry()+5)/77;
        isReadCoordinateEnd = true;
        blinkTimer->stop();
        if(blinkFigure!=NULL)
             blinkFigure->eatFigure(false);
    }
    if(leftUp.rx()<650)
        isFirstClick =!isFirstClick;
    if(isReadCoordinateEnd)
    {
       game->makePlayerTurn(readCord.startX,readCord.startY,readCord.finishX,readCord.finishY);
       repaint();
    }
    repaint();
}

 void MainWindow::appendTurn()
 {
     ui->listWidget->addItem(QString( QString(readCord.startX+'A'-1) + " " + QString(readCord.startY+'0') ) +
                            " -> "+" "+QString( QString(readCord.finishX+'A'-1) + " " + QString(readCord.finishY+'0') ));
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
    //if(isFirstClick==false && leftUp.rx()<650)
       //  qp.drawRect(leftUp.rx()+2,leftUp.ry()+2,77,77);
     qp.end();


}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
        leftButtonPressEvent(event);
}

void MainWindow::on_actionNewGame_activated()
{
    ui->listWidget->clear();
    isFirstClick = true;
    isReadCoordinateEnd = false;
    QTime time1;
    std::ifstream sett("setting.txt");
    sett>>hours>>minutes>>seconds>>blink;
    sett.close();
    time1.setHMS(hours,minutes,seconds);
    timeWhite->setHMS(hours,minutes,seconds);
    timeBlack->setHMS(hours,minutes,seconds);
    ui->timeEdit->setTime(time1);
    ui->timeEdit_2->setTime(time1);
    game->newGame();
    repaint();
}

void MainWindow::on_actionPlayerWins_activated()
{
    QMessageBox::information(this,"Players wins",QString("White player wins: "+QString(game->getWhitePlayerWins()+'0')+ " "+"Black player wins: "+QString(game->getBlackPlayerWins()+'0')));
}

void MainWindow::shahIsTrue()
{
    QMessageBox::information(this,"","Shah is true!");
    return;
}

void MainWindow::turnIsFalse()
{
    QMessageBox::information(this,"","Turn is false! Repeat turn");
}

void MainWindow::testIsTrue()
{
    QMessageBox::information(this,"","Test is true!");
}
void MainWindow::testIsFalse()
{
    QMessageBox::information(this,"","Test is false!");
}

void MainWindow::on_actionTests_activated()
{
    test->tests();
}

void MainWindow::on_actionEnd_activated()
{
    ui->listWidget->clear();
    on_actionSave_activated();
    if(game->getWhitePlayerTurnNow())
        game->plusWinner(false);
    else
        game->plusWinner(true);
    //QTime time1;
    //timeWhite->setHMS(hours,minutes,seconds);
    //timeBlack->setHMS(hours,minutes,seconds);
    //ui->timeEdit->setTime(time1);
    //ui->timeEdit_2->setTime(time1);
    //game->newGame();
    on_actionNewGame_activated();
    repaint();
}

void MainWindow::printMat()
{
    if(game->getWinner()!=nobody)
    if(game->getWhitePlayerTurnNow()==false)
        QMessageBox::information(this,"Mat","White Player win!");
    else
        QMessageBox::information(this,"Mat"," Black Player win!");
}

void MainWindow::onTimerIsEnd()
{
   QTime time;
   if(game->getWhitePlayerTurnNow())
   {
       time.setHMS(timeWhite->hour(),timeWhite->minute(),timeWhite->second());
       QTime time2;
       time2 = time.addSecs(-1);
       timeWhite->setHMS(time2.hour(),time2.minute(),time2.second());
       ui->timeEdit->setTime(time2);
   }
   else
   {
       time.setHMS(timeBlack->hour(),timeBlack->minute(),timeBlack->second());
       QTime time2;
       time2 = time.addSecs(-1);
       timeBlack->setHMS(time2.hour(),time2.minute(),time2.second());
       ui->timeEdit_2->setTime(time2);
   }
}

void MainWindow::checkTimeOut()
{

    if(timeWhite->hour()==0 && timeWhite->minute()==0 && timeWhite->second()==0)
    {
        QMessageBox::information(this,"Time is over","Black Player win!");
       game->plusWinner(false);
       game->newGame();
    }
    if(timeBlack->hour()==0 && timeBlack->minute()==0&&timeBlack->second()==0)
    {
        QMessageBox::information(this,"Time is over","White Player win!");
       game->plusWinner(true);
       game->newGame();
    }
}

void MainWindow::on_actionSave_activated()
{
    ofstream fout("save.txt");
    if(fout.is_open()==false)
    {
        QMessageBox::information(this,"Error!", "Save file can not opened!");
        return;
    }
    fout<<game->getWhitePlayerWins()<<" "<<game->getBlackPlayerWins()<<std::endl;
    if(game->getWhitePlayerTurnNow()==true)
        fout<<1<<std::endl;
    else
        fout<<0<<std::endl;
    fout<<ui->timeEdit->time().hour()<<" "<<ui->timeEdit->time().minute()<<" "<<ui->timeEdit->time().second()<<std::endl;
    fout<<ui->timeEdit_2->time().hour()<<" "<<ui->timeEdit_2->time().minute()<<" "<<ui->timeEdit_2->time().second()<<std::endl;
    //обозначения при сохранении:
    //0-пешка, 1- король, 2- королева, 3- ладья, 4-конь, 5 - слон
    //0 - чёрная фигура, 1 - белая фигура
    //0 - фигура не съедена, 1 - фигура съедена
    //координаты фигуры
    //количество ходов, сделанных фигурой
    for(int i=0;i<32;i++)
    {
        fout<<(int) game->desk->getFigure(i)->getType()<<" ";

        if(game->desk->getFigure(i)->getColour()==true)
            fout<<1<<" ";
        else
            fout<<0<<" ";
        if(game->desk->getFigure(i)->isEat()==true)
            fout<<1<<" ";
        else
            fout<<0<<" ";
        fout<<game->desk->getFigure(i)->getX()<<" ";
        fout<<game->desk->getFigure(i)->getY()<<" ";
        fout<<game->desk->getFigure(i)->getStep();
        if (i!=31)
            fout<<std::endl;
    }
    if(game->desk->getTurnVecSize()==0)
        return;
    for(int i=0;i<game->desk->getTurnVecSize()-1;i++)
    {
        fout<<game->desk->getTurnVecElem(i)<<std::endl;
    }
    fout<<game->desk->getTurnVecElem(game->desk->getTurnVecSize()-1);
    fout.close();
    return;
}

void MainWindow::on_actionLoad_activated()
{
    ifstream fin("save.txt");
    if(fin.is_open()==false)
    {
        QMessageBox::information(this,"Error!", "Load file can not opened!");
        return;
    }
    game->newGame();
    ui->listWidget->clear();
    game->desk->clearTurnVec();
    int a,b,c,d,e,f;
    fin>>a>>b;
    game->setWins(true,a);
    game->setWins(false,b);
    fin>>a;
    if(a==1)
        game->setWhitePlayerTurn(true);
    else
        game->setWhitePlayerTurn(false);
    fin>>a>>b>>c;
    timeWhite->setHMS(a,b,c);
    fin>>a>>b>>c;
    timeBlack->setHMS(a,b,c);
    for(int i=0;i<32;i++)
    {
        fin>>a>>b>>c>>d>>e>>f;
        if(c==1)
            game->desk->getFigure(i)->eatFigure(true);
        game->desk->getFigure(i)->setX(d);
        game->desk->getFigure(i)->setY(e);
        for(int k=0;k<f;k++)
            game->desk->getFigure(i)->increaceSteps(true);
    }
    for(int i=0;!fin.eof();i++)
    {
        fin>>a>>b>>c>>d;
        TurnCoordinate coord(a,b,c,d);
        game->desk->setTurnVecElem(coord);
        ui->listWidget->addItem(QString( QString(a+'A'-1) + " " + QString(b+'0') ) +
           " -> "+" "+QString( QString(c+'A'-1) + " " + QString(d+'0') ));
    }
    repaint();
    fin.close();
    return;
}

void MainWindow::blinkTimeOut()
{
    blinkFigure->eatFigure(!blinkFigure->isEat());
    repaint();
}

void MainWindow::on_actionOptions_activated()
{
    optionDialog *dialog = new optionDialog;
    connect(dialog,SIGNAL(changesAccepted()),this,SLOT(chachgeSetting()));
    dialog->show();
}

void MainWindow::chachgeSetting()
{
    on_actionNewGame_activated();
}
