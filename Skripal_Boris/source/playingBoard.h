#include "figure.h"

#ifndef _playingBoard_h_
#define _playingBoard_h_

class Desk
{
	//игровое поле
	Figure desk[8][8];

public:
	//конструктор
	Desk();
	//очистка доски
	void clearBoard();
	//проверка на мат
	void checkKingsMat(bool whitePlayerTurn);
	//проверка на шах
	void checkKingsShah(bool whitePlayerTurn);
	//распечатка доски
	void printBoard();
};

#endif