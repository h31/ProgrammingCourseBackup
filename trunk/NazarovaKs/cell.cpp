#include "field.h"
#include <iostream>

using namespace std;

Cell::Cell() {}

Cell::Cell(int px, int py)
{
	cx=--px;
	cy=--py;
}

Cell::~Cell() {}
