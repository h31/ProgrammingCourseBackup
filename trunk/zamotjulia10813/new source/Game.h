#ifndef _Game_h_
#define _Game_h_
#include "Scenario.h"

class Game { //������ ��� ����������, ��� ���������-���.
public:
    Game ();
    ~Game();
    void Upd ();
    int Time; //��� �����
    int Cycle; //��� ������
    Scenario1 *Sc1;
};

#endif
