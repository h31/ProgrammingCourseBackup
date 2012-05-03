#pragma once

#ifndef _rook_h_
#define _rook_h_

#include "figure.h"
#include "desk.h"

class Rook: virtual public Figure
{
    Q_OBJECT
public:
	Rook(const int xCoordinate,const  int yCoordinate,const  bool whiteFigure);
	virtual bool canFigureTurn(const int xCoordinate,const int yCoordinate,const Desk & desk);
    virtual void printFigure(QPainter &painter);
};

#endif 
