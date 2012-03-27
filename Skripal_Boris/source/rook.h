#pragma once
#include "figure.h"

#ifndef _rook_h_
#define _rook_h_

class Rook: virtual public Figure
{
public:
	Rook(int xCoordinate, int yCoordinate, bool whiteFigure);
	virtual bool canFigureTurn(int xCoordinate,int yCoordinate, Figure **figure);
};

#endif 