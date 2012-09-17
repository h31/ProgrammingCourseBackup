#ifndef BOT_H
#define BOT_H

#include <QPainter>
#include "tanki.h"
#include <conio.h>
struct BotCoordinates //координаты
{
    int x;
    int y;
};

struct VecBot //угол движения
{
    int x;
    int y;
};
class Bot
{
public:
    BotCoordinates koordsb;
    VecBot vecb;
    QVector <Bullet> bbullet;//вектор пуль
    int alpha; //угол движения
    int speedb; //скорость дижения
    int r;//радиус бота

    Bot();//конструктор

};

#endif // BOT_H
