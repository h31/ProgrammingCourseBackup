#pragma once


#ifndef _bishop_h_
#define _bishop_h_

#include "figure.h"
#include "desk.h"

class Bishop: virtual public Figure
{
    Q_OBJECT
public:
	Bishop(const int xCoordinate, const int yCoordinate, const bool whiteFigure);
	virtual bool canFigureTurn(const int xCoordinate,const int yCoordinate,const  Desk &desk);
    virtual void printFigure(QPainter &painter);
};

#endif
