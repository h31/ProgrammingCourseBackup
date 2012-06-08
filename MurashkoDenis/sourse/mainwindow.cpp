#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    BulletTimer = new QTimer;//��� �������� ���� ������
    BotTimer = new QTimer;//��� �������� ����
    BulletBotTimer = new QTimer;//��� ���������� ���� ����
    BBulletTimer = new QTimer;//��� �������� ���� ����

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent* ev)
{
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
        Bullet b;//��� ���� �������� �������� � ����� �������� � ������
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
void MainWindow::paintEvent(QPaintEvent *event) //��� �������� ���� ���������(����������)
{
    QPainter painter;
    painter.begin(this);
    painter.setBrush(QBrush(Qt::green));//������������ ���������������
    painter.drawRect(tank.field.x1,tank.field.y1,tank.field.x2,tank.field.y2);
    bot.draw(painter);
    tank.draw(painter);

    for (int i=0;i<tank.bullet.size();i++)
    {
        tank.bullet[i].drawp(painter);
    }

    for (int j=0;j<bot.bbullet.size();j++)
    {
        bot.bbullet[j].drawp(painter);
    }
    proverkaDeath();
    painter.end();
}

void MainWindow::moveBulletOnTimeout()
{

    for (int i=0; i<tank.bullet.size(); i++)
    {
        tank.bullet[i].coords.x = tank.bullet[i].coords.x + tank.bullet[i].alpha.x * tank.bullet[i].speed;
        tank.bullet[i].coords.y = tank.bullet[i].coords.y + tank.bullet[i].alpha.y * tank.bullet[i].speed;

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

        bot.alpha=rand()%5;
        //=0 �� �����
        //=1 ������
        //=2 �����
        //=3 �����
        //=4 ����
        //�������� ����� ��� �� ���� �� ������� �����
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
           //�������� ������
           if ( ((bot.bbullet[j].coords.x+bot.bbullet[j].l * bot.bbullet[j].alpha.x)>=(tank.koords.x-tank.r)) &&((bot.bbullet[j].coords.x+bot.bbullet[j].l * bot.bbullet[j].alpha.x)<=(tank.koords.x+tank.r)) &&
                ((bot.bbullet[j].coords.y+bot.bbullet[j].l * bot.bbullet[j].alpha.y)>=(tank.koords.y-tank.r)) &&((bot.bbullet[j].coords.y+bot.bbullet[j].l * bot.bbullet[j].alpha.y)<=(tank.koords.y+tank.r)) )
           {
               QMessageBox::information(this, "YOU LOSE!", "YOU LOSE");
               exit(0);

           }
       }
}
void MainWindow::proverkaDeath()
{
    //�������� ����
    for (int i=0;i<tank.bullet.size();i++)
    {
        if ( (tank.bullet[i].coords.x+tank.bullet[i].l * tank.bullet[i].alpha.x)>=(bot.koordsb.x-bot.r) && ((tank.bullet[i].coords.x+tank.bullet[i].l * tank.bullet[i].alpha.x)<=(bot.koordsb.x+bot.r)) &&
            ((tank.bullet[i].coords.y+tank.bullet[i].l * tank.bullet[i].alpha.y)>=(bot.koordsb.y-bot.r)) && ((tank.bullet[i].coords.y+tank.bullet[i].l * tank.bullet[i].alpha.y)<=(bot.koordsb.y+bot.r)) )
        {
            QMessageBox::information(this, "YOU WIN!", "YOU WIN");
            exit(0);
        }
    }
}
