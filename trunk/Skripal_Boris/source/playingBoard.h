#include "figure.h"

#ifndef _playingBoard_h_
#define _playingBoard_h_

class Desk
{
	//очистка доски
	void clearBoard();
public:
	//игровое поле
	Figure desk[8][8];
	//конструктор
	Desk();
	//проверка на мат
	void checkKingsMat(bool whitePlayerTurn);
	//проверка на шах
	void checkKingsShah(bool whitePlayerTurn);
	//распечатка доски
	void printBoard();
};

#endif