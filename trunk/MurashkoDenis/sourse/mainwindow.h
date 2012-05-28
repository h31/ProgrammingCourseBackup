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

public slots:
   void moveBulletOnTimeout();//движение пули
   void driveBotOnTimeout();//движение бота


private:
    Ui::MainWindow *ui;
    void keyPressEvent(QKeyEvent * ev);
    QPainter painter;
    Igrok tank;
    Bot bot;
    QTimer* Timer;//таймер


};

#endif // MAINWINDOW_H
