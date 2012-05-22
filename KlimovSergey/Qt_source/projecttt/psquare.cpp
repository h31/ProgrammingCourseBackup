#include "psquare.h"

PSquare::PSquare()
{
}

PSquare::~PSquare()
{
}

void PSquare::draw(Square& sq,QPainter& painter)
{
    if(sq.getStat() == 1)
    {
        painter.setBrush(Qt::black);
        painter.drawRoundedRect(sq.s.x,sq.s.y+21,sqSize-1,sqSize-1,5,5);
    }
    else if(sq.getStat()==2)
    {
        painter.fillRect(sq.s.x,sq.s.y+21,sqSize,sqSize,Qt::white);
    }
    else if(sq.getStat()==0)
    {
        painter.setBrush(Qt::black);
        painter.drawEllipse(sq.s.x+7,sq.s.y+21+(sqSize+1)/3,sqSize/4,sqSize/4);
    }
}
