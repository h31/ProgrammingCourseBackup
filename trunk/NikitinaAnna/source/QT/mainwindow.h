#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>

#include "field.h"
#include "player.h"
#include "shashki.h"
#include "game.h"

struct Coordinate
{
   int x,y,Px,Py;
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    //QTimer* timer;
    
public:
    explicit MainWindow(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
    ~MainWindow();
signals:
   void wrongMove();
protected:
   void mousePressEvent(QMouseEvent *event);      
private slots:
   //void onTimeout();
   void on_pushButton_clicked();
   void on_pushButton_2_clicked();
   void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
   void printResult();
   void turnIsFalse();
   void falseTurns();
   void wrong();
   void strangeStroke();
   void empty2();

private:
    Ui::MainWindow *ui;
    QPainter qpaint;
    QImage playingBoard;
    QImage paint;
    QPixmap shashka;
    QImage turnPicture;
    Field *field;  Game *game;
    Checker checker; King king;Player player;
    bool isFirstClick;
    bool isReadCoordinateEnd;
    Coordinate readCord;
    void leftButtonPressEvent(QMouseEvent * event);
    int sizeBoard;int number;
    int plateX;int plateY;
    int denom;int sum;
    int testVar;int var;int next;
    //bool time;
    bool isWhiteTurnTwo;
};

#endif // MAINWINDOW_H
