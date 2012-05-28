#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "field.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    bool firstClick;
    int startX, startY, finishX, finishY;

    virtual void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);    
    void leftButtonPressEvent(QMouseEvent* event);
    void outLoss();

private slots:
    void on_actionNew_game_activated();
    void on_pushButton_clicked();
    void on_actionExit_activated();

    void on_verticalScrollBar_sliderPressed();

private:
    Ui::MainWindow *ui;
    Field f;
};

#endif // MAINWINDOW_H
