#pragma once

#ifndef _pawn_h_
#define _pawn_h_

#include "figure.h"
#include "desk.h"

class Pawn: virtual public Figure
{
public:
	Pawn(const int xCoordinate,const  int yCoordinate,const  bool whiteFigure);
	virtual bool canFigureTurn(const int xCoordinate,const int yCoordinate,const  Desk &desk);
};

#endif