#include "figure.h"

#ifndef _playingBoard_h_
#define _playingBoard_h_

class Desk
{
	//������� �����
	void createNewPlayingBoard();
	//�������� �� ���
	bool checkKingsMat(bool whitePlayerTurn);
	//�������� �� ���
	bool checkKingsShah(bool whitePlayerTurn);
	//����������� ���� �����
	bool canPawnTurn(int startX,int startY,int finishX,int finishY, bool whitePlayer);
	//����������� ���� ������
	bool canKingTurn(int startX,int startY,int finishX,int finishY);
	//����������� ���� �����
	bool canRookTurn(int startX,int startY,int finishX,int finishY);
	//����������� ���� �����
	bool canQueenTurn(int startX,int startY,int finishX,int finishY);
	//����������� ���� ����
	bool canHourseTurn(int startX,int startY,int finishX,int finishY);
	//����������� ���� �����
	bool canElephantTurn(int startX,int startY,int finishX,int finishY);
public:
	//������� �����
	Figure desk[8][8];
	//�����������
	Desk();
	//���������� �����
	void printBoard();
	//���������� ��������� ������
	void putFigure(Type typeFigure, bool white, int x, int y);

	friend class Player;
};

#endif