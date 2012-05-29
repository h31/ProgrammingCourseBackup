#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Timer = new QTimer;//для движения пули
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent* ev)
{
    //танк
    if ((tank.koords.x-tank.r-tank.speed<tank.field.x1)||(tank.koords.y-tank.r-tank.speed<tank.field.y1)||
            (tank.koords.x+tank.r+tank.speed>tank.field.x2)||(tank.koords.y+tank.r+tank.speed>tank.field.y2))
    {

    }
    if (ev->key() == Qt::Key_W)
    {

        tank.koords.y=tank.koords.y-tank.speed;
        tank.vec.x=0;
        tank.vec.y=-2;
        repaint();
    }
    if (ev->key() == Qt::Key_S)
    {
        tank.koords.y=tank.koords.y+tank.speed;
        tank.vec.x=0;
        tank.vec.y=2;
        repaint();
    }
    if (ev->key() == Qt::Key_A)
    {
        tank.koords.x=tank.koords.x-tank.speed;
        tank.vec.x=-2;
        tank.vec.y=0;
        repaint();
    }
    if (ev->key() == Qt::Key_D)
    {
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


        tank.bullet.push_back(b);
       // qDebug() << "Bullet created: " << b.speed << " " << endl;
    }
    //бот
    connect(Timer, SIGNAL(timeout()), SLOT(moveBulletOnTimeout()));
    connect(Timer, SIGNAL(timeout()), SLOT(driveBotOnTimeout()));
    Timer->start(1000);
   // bulletTimer->start(1000);

}
void MainWindow::paintEvent(QPaintEvent *event) //как передать сюда аргументы(координаты)
{
    QPainter painter;
    painter.begin(this);
    painter.setBrush(QBrush(Qt::black));//закрашивание прямоугольником
    painter.drawRect(tank.field.x1,tank.field.y1,tank.field.x2,tank.field.y2);

    tank.draw(painter);
    bot.draw(painter);
    for (int i=0;i<tank.bullet.size();i++)
    {
        //qDebug() << tank.bullet[i].coords.x << tank.bullet[i].coords.y << endl;
        tank.bullet[i].drawp(painter);
    }
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
        //=0 на месте
        //=1 вправо
        //=2 вверх
        //=3 влево
        //=4 вниз
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
