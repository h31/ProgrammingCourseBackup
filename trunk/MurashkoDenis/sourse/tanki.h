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

struct TankCoordinates//���������� �����-������
{
    int x;
    int y;
};
struct TankVec//��� ����������� �������� �����
{
    int x;
    int y;
};

class Igrok//����-�����
{
public:
    TankCoordinates koords;
    TankVec vec;
    Field field;
    QVector <Bullet> bullet;//������ ����
    int r;//������ �����
    int speed;//�������� �������� �����

    Igrok();//������������
    void draw(QPainter &painter);//��������� �����-������

};

#endif // TANKI_H
