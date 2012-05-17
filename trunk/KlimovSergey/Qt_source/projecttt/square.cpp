#include "square.h"

Square::Square()
{
}

Square::~Square()
{}


int Square::getStat()
{
    return status;
}

void Square::setStat(int st)
{
    status = st;
}

/*istream& operator >>(istream& in, Square& sq)
{
    in >> sq.status;
    return in;
}

ostream& operator <<(ostream& out, const Square& sq)
{
    out << sq.status;
    return out;
}*/

void Square::fill(QPainter& painter)
{
    painter.setBrush(Qt::black);
    //painter.fillRect(s.x,s.y+21,20,20,Qt::black);
    painter.drawRoundedRect(s.x,s.y+21,sqSize-1,sqSize-1,5,5);
}

void Square::clear(QPainter& painter)
{
    painter.fillRect(s.x,s.y+21,sqSize,sqSize,Qt::white);

}

void Square::mark(QPainter& painter)
{
    painter.setBrush(Qt::black);
    painter.drawEllipse(s.x+7,s.y+21+(sqSize+1)/3,sqSize/4,sqSize/4);
}
