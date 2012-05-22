#ifndef PSQUARE_H
#define PSQUARE_H

#include"square.h"

class Square;

class PSquare
{
public:
    PSquare();
    ~PSquare();
    void draw(Square& sq,QPainter& painter);
};

#endif // PSQUARE_H
