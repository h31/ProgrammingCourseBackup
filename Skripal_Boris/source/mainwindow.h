#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>

#include<player.h>

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
    
private:
    Ui::MainWindow *ui;
    QPainter qp;
     QImage desk;
     Player game;
};

#endif // MAINWINDOW_H
