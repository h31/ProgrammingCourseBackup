#include "playingBoard.h"

#ifndef _player_h_
#define _player_h_
//перечисление победителей
enum Winner
{
	black,//чёрные фигуры
	white,//белые фигуры
	nobody,//никто
	draw//ничья
};
class Player
{
	//текущий победитель
	Winner winner;
	//возможность рокировки
	bool canRokirovkaWhite;
	bool canRokirovkaBlack;
	//ход первого или второго игрока (true - сейчас ходит игрок играющий белыми фигурами)
	bool whitePlayerTurn;
	//проверка победителя
	void checkWinner();
	//проверка возможности хода
	bool canTurn(int startX,int startY,int finishX,int finishY);
public:
	//конструктор
	Player();
	//игровое поле
	Desk board;
	//совершение хода
	bool makeTurn(int startX,int startY,int finishX,int finishY);
};
#endif