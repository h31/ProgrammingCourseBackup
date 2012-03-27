#pragma once
#include "figure.h"

#ifndef _elephant_h_
#define _elephant_h_

class Elephant: virtual public Figure
{
public:
	Elephant(int xCoordinate, int yCoordinate, bool whiteFigure);
	virtual bool canFigureTurn(int xCoordinate,int yCoordinate, Figure **figure);
};

#endif