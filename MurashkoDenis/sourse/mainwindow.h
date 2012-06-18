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
   void proverkaDeath();//�������� ��������
   bool proverkaFieldIgrok();//�������� ������ ���� ��� ������
   bool proverkaFieldBot();//�������� ������ ���� ��� ����
   void drawIgrok(QPainter &painter);//��������� �����-������
   void drawBot(QPainter &painter);//��������� ����
public slots:
   void moveBulletOnTimeout();//�������� ����
   void driveBotOnTimeout();//�������� ����
   void hitBulletBotOnTimeout();//������ ���� ����
   void moveBotBulletOnTimeout();//�������� ���� ����

private:
    Ui::MainWindow *ui;
    void keyPressEvent(QKeyEvent * ev);
    QPainter painter;
    Igrok tank;
    Bot bot;
    Test test;
    //������ ���
    QTimer* BulletTimer; //�������� ���� ������
    QTimer* BotTimer;//�������� ����
    QTimer* BulletBotTimer;//������ ���� � ����
    QTimer* BBulletTimer;//�������� ���� � ����
};

#endif // MAINWINDOW_H
