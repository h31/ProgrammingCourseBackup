#ifndef _player_h_
#define _player_h_
#include"field.h"

class Player
{
	int opponentX;
	int opponentY;
public:
	Player();
	~Player();
	bool permutation(int Px,int Py, int x, int y,Field& field);//���������� �������� ����
	bool testEatenChecker(int Px,int Py, int x, int y,Field& field);//��������:�������� �� ������ ����� ��� ����� "������" ����� ����������
	void eatenChecker(int Px,int Py, int x, int y,Field& field);//���������� ���� ��� �������� ����� �����
	bool secondCourse(int Px,int Py,Field& field);//���������� ���������� ���� ��� �� ����� ����� ����, ��� ��� "�����" ����� ����������
};

#endif