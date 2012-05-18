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
public:
    Game();
    ~ Game();
    void findWinner(Field& field);//проверка завершения игры и определение победителя
    View winner;//Кто выиграл
    bool isWhiteTurn;//Кто на данный момент ходит
   bool result(int Px,int  Py,int  x, int y,int variable,Field& field,Checker& checker, King &king,Player &player);
signals:
   void end();
   void printFalseTurn();
};

#endif
