#ifndef TANKI_H
#define TANKI_H
#include<iostream>
#include<math.h>
#include<QList>
#include <QPainter>
#include "puli.h"

using namespace std;

struct TankCoordinates
{
    int x;
    int y;
};
struct TankVec//для направления движения танка
{
    int x;
    int y;
};

class Tank
{
public:

    TankCoordinates koords;
    TankVec vec;
    Bullet bullet;
    int r;
    int speed;
    int speedB;
    void draw(QPainter &painter);
    void redraw(QPainter &painter);
    //void drawBullet(QPainter &painter);
};

#endif // TANKI_H
