#ifndef BOT_H
#define BOT_H

#include <QPainter>
#include "tanki.h"
#include <conio.h>
struct BotCoordinates //����������
{
    int x;
    int y;
};

struct VecBot //���� ��������
{
    int x;
    int y;
};
class Bot
{
public:
    BotCoordinates koordsb;
    VecBot vecb;
    QVector <Bullet> bbullet;//������ ����
    int alpha; //���� ��������
    int speedb; //�������� �������
    int r;//������ ����

    Bot();//�����������

};

#endif // BOT_H
