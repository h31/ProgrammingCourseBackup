#ifndef _field_h_
#define _field_h_


const int size=8;
enum Cell//��������� ������
{
         empty=0,//�����
         whiteShashka=1,//����� �����
         blackShashka=2,//������ �����
         whiteKing=8,//����� �����
         blackKing=9//������ �����
};
class Field
    {
public:
     Field();
     ~Field();
    Cell gameField[size][size];//������� ����
    void transformKing();//����������� ����� � �����
    int endOfGame();//�������� ��������� ����
};


#endif