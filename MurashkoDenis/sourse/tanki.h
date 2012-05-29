#ifndef TANKI_H
#define TANKI_H

#include <iostream>
#include <math.h>
#include <QPainter>
#include <QVector>
#include "puli.h"
#include "pole.h"
#include "bot.h"

using namespace std;

struct TankCoordinates//координаты танка-игрока
{
    int x;
    int y;
};
struct TankVec//для направления движения танка
{
    int x;
    int y;
};

class Igrok//танк-игрок
{
public:
    TankCoordinates koords;
    TankVec vec;
    Field field;
    QVector <Bullet> bullet;//вектор пуль
    int r;//радиус танка
    int speed;//скорость движения танка

    Igrok();//контструктор
    void draw(QPainter &painter);//рисование танка-игрока

};

#endif // TANKI_H
