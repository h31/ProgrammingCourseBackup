#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QTime>
#include <iostream>

#include "player.h"
#include "test.h"
#include "optiondialog.h"

struct Coordinate
{
   int startX,startY,finishX,finishY;
};

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

//   void checkShah();
protected:
   void mousePressEvent(QMouseEvent *event);
private slots:
   void on_actionNewGame_activated();
   void on_actionPlayerWins_activated();
   void shahIsTrue();
   void turnIsFalse();
   void testIsTrue();
   void testIsFalse();
   void printMat();
   void appendTurn();
   void onTimerIsEnd();
   void checkTimeOut();
   void blinkTimeOut();
   void chachgeSetting();
   void on_actionTests_activated();

   void on_actionEnd_activated();

   void on_actionSave_activated();

   void on_actionLoad_activated();

   void on_actionOptions_activated();

private:
    Ui::MainWindow *ui;
     QPainter qp;
     QImage desk;
     Player *game;
     Test *test;
     Figure *blinkFigure;

     QImage turnPicture;
     QPoint leftUp;

     bool isFirstClick;
     bool isReadCoordinateEnd;

     Coordinate readCord;
     QTime *timeWhite;
     QTime *timeBlack;
     QTimer *timer;
     QTimer *blinkTimer;
     int hours,minutes,seconds,blink;

      void leftButtonPressEvent(QMouseEvent * event);

};

#endif // MAINWINDOW_H
