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
    void drawIgrok(QPainter &painter);//рисование танка-игрока
    void drawBot(QPainter &painter);//рисование бота
    void drawFencing(QPainter &painter);//рисование ограды
    void workFencing(QPainter &painter);//преграждение пуль и для танков
public slots:
    void moveBulletOnTimeout();//движение пули
    void driveBotOnTimeout();//движение бота
    void hitBulletBotOnTimeout();//выпуск пули бота
    void moveBotBulletOnTimeout();//движение пули бота
    void paintTimer();
private:
    Ui::MainWindow *ui;
    void keyPressEvent(QKeyEvent * ev);
    QPainter painter;
    Igrok tank;
    Bot bot;
    Field field;
    Test test;
    //таймер для
    QTimer* BulletTimer; //движения пули игрока
    QTimer* BotTimer;//движения бота
    QTimer* BulletBotTimer;//выпуск пуль у бота
    QTimer* BBulletTimer;//движение пуль у бота
    QTimer* RepaintTimer;
};

#endif // MAINWINDOW_H
