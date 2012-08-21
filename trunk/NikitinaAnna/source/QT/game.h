#ifndef _game_h_
#define _game_h_


#include <QtGui>
#include"player.h"
#include"field.h"
#include"shashki.h"

enum View
{
    black,//Игрок, играющий черными
    white,//Игрок, играющий белыми
    blank//Ничья
};

class Game:public QObject
{
   Q_OBJECT
     int pox;int poy;
public:
     int getpox();
     int getpoy();
     void setpox(int x);
    void setpoy(int y);
    Game();
    ~ Game();
    bool test(int  x, int y,Field& field);
    void findWinner(Field& field);//проверка завершения игры и определение победителя
    View winner;//Кто выиграл
    bool isWhiteTurn;//Кто на данный момент ходит
   bool result(int Px,int  Py,int  x, int y,Field& field,Checker& checker, King &king,Player &player);
signals:
  void end();
  void printFalseTurn();
  void falseTurn();
  void empty1();
  void strangeStroke1();
};

#endif
