#ifndef POLE_H
#define POLE_H
#include "tanki.h"
#include "bot.h"
struct Field //������� ����
{
    //������� ����
    int x1;
    int y1;
    int x2;
    int y2;

    //�����������
    int g1;
    int g2;
    int a;//�����
    int b;//������
    Field();//�����������
    Igrok tank;
    Bot bot;
    bool proverkaFieldIgrok();//�������� ������ ���� ��� ������
    bool proverkaFieldBot();//�������� ������ ���� ��� ����
    bool proverkaFencingOnField();//�������� ������������ ������������ ������
    bool proverkaFencing();
};

#endif // POlE_H
