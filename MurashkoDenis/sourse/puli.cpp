
#include "puli.h"
void Bullet::draw(QPainter &painter)//надо передать координаты танка и направляющий вектор
{
    painter.setPen(Qt::white);
    painter.drawLine(coords.x,coords.y,coords.x+10*alpha.x,coords.y+10*alpha.y);
}

void Bullet::moveBulletOnTimeout()
{
    coords.x = coords.x + speed;
    coords.y = coords.y + speed;
}
