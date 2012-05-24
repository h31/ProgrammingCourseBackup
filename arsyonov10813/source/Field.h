#ifndef FIELD_H
#define FIELD_H

#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QApplication>
#include <QHBoxLayout>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QHBoxLayout>
#include <QGraphicsView>
#include <QTime>
//#include "mainwindow.h"
#include <phonon/AudioOutput>
#include <phonon/MediaObject>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <Game.h>
#include <vector>
static int razdvatri;
//GameField* field;

//extern QString str1;
//extern QString str2;

//extern TurnText* tu;

class MyLine : public QObject, public QGraphicsLineItem
{
  Q_OBJECT
public:
 MyLine(int x1, int x2, int x3, int x4);
 bool isChecked;
signals:
   void mySignal();


// int ocherednost;

protected:
 void mousePressEvent(QGraphicsSceneMouseEvent* event);

};

class MyText : public QGraphicsTextItem
{

public:
 MyText(const QString q);
protected:
 void mousePressEvent(QGraphicsSceneMouseEvent* event);
 void mouseDoubleClickEvent( QGraphicsSceneMouseEvent * event );
};
/*
class WinText : public QObject, public QGraphicsTextItem
{
    Q_OBJECT
public:
 WinText(const QString q);
signals:
   void winSignal();

protected:
 void mousePressEvent(QGraphicsSceneMouseEvent* event);

};

*/



class GameFieldA : public QObject
{
    Q_OBJECT

public:

  //  QPen PenBlack;

    QPen PenGray;
    QGraphicsScene* GameScene;
    std::vector<std::vector<MyLine*> > VerticalLine;
    std::vector<std::vector<MyLine*> > HorizontalLine;
    QGraphicsTextItem* finished;
    TurnText *tu;
    QGraphicsTextItem* hello;
    std::vector<std::vector<MyText*> > CellText;
   // MyText* CellText[10][10];
    GameFieldA(int height, int width, QString str1, QString str2);
    QString string1;
    QString string2;
    int h;
    int w;

    ~GameFieldA();
    void InitializationField();
    int CheckField();
    int FieldCounting();

    void ShowField();
protected:
    void keyPressEvent(QKeyEvent *event);
public slots:
   void mySlot()
   {
      if(tu->toPlainText() == string1)
      {
       delete tu;
       tu=new TurnText(string2);
       tu->setPos(420, 120);
       tu->setDefaultTextColor(Qt::blue);
       GameScene->addItem(tu);
       }
       else
      {
        delete tu;
        tu=new TurnText(string1);
        tu->setPos(420, 120);
        tu->setDefaultTextColor(Qt::red);
        GameScene->addItem(tu);

       qDebug()<<"Text";
      }
   }
/*
   void winSlot()
   {
       delete finished;
       finished = new WinText(string2);
       finished->setPos(420, 120);
       finished->setDefaultTextColor(Qt::red);
       GameScene->addItem(finished);
   }
   */
};


class GameFieldQ : public GameFieldA
{
 //   Q_OBJECT
public:

  //  QPen PenBlack;

    GameFieldQ(int height, int width, QString str1, QString str2) : GameFieldA(height, width, str1, str2)
    {
        PenGray.setColor(Qt::gray);
        PenGray.setWidth(5);
        if(height >= width)
        {
            h = height;
            w = height;
        }
        else
        {
            h = width;
            w = width;
        }
        string1 = str1;
        string2 = str2;


    }

  //  int a;
 //   ~GameFieldQ();
//public slots:
 //  void mySlot()
 //  {
 //      if(tu->toPlainText() == string1)
   //        tu=new TurnText(string2);
   //    else
   //        tu=new TurnText(string1);
 //  }
};


//extern GameField* field;


#endif // FIELD_H


/*
MainPlot=new QGraphicsScene(centralWidget());
MainPlot->setSceneRect(0,0,500,500);

QPen _Pen;
_Pen.setColor(Qt::red);
_Pen.setWidth(3);

QGraphicsLineItem* _Line=new QGraphicsLineItem(100,100,450,300);
_Line->setPen(_Pen);
_Line->setVisible(true);
_Line->setFlags(QGraphicsLineItem::ItemIsSelectable | QGraphicsLineItem::ItemIsMovable);
MainPlot->addItem(_Line);

ui.view->setScene(MainPlot);
  */
