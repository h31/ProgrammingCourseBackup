#ifndef _Fruct_h_
#define _Fruct_h_

#include <iostream>
#include <stdlib.h>
using namespace std;

const int Grtime=20;

enum FructTipe { App=0, Grr=1 };

class Fruct { //единичный фрукт, абстрактый базовый класс
public:
    int x, y;
    Fruct (int X, int Y);
    virtual int enumfunc ( )=0;
};

class Apple: public Fruct { //производный класс
public:
    Apple (int X, int Y);
    int enumfunc ();
};

class Grusha: public Fruct { //производный класс
public:
    int time;
    Grusha (int t, int X, int Y);
    int enumfunc ( );
};

#endif
