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
	//��� ������� ��� ������� ������ (true - ������ ����� ����� �������� ������ ��������)
	bool whitePlayerTurn;
	//�������� ����������
	void checkWinner();
	//�������� ����������� ����
	bool canTurn(const int startX,const int startY,const int finishX,const int finishY);
	//���������
	bool make�astling(const int startX,const int startY,const int finishX,const int finishY);
public:
	//�����������
	Player();
	//������� ����
	Desk board;
	//���������� ����
	bool makeTurn(const int startX,const int startY,const int finishX,const int finishY);
	//�������� ������� ����������
	bool haveWinner();
	//��� ��� �������
	bool whitePlayerTurnNow();
};
#endif