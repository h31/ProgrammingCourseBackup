#ifndef _Fruct_h_
#define _Fruct_h_

#include <iostream>
#include <stdlib.h>
using namespace std;

const int Grtime=20;

enum FructTipe { App=0, Grr=1 };

class Fruct { //��������� �����, ���������� ������� �����
public:
    int x, y;
    Fruct (int X, int Y);
    virtual int enumfunc ( )=0;
};

class Apple: public Fruct { //����������� �����
public:
    Apple (int X, int Y);
    int enumfunc ();
};

class Grusha: public Fruct { //����������� �����
public:
    int time;
    Grusha (int t, int X, int Y);
    int enumfunc ( );
};

#endif
