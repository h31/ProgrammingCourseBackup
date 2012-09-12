#ifndef _Fruct_h_
#define _Fruct_h_
#include <iostream>
#include <stdlib.h>
using namespace std;

const int peartime=20;

enum fructType { app=98, pear=99 };

class Fruct {
private:
    int x, y;
	int type;
public:
    Fruct (int X, int Y);
	Fruct ();
    ~Fruct();
    int getx();
    int gety();
    bool setx (int new_x);
    bool sety (int new_y);
    int gettype ( );
	bool settype(int newtype);
};

class Apple: public Fruct {
public:
    Apple (int X, int Y);
    ~Apple();
};

class Pear: public Fruct {

private:
	int time;
public:

    Pear (int t, int X, int Y);
    ~Pear();
	int gettime();
	bool settime(int newtime);
};

#endif
