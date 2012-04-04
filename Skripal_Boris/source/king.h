#pragma once

#ifndef _king_h_
#define _king_h_

#include "figure.h"
#include "desk.h"

class King: virtual public Figure
{
public:
	King(const int xCoordinate,const  int yCoordinate,const  bool whiteFigure);
	virtual bool canFigureTurn(const int xCoordinate,const int yCoordinate,const  Desk &desk);
};

#endif