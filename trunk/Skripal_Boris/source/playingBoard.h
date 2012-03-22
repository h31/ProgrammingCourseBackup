#include "figure.h"

#ifndef _playingBoard_h_
#define _playingBoard_h_

class Desk
{
	//������� �����
	void createNewPlayingBoard();
	//�������� �� ���
	bool checkKingsMat(const bool whitePlayerTurn);
	
public:
	//������� �����
	Figure **desk;
	//�����������
	Desk();
	//����������
	~Desk();
	//���������� �����
	void printBoard();
	//���������� ��������� ������
	void putFigure(Type typeFigure,const bool white, int x, int y);
	//����� �� ������ �������
	bool canFigureTurn(const int startX, const int startY, const int finishX, const int finishY, const bool whitePlayerTurn);
	//�������� �� ���
	bool checkKingsShah(const bool whitePlayerTurn);
};

#endif