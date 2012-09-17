#include "pole.h"

Field::Field()
{
    x1=0;
    y1=0;
    x2=500;
    y2=500;
    g1=80;
    g2=200;
    a=100;
    b=30;
}

bool Field::proverkaFieldIgrok()
{
    if ((tank.koords.y-tank.r<y1)||(tank.koords.y+tank.r>y2)||
            (tank.koords.x-tank.r<x1)||(tank.koords.x+tank.r>x2))
        return false;
    else
        return true;
}

bool Field::proverkaFieldBot()
{
    if ((bot.koordsb.x-bot.r<x1)||(bot.koordsb.y-bot.r<y1)||
            (bot.koordsb.x+bot.r>x2)||(bot.koordsb.y+bot.r>y2))
    {

        return false;
    }
    else
        return true;
}

bool Field::proverkaFencingOnField()
{
    //проверка в поле ли ограждение
    if ((g1+a<x1)||(g1>x2)||(g2+b<y1)||(g2>y2))
        return false;
    //редактирование границ ограждения если оно вышло за пределы поля
    if (g1<x1)
        g1=x1;
    if (g2<y1)
        g2=y1;
    if (g1+a>x2)
        a=x2-g1;
    if (g2+b>y2)
        b=y2-g2;
    return true;
}

bool Field::proverkaFencing()
{
    //для игрока
    if (((tank.koords.x+tank.r)>g1)&&((tank.koords.x-tank.r)<(g1+a))&&
            ((tank.koords.y+tank.r)>g2)&&((tank.koords.y-tank.r)<(g2+b)))
    {
        return false;
    }
    else
        return true;
    //для бота
    if (((bot.koordsb.x+bot.r)>g1)&&((bot.koordsb.x-bot.r)<(g1+a))&&
            ((bot.koordsb.y+bot.r)>g2)&&((bot.koordsb.y-bot.r)<(g2+b)))
    {
        return false;
    }
    else
        return true;
}
