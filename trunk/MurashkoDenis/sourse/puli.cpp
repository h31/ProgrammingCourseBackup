
#include "puli.h"
Bullet::Bullet()
{
    speed = 10;
    l=10;
}

Bullet &Bullet::operator =(const Bullet &b)//���������� ���������� ��������� ���� �������
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
    painter.setPen(Qt::green);
    painter.drawLine(coords.x,coords.y,coords.x+l* alpha.x,coords.y+l* alpha.y);
}
