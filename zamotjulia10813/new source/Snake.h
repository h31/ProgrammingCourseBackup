#ifndef _Snake_h_
#define _Snake_h_

#include "Snakelem.h"
#include <vector>

enum zmlist { snakehead=2, snaketail=3 };

class Zmeika { //состоит из головы и хвоста
private:
    int headx, heady;
    int napx, napy;
public:
    Zmeika(int X, int Y, int Napx, int Napy);
    Zmeika(int X, int Y, int Napx, int Napy, int LTail);

    int get_headx();
    int get_heady();
    bool set_headx (int new_x);
    bool set_heady (int new_y);
    int get_napx();
    int get_napy();
    bool set_napx (int new_napx);
    bool set_napy (int new_napy);

    std::vector<ZmElement*>Tail2;
    Zmeika();
    ~Zmeika();

    int dlintail;
    //жива ли змейка
    bool Alive;
    ZmElement* tail;
    int enumerateHead ();
    int enumerateTail ();

    bool rotateUp();
    bool rotateDown();
    bool rotateLeft();
    bool rotateRight();
    bool move();

    void shift();
    bool check1();
	bool check2();
	bool check3();

    };
#endif
