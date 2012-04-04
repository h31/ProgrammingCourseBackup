#ifndef _Snake_h_
#define _Snake_h_

#include "Snakelem.h"
#include <vector>

enum Zmlist { Snakehead=2, Snaketail=3 };

class Zmeika { //������� �� ������ � ������
public:
    //Game * Game1;
    Zmeika(int X, int Y, int Napx, int Napy);
    Zmeika(int X, int Y, int Napx, int Napy,int LTail);
    std::vector<ZmElement*>Tail2;
    Zmeika();
    ~Zmeika();
    int Headx, Heady;
    int napx, napy;
    int dlintail;
    //���� �� ������
    bool Alive;
    ZmElement* Tail;
    int enumHead ();
    int enumTail ();

    bool RotateUp();
    bool RotateDown();
    bool RotateLeft();
    bool RotateRight();
    bool Move();

    void Shift();
    bool Check();
    };
#endif
