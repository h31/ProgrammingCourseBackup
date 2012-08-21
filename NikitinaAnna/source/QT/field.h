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
       int sumWhite;int sumBlack;
public:
     Field();
     ~Field();
    Cell gameField[size][size];//������� ����
    void transformKing(int Px,int Py);//����������� ����� � �����
    int endOfGame();//�������� ��������� ����
     int getSumWhite();int getSumBlack();
     void setSumWhite(int var);
     void setSumBlack(int var);
};


#endif
