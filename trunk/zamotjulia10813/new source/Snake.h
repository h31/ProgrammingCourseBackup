#ifndef _Snake_h_
#define _Snake_h_

#include "Snakelem.h"

enum Zmlist { Snakehead=2, Snaketail=3 };

class Zmeika { //������� �� ������ � ������
public:
    Zmeika(int X, int Y, int Napx, int Napy);
    Zmeika();
    int Headx, Heady;
    int napx, napy;
    int dlintail;
    //���� �� ������
    bool Alive;
    ZmElement* Tail;
    int enumHead ();
    int enumTail ();
    //bool RotateUp();
    //bool RotateDown();
    //bool RotateLeft();
    //bool RotateRight();
    //bool Move();
    };

#endif
