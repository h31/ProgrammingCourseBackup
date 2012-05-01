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
	void fieldMake();//���������� ����
	 void print();//����� ����
	 bool permutation(int Px,int Py, int x, int y);//���������� �������� ����
	 void eatenChecker(int Px,int Py, int x, int y);//���������� ���� ��� �������� ����� �����
	 bool secondCourse(int Px,int Py);//���������� ���������� ���� ��� �� ����� ����� ����, ��� ��� "�����" ����� ����������
	 void transformKing();//����������� ����� � �����
	 int endOfGame();//�������� ��������� ����
	 bool testEatenChecker(int Px,int Py, int x, int y);//��������:�������� �� ������ ����� ��� ����� "������" ����� ����������
};

# endif