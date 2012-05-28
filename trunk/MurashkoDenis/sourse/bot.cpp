#include "bot.h"

Bot::Bot()
{
    koordsb.x=300;
    koordsb.y=200;
    speedb=10;
    r=20;
    vecb.x=0;
    vecb.y=0;
}

void Bot::draw(QPainter &painter)
{
    painter.setPen(Qt::red);
    painter.drawEllipse(QRect(koordsb.x-r,koordsb.y-r,2*r,2*r));
    painter.drawEllipse(QRect(koordsb.x+vecb.x-5,koordsb.y+vecb.y-5,10,10));

}

