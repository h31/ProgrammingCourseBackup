#ifndef _game_h_
#define _game_h_


#include <QtGui>
#include"player.h"
#include"field.h"
#include"shashki.h"

enum View
{
    black,//�����, �������� �������
    white,//�����, �������� ������
    blank//�����
};

class Game:public QObject
{
   Q_OBJECT
public:
    Game();
    ~ Game();
    void findWinner(Field& field);//�������� ���������� ���� � ����������� ����������
    View winner;//��� �������
    bool isWhiteTurn;//��� �� ������ ������ �����
   bool result(int Px,int  Py,int  x, int y,int variable,Field& field,Checker& checker, King &king,Player &player);
signals:
   void end();
   void printFalseTurn();
};

#endif
