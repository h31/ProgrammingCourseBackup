#ifndef _Field_h_
#define _Field_h_

#include <iostream>
#include <stdlib.h>
using namespace std;

#include "Fructs.h"
#include "Snake.h"

class Pole {
public:
    int** p;
    int w,h;
public:
    Pole (int W, int H, Fructs* Fruits, Zmeika*Zmeia);
    Pole ();
    void init (Fructs* Fruits, Zmeika*Zmeia);
    void show ();
    bool createPole ();
    char intToChar (int Code);
};

#endif
