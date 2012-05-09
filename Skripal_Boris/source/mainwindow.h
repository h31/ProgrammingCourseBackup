#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>

#include "player.h"
#include "test.h"

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
   void on_actionTests_activated();

private:
    Ui::MainWindow *ui;
     QPainter qp;
     QImage desk;
     Player *game;
     Test *test;

     QImage turnPicture;
     QPoint leftUp;

     bool isFirstClick;
     bool isReadCoordinateEnd;

     Coordinate readCord;

      void leftButtonPressEvent(QMouseEvent * event);
};

#endif // MAINWINDOW_H
