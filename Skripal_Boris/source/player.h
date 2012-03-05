#include "playingBoard.h"

#ifndef _player_h_
#define _player_h_
//������������ �����������
enum Winner
{
	black,//������ ������
	white,//����� ������
	nobody,//�����
	draw//�����
};
class Player
{
	//������� ����������
	Winner winner;
	//����������� ���������
	bool canRokirovka;
	//��� ������� ��� ������� ������ (true - ������ ����� ����� �������� ������ ��������)
	bool whitePlayerTurn;
	//�������� ����������
	void checkWinner();
	//�������� ����������� ����
	void canTurn(int startX,int startY,int finishX,int finishY);
public:
	//�����������
	Desk board;
	//���������� ����
	void makeTurn(int startX,int startY,int finishX,int finishY);
};
#endif