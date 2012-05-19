#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QPainter>
#include <QTimer>
#include "tanki.h"
#include "puli.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
   // void paint();
   void paintEvent(QPaintEvent *event);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void keyPressEvent(QKeyEvent * ev);
    //void moveBulletOnTimeout(BulletCoordinates &coords, int speed);
    QPainter painter;
    Tank tank;
    QTimer* bulletTimer;

};

#endif // MAINWINDOW_H
