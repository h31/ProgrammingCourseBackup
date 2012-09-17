#include "test.h"

bool Test::proverkaFieldIgrok()//для танка
{

    t.koords.x=100;
    t.koords.y=100;
    if ((t.koords.y-t.r<field.y1)||(t.koords.y+t.r>field.y2)||
            (t.koords.x-t.r<field.x1)||(t.koords.x+t.r>field.x2))
    {
        return false;
    }
    else
        return true;
}
bool Test::proverkaFieldBot()
{
    bott.koordsb.x=70;
    bott.koordsb.y=70;
    if ((bott.koordsb.x-bott.r<field.x1)||(bott.koordsb.y-bott.r<field.y1)||
            (bott.koordsb.x+bott.r>field.x2)||(bott.koordsb.y+bott.r>field.y2))
    {
        return false;
    }
    else
        return true;
}


