#include"tanki.h"

//методы Tank
Igrok::Igrok()
{
    koords.x=100;
    koords.y=100;
    speed=2;
    vec.x=0;
    vec.y=0;
    r=20;
}

void Igrok::draw(QPainter &painter)
{
    painter.setBrush(Qt::blue);
    painter.setPen(Qt::blue);
    painter.drawEllipse(QRect(koords.x-r,koords.y-r,2*r,2*r));
    painter.setPen(Qt::white);
    painter.drawEllipse(QRect(koords.x+vec.x-5,koords.y+vec.y-5,10,10));//башня
}



\
