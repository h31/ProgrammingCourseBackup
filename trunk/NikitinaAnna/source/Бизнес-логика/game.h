#ifndef _game_h_
#define _game_h_
#include"player.h"
#include"field.h"

enum View
{ 
	black,//�����, �������� �������
	white,//�����, �������� ������
	blank//�����
};

class Game
{
public:
	Game();
	~ Game();
	void findWinner(Field& field);//�������� ���������� ���� � ����������� ����������
	//void sequenceMove(Player& player,Field& field, int Px, int Py, int x, int y);//������� ������������������ �����
	View winner;//��� �������
	bool isWhiteTurn;//��� �� ������ ������ �����
};

#endif