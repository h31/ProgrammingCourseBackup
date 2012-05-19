#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tanki.h"
#include "puli.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tank.koords.x=100;
    tank.koords.y=100;
    tank.speed=20;
    tank.bullet.speed=20;
    tank.vec.x=0;
    tank.vec.y=0;
    tank.r=20;

    // TODO: Исправить

    tank.bullet.coords.x = tank.koords.x;
    tank.bullet.coords.y = tank.koords.y;

    //tank.bullet.alpha.x = tank.vec.x;
    //tank.bullet.alpha.x = tank.vec.x;

    /*QTimer *timer = new QTimer(this);
     connect(timer, SIGNAL(timeout()), this, SLOT(update()));
     timer->start(1000);*/
     bulletTimer = new QTimer;//для движения пули
     connect(bulletTimer, SIGNAL(timeout()), &tank.bullet, SLOT(moveBulletOnTimeout()));//надо сделать наследником Q_OBJECT
     bulletTimer->start(1000);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent* ev)
{
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
    if (ev->key() == Qt::Key_Space)//надо передать vect для направления пули
    {
        //???????  надо угол стобы был const
        //надо вызывать функцию moveBulletOnTimeout() через 1 с

        tank.bullet.alpha.x = tank.vec.x;
        tank.bullet.alpha.y = tank.vec.y;
        tank.bullet.moveBulletOnTimeout();
        //tank.bullet+=40;
        repaint();
    }
}
void MainWindow::paintEvent(QPaintEvent *event)//как передать сюда аргументы(координаты)
{
    QPainter painter;
    painter.begin(this);
    painter.setBrush(QBrush(Qt::black));//закрашивание прямоугольником
    painter.drawRect(0,0,1500,1000);

    tank.draw(painter);
    tank.bullet.draw(painter);

    painter.end();
}

/*void MainWindow::moveBulletOnTimeout(BulletCoordinates &coords,int speed)
{
    coords.x = coords.x + speed;
    coords.y = coords.y + speed;
}*/
