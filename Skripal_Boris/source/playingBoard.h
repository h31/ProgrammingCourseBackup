#include "figure.h"

#ifndef _playingBoard_h_
#define _playingBoard_h_

class Desk
{
	//������� �����
	void clearBoard();
public:
	//������� ����
	Figure desk[8][8];
	//�����������
	Desk();
	//�������� �� ���
	void checkKingsMat(bool whitePlayerTurn);
	//�������� �� ���
	void checkKingsShah(bool whitePlayerTurn);
	//���������� �����
	void printBoard();
};

#endif