#pragma once
#ifndef _knight_h_
#define _knight_h_

#include "figure.h"
#include "desk.h"

class Knight: virtual public Figure
{
public:
	Knight(const int xCoordinate,const  int yCoordinate,const  bool whiteFigure);
	virtual bool canFigureTurn(const int xCoordinate,const int yCoordinate,const  Desk &desk);
};

#endif