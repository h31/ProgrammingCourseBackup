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
	bool canRokirovkaWhite;
	bool canRokirovkaBlack;
	//��� ������� ��� ������� ������ (true - ������ ����� ����� �������� ������ ��������)
	bool whitePlayerTurn;
	//�������� ����������
	void checkWinner();
	//�������� ����������� ����
	bool canTurn(int startX,int startY,int finishX,int finishY);
public:
	//�����������
	Player();
	//������� ����
	Desk board;
	//���������� ����
	bool makeTurn(int startX,int startY,int finishX,int finishY);
};
#endif