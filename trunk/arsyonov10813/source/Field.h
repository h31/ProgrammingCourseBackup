#ifndef FIELD_H
#define FIELD_H

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

//GameField* field;

//extern QString str1;
//extern QString str2;

//extern TurnText* tu;

class MyLine : public QGraphicsLineItem
{

public:
 MyLine(int x1, int x2, int x3, int x4);
 bool isChecked;
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


class GameField
{
public:

  //  QPen PenBlack;

    QPen PenGray;
    QGraphicsScene* GameScene;
    std::vector<std::vector<MyLine*> > VerticalLine;
    std::vector<std::vector<MyLine*> > HorizontalLine;
    QGraphicsTextItem* finished;
    std::vector<std::vector<MyText*> > CellText;
   // MyText* CellText[10][10];
    GameField();
    ~GameField();
    void InitializationField();
    int CheckField();
    int FieldCounting();

    void ShowField();
protected:
    void keyPressEvent(QKeyEvent *event);
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
