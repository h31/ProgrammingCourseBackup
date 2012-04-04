#pragma once

#ifndef _rook_h_
#define _rook_h_

#include "figure.h"
#include "desk.h"

class Rook: virtual public Figure
{
public:
	Rook(const int xCoordinate,const  int yCoordinate,const  bool whiteFigure);
	virtual bool canFigureTurn(const int xCoordinate,const int yCoordinate,const Desk & desk);
};

#endif 