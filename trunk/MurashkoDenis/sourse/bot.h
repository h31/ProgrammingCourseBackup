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
    Field field;
    QVector <Bullet> bbullet;//������ ����
    int alpha; //���� ��������
    int speedb; //�������� �������
    int r;//������ ����

    Bot();//�����������
    void draw(QPainter &painter);//��������� ����
};

#endif // BOT_H
