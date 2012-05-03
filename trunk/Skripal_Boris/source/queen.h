#pragma once

#ifndef _queen_h_
#define _queen_h_

#include "figure.h"
#include "desk.h"

class Queen: virtual public Figure
{
    Q_OBJECT
public:
	Queen(const int xCoordinate,const  int yCoordinate,const  bool whiteFigure);
	virtual bool canFigureTurn(const int xCoordinate,const int yCoordinate,const  Desk &desk);
    virtual void printFigure(QPainter &painter);
};

#endif
