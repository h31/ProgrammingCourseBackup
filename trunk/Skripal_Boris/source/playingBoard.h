#include "figure.h"

#ifndef _playingBoard_h_
#define _playingBoard_h_

class Desk
{
	//������� ����
	Figure desk[8][8];

public:
	//�����������
	Desk();
	//������� �����
	void clearBoard();
	//�������� �� ���
	void checkKingsMat(bool whitePlayerTurn);
	//�������� �� ���
	void checkKingsShah(bool whitePlayerTurn);
	//���������� �����
	void printBoard();
};

#endif