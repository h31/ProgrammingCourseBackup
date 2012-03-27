#pragma once
#include "figure.h"

#ifndef _horse_h_
#define _horse_h_

class Horse: virtual public Figure
{
public:
	Horse(int xCoordinate, int yCoordinate, bool whiteFigure);
	virtual bool canFigureTurn(int xCoordinate,int yCoordinate, Figure **figure);
};

#endif