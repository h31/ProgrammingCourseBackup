
#include "puli.h"
Bullet::Bullet()
{
    speed = 15;
    l=10;
}

Bullet &Bullet::operator =(const Bullet &b)//компилятор потребовал написания этой функции
{
    coords = b.coords;
    alpha = b.alpha;
    speed = b.speed;
    l = b.l;
    return *this;
}


Bullet::Bullet(const Bullet &b): coords(b.coords), alpha(b.alpha), speed(b.speed), l(b.l)
{
}

void Bullet::drawp(QPainter &painter)
{
    painter.setPen(Qt::yellow);
    painter.drawLine(coords.x,coords.y,coords.x+l* alpha.x,coords.y+l* alpha.y);
}
