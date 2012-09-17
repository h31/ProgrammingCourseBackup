#ifndef TEST_H
#define TEST_H
#include "tanki.h"
#include "bot.h"
#include "pole.h"
//#include <QMainWindow>
//#include <QtGui>
//#include <QPainter>
class Test
{
public:
    Igrok t;
    Bot bott;
    Field field;
    bool proverkaFieldIgrok(); //проверяет находится ли танк-игрок на поле(в начальном положении)
    bool proverkaFieldBot(); //проверяет находится ли танк-бот на поле(в начальном положении)

};

#endif // TEST_H
