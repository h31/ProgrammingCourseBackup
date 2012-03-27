#pragma once
#include "figure.h"

#ifndef _pawn_h_
#define _pawn_h_

class Pawn: virtual public Figure
{
public:
	Pawn(int xCoordinate, int yCoordinate, bool whiteFigure);
	virtual bool canFigureTurn(int xCoordinate,int yCoordinate, Figure **figure);
};

#endif