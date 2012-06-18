#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QPainter>
#include <QTimer>
#include <conio.h>
#include "tanki.h"
#include "puli.h"
#include "bot.h"
#include "test.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

   void paintEvent(QPaintEvent *event);
    ~MainWindow();
   void proverkaDeath();//проверка убийства
   bool proverkaFieldIgrok();//проверка границ поля для игрока
   bool proverkaFieldBot();//проверка границ поля для бота
   void drawIgrok(QPainter &painter);//рисование танка-игрока
   void drawBot(QPainter &painter);//рисование бота
public slots:
   void moveBulletOnTimeout();//движение пули
   void driveBotOnTimeout();//движение бота
   void hitBulletBotOnTimeout();//выпуск пули бота
   void moveBotBulletOnTimeout();//движение пули бота

private:
    Ui::MainWindow *ui;
    void keyPressEvent(QKeyEvent * ev);
    QPainter painter;
    Igrok tank;
    Bot bot;
    Test test;
    //таймер для
    QTimer* BulletTimer; //движения пули игрока
    QTimer* BotTimer;//движения бота
    QTimer* BulletBotTimer;//выпуск пуль у бота
    QTimer* BBulletTimer;//движение пуль у бота
};

#endif // MAINWINDOW_H
