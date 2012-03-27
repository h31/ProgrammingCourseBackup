#pragma once
#include "figure.h"

#ifndef _king_h_
#define _king_h_

class King: virtual public Figure
{
public:
	King(int xCoordinate, int yCoordinate, bool whiteFigure);
	virtual bool canFigureTurn(int xCoordinate,int yCoordinate, Figure **figure);
};

#endif