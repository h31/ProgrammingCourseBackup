#ifndef _game_h_
#define _game_h_
#include"player.h"
#include"field.h"

enum View
{ 
	black,//Игрок, играющий черными
	white,//Игрок, играющий белыми
	blank//Ничья
};

class Game
{
public:
	Game();
	~ Game();
	void findWinner(Field& field);//проверка завершения игры и определение победителя
	//void sequenceMove(Player& player,Field& field, int Px, int Py, int x, int y);//задание последовательности ходов
	View winner;//Кто выиграл
	bool isWhiteTurn;//Кто на данный момент ходит
};

#endif