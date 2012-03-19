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
	//ход первого или второго игрока (true - сейчас ходит игрок играющий белыми фигурами)
	bool whitePlayerTurn;
	//проверка победителя
	void checkWinner();
	//проверка возможности хода
	bool canTurn(const int startX,const int startY,const int finishX,const int finishY);
	//рокировка
	bool makeСastling(const int startX,const int startY,const int finishX,const int finishY);
public:
	//конструктор
	Player();
	//игровое поле
	Desk board;
	//совершение хода
	bool makeTurn(const int startX,const int startY,const int finishX,const int finishY);
	//проверка наличия победителя
	bool haveWinner();
	//чей ход текущий
	bool whitePlayerTurnNow();
};
#endif