#include "mainwindow.h"-
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    BulletTimer = new QTimer;//для движения пули игрока
    BotTimer = new QTimer;//для движения бота
    BulletBotTimer = new QTimer;//для выпускания пули бота
    BBulletTimer = new QTimer;//для движения пули бота
    if ((test.proverkaFieldIgrok()==false)||(test.proverkaFieldBot()==false))
    {
        QMessageBox::information(this, "Test failed", "Test failed!");
        exit(0);
    }
    else
    {
        QMessageBox::information(this,"Test passed","Test passed!");

    }
    proverkaFieldIgrok();
    proverkaFieldBot();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent* ev)
{
    proverkaFieldIgrok();
    if (ev->key() == Qt::Key_W)
    {
        if (tank.koords.y-tank.r-tank.speed<tank.field.y1)
        {
            tank.koords.x=tank.koords.x;
            tank.koords.y=tank.koords.y;
        }
        else
        tank.koords.y=tank.koords.y-tank.speed;
        tank.vec.x=0;
        tank.vec.y=-2;
        repaint();
    }
    if (ev->key() == Qt::Key_S)
    {
        if (tank.koords.y+tank.r+tank.speed>tank.field.y2)
        {
            tank.koords.x=tank.koords.x;
            tank.koords.y=tank.koords.y;
        }
        else
        tank.koords.y=tank.koords.y+tank.speed;
        tank.vec.x=0;
        tank.vec.y=2;
        repaint();
    }
    if (ev->key() == Qt::Key_A)
    {
        if (tank.koords.x-tank.r-tank.speed<tank.field.x1)
        {
            tank.koords.x=tank.koords.x;
            tank.koords.y=tank.koords.y;
        }
        else
        tank.koords.x=tank.koords.x-tank.speed;
        tank.vec.x=-2;
        tank.vec.y=0;
        repaint();
    }
    if (ev->key() == Qt::Key_D)
    {
        if (tank.koords.x+tank.r+tank.speed>tank.field.x2)
        {
            tank.koords.x=tank.koords.x;
            tank.koords.y=tank.koords.y;
        }
        else
        tank.koords.x=tank.koords.x+tank.speed;
        tank.vec.x=2;
        tank.vec.y=0;
        repaint();
    }
    if (ev->key() == Qt::Key_Space)
    {
        Bullet b;//для пули описываю свойства а потом добавляю в вектор
        b.coords.x = tank.koords.x;
        b.coords.y = tank.koords.y;

        b.alpha.x = tank.vec.x;
        b.alpha.y = tank.vec.y;

        BulletTimer->start(800);
        connect(BulletTimer, SIGNAL(timeout()), SLOT(moveBulletOnTimeout()));

        tank.bullet.push_back(b);
    }
    connect(BotTimer, SIGNAL(timeout()), SLOT(driveBotOnTimeout()));
    BotTimer->start(1000);

    connect(BulletBotTimer, SIGNAL(timeout()), SLOT(hitBulletBotOnTimeout()));
    BulletBotTimer->start(3000);

    connect(BBulletTimer,SIGNAL(timeout()),SLOT(moveBotBulletOnTimeout()));
    BBulletTimer->start(800);


}
void MainWindow::paintEvent(QPaintEvent *event) //как передать сюда аргументы(координаты)
{
    QPainter painter;
    painter.begin(this);
    painter.setBrush(QBrush(Qt::green));//закрашивание прямоугольником
    painter.drawRect(tank.field.x1,tank.field.y1,tank.field.x2,tank.field.y2);
    drawIgrok(painter);
    drawBot(painter);

    for (int i=0;i<tank.bullet.size();i++)
    {
        tank.bullet[i].drawp(painter);
    }

    for (int j=0;j<bot.bbullet.size();j++)
    {
        bot.bbullet[j].drawp(painter);
    }
    painter.end();
}

void MainWindow::moveBulletOnTimeout()
{

    for (int i=0; i<tank.bullet.size(); i++)
    {
        tank.bullet[i].coords.x = tank.bullet[i].coords.x + tank.bullet[i].alpha.x * tank.bullet[i].speed;
        tank.bullet[i].coords.y = tank.bullet[i].coords.y + tank.bullet[i].alpha.y * tank.bullet[i].speed;
        if ( (tank.bullet[i].coords.x+tank.bullet[i].l * tank.bullet[i].alpha.x)>=(bot.koordsb.x-bot.r) && ((tank.bullet[i].coords.x+tank.bullet[i].l * tank.bullet[i].alpha.x)<=(bot.koordsb.x+bot.r)) &&
            ((tank.bullet[i].coords.y+tank.bullet[i].l * tank.bullet[i].alpha.y)>=(bot.koordsb.y-bot.r)) && ((tank.bullet[i].coords.y+tank.bullet[i].l * tank.bullet[i].alpha.y)<=(bot.koordsb.y+bot.r)) )
        {
            BulletTimer->stop();
            BotTimer->stop();
            BulletBotTimer->stop();
            BBulletTimer->stop();

            QMessageBox::information(this, "YOU WIN!", "YOU WIN");
            exit(0);
        }
        if ((tank.bullet[i].coords.x > tank.field.x2)||(tank.bullet[i].coords.y > tank.field.y2)||(tank.bullet[i].coords.x<tank.field.x1)||(tank.bullet[i].coords.y<tank.field.y1))
        {
            tank.bullet.erase(&tank.bullet[i]);
            break;
        }
        repaint();
    }
}

void MainWindow::driveBotOnTimeout()
{
     proverkaFieldBot();
        bot.alpha=rand()%5;
        //=0 на месте
        //=1 вправо
        //=2 вверх
        //=3 влево
        //=4 вниз
        //проверка чтобы бот не ушел за границы полян
        if (bot.koordsb.x-bot.r-bot.speedb<tank.field.x1)
        {
            bot.koordsb.x+=bot.speedb;
        }
        if (bot.koordsb.y-bot.r-bot.speedb<tank.field.y1)
        {
            bot.koordsb.y+=bot.speedb;
        }
        if (bot.koordsb.x+bot.r+bot.speedb>tank.field.x2)
        {
            bot.koordsb.x-=bot.speedb;
        }
        if (bot.koordsb.y+bot.r+bot.speedb>tank.field.y2)
        {
            bot.koordsb.y-=bot.speedb;
        }

        if (bot.alpha==0)
        {
             bot.koordsb.x=bot.koordsb.x;
             bot.koordsb.y=bot.koordsb.y;
             repaint();

        }
        if (bot.alpha==1)
        {
            bot.koordsb.x=bot.koordsb.x+bot.speedb;
            bot.koordsb.y=bot.koordsb.y;
            bot.vecb.x=2;
            bot.vecb.y=0;
            repaint();
        }
        if (bot.alpha==2)
        {
            bot.koordsb.x=bot.koordsb.x;
            bot.koordsb.y=bot.koordsb.y-bot.speedb;
            bot.vecb.x=0;
            bot.vecb.y=-2;
            repaint();
        }
        if (bot.alpha==3)
        {
            bot.koordsb.x=bot.koordsb.x-bot.speedb;
            bot.koordsb.y=bot.koordsb.y;
            bot.vecb.x=-2;
            bot.vecb.y=0;
            repaint();
        }
        if (bot.alpha==4)
        {
            bot.koordsb.x=bot.koordsb.x;
            bot.koordsb.y=bot.koordsb.y+bot.speedb;
            bot.vecb.x=0;
            bot.vecb.y=2;
            repaint();
        }
}
void MainWindow::hitBulletBotOnTimeout()
{
       Bullet bb;
       bb.coords.x = bot.koordsb.x;
       bb.coords.y = bot.koordsb.y;

       bb.alpha.x = bot.vecb.x;
       bb.alpha.y = bot.vecb.y;

       bot.bbullet.push_back(bb);
}
void MainWindow::moveBotBulletOnTimeout()
{
       for (int j=0; j<bot.bbullet.size(); j++)
       {
           bot.bbullet[j].coords.x = bot.bbullet[j].coords.x + bot.bbullet[j].alpha.x * bot.bbullet[j].speed;
           bot.bbullet[j].coords.y = bot.bbullet[j].coords.y + bot.bbullet[j].alpha.y * bot.bbullet[j].speed;

           if ((bot.bbullet[j].coords.x > tank.field.x2)||(bot.bbullet[j].coords.y > tank.field.y2)||(bot.bbullet[j].coords.x<tank.field.x1)||(bot.bbullet[j].coords.y<tank.field.y1))
           {
               bot.bbullet.erase(&bot.bbullet[j]);
               break;
           }
           repaint();
           //убийство игрока
           if ( ((bot.bbullet[j].coords.x+bot.bbullet[j].l * bot.bbullet[j].alpha.x)>=(tank.koords.x-tank.r)) &&((bot.bbullet[j].coords.x+bot.bbullet[j].l * bot.bbullet[j].alpha.x)<=(tank.koords.x+tank.r)) &&
                ((bot.bbullet[j].coords.y+bot.bbullet[j].l * bot.bbullet[j].alpha.y)>=(tank.koords.y-tank.r)) &&((bot.bbullet[j].coords.y+bot.bbullet[j].l * bot.bbullet[j].alpha.y)<=(tank.koords.y+tank.r)) )
           {
               repaint();
               BulletTimer->stop();
               BotTimer->stop();
               BulletBotTimer->stop();
               BBulletTimer->stop();
               QMessageBox::information(this, "YOU LOSE!", "YOU LOSE");
               exit(0);

           }

       }
}

bool MainWindow::proverkaFieldIgrok()
{
    if ((tank.koords.y-tank.r<tank.field.y1)||(tank.koords.y+tank.r>tank.field.y2)||
        (tank.koords.x-tank.r<tank.field.x1)||(tank.koords.x+tank.r>tank.field.x2))
        {
            QMessageBox::information(this, "Nevernie koordinati Igroka!", "Nevernie koordinati Igroka!");
            exit(0);
            return false;
        }

    else
        return true;
}

bool MainWindow::proverkaFieldBot()
{
    if ((bot.koordsb.x-bot.r<tank.field.x1)||(bot.koordsb.y-bot.r<tank.field.y1)||
        (bot.koordsb.x+bot.r>tank.field.x2)||(bot.koordsb.y+bot.r>tank.field.y2))
        {
            QMessageBox::information(this, "Nevernie koordinati Bota!", "Nevernie koordinati Bota!");
            exit(0);
            return false;
        }
    else
        return true;
}

void MainWindow::drawIgrok(QPainter &painter)
{
    painter.setBrush(Qt::blue);
    painter.setPen(Qt::blue);
    painter.drawEllipse(QRect(tank.koords.x-tank.r,tank.koords.y-tank.r,2*tank.r,2*tank.r));
    painter.setPen(Qt::white);
    painter.drawEllipse(QRect(tank.koords.x+tank.vec.x-5,tank.koords.y+tank.vec.y-5,10,10));//башня
}

void MainWindow::drawBot(QPainter &painter)
{
    painter.setBrush(Qt::red);
    painter.setPen(Qt::red);
    painter.drawEllipse(QRect(bot.koordsb.x-bot.r,bot.koordsb.y-bot.r,2*bot.r,2*bot.r));
    painter.setPen(Qt::white);
    painter.drawEllipse(QRect(bot.koordsb.x+bot.vecb.x-5,bot.koordsb.y+bot.vecb.y-5,10,10));
}


