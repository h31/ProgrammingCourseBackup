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
    bool proverkaFieldIgrok(); //��������� ��������� �� ����-����� �� ����(� ��������� ���������)
    bool proverkaFieldBot(); //��������� ��������� �� ����-��� �� ����(� ��������� ���������)

};

#endif // TEST_H
