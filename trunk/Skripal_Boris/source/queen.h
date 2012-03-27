#pragma once
#include "figure.h"

#ifndef _queen_h_
#define _queen_h_

class Queen: virtual public Figure
{
public:
	Queen(int xCoordinate, int yCoordinate, bool whiteFigure);
	virtual bool canFigureTurn(int xCoordinate,int yCoordinate, Figure **figure);
};

#endif