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
    
public:
    explicit MainWindow(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
    ~MainWindow();
protected:
   void mousePressEvent(QMouseEvent *event);      
private slots:
   void on_pushButton_clicked();
   //void printResult();
   //void turnIsFalse();

private:
    Ui::MainWindow *ui;
    QPainter qpaint;
    QImage playingBoard;
    QPixmap shashka;
    QImage turnPicture;
    Field *field; Player player; Game *game;
    Checker checker; King king;

    bool isFirstClick;
    bool isReadCoordinateEnd;
    Coordinate readCord;
    void leftButtonPressEvent(QMouseEvent * event);
    int sizeBoard;int number;
    int plateX;int plateY;
    int denom;int sum;
};

#endif // MAINWINDOW_H
