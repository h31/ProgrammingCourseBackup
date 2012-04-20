#ifndef _Fruct_h_
#define _Fruct_h_

#include <iostream>
#include <stdlib.h>
using namespace std;

const int peartime=20;

enum fructType { app=0, pear=1 };

class Fruct { //��������� �����, ���������� ������� �����
private:
    int x, y;
public:
    Fruct (int X, int Y);
    ~Fruct();
    int getx();
    int gety();
    bool setx (int new_x);
    bool sety (int new_y);
    virtual int fructenumerate ( )=0;
};

class Apple: public Fruct { //����������� �����
public:
    Apple (int X, int Y);
    ~Apple();
    int fructenumerate ();
};

class Pear: public Fruct { //����������� �����
public:
    int time;
    Pear (int t, int X, int Y);
    ~Pear();
    int fructenumerate ();
};

#endif
