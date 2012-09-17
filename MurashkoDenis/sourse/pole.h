#ifndef POLE_H
#define POLE_H
#include "tanki.h"
#include "bot.h"
struct Field //игровое поле
{
    //границы поля
    int x1;
    int y1;
    int x2;
    int y2;

    //препятствие
    int g1;
    int g2;
    int a;//длина
    int b;//ширина
    Field();//конструктор
    Igrok tank;
    Bot bot;
    bool proverkaFieldIgrok();//проверка границ поля для игрока
    bool proverkaFieldBot();//проверка границ поля для бота
    bool proverkaFencingOnField();//проверка правельности расположения ограды
    bool proverkaFencing();
};

#endif // POlE_H
