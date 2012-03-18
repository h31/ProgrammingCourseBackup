#ifndef _Field_h_
#define _Field_h_

#include "Fruct.h"
#include "Snake.h"

#include <iostream>
#include <stdlib.h>
using namespace std;

class Pole {
public:
	int** p;
	int w,h;
public:
	Pole (int W, int H);
	void showpole (Fructs* Fruits, Zmeika*Zmeia);
};

#endif