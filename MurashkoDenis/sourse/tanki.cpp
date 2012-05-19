#include"tanki.h"

//методы Tank
void Tank::draw(QPainter &painter)
{
    painter.setPen(Qt::white);
    painter.drawEllipse(QRect(koords.x-r,koords.y-r,2*r,2*r));
    painter.drawEllipse(QRect(koords.x+vec.x-5,koords.y+vec.y-5,10,10));//башня
}
void Tank::redraw(QPainter &painter)
{
    painter.setBrush(QBrush(Qt::black));//закрашивание прямоугольником
    painter.drawRect(0,0,1500,1000);
    draw(painter);
}


/*void Tank::drawBullet(QPainter &painter)//надо передать координаты танка и направляющий вектор
{
    painter.setPen(Qt::white);
    painter.drawLine(koords.x+vec.x*speedB,koords.y+vec.y*speedB,koords.x+vec.x*(speedB+20),koords.y+vec.y*(speedB+20));
}*/

\
