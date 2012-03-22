#include "figure.h"

#ifndef _playingBoard_h_
#define _playingBoard_h_

class Desk
{
	//очистка доски
	void createNewPlayingBoard();
	//проверка на мат
	bool checkKingsMat(const bool whitePlayerTurn);
	
public:
	//игровая доска
	Figure **desk;
	//конструктор
	Desk();
	//деструктор
	~Desk();
	//распечатка доски
	void printBoard();
	//постановка отдельной фигуры
	void putFigure(Type typeFigure,const bool white, int x, int y);
	//может ли фигура сходить
	bool canFigureTurn(const int startX, const int startY, const int finishX, const int finishY, const bool whitePlayerTurn);
	//проверка на шах
	bool checkKingsShah(const bool whitePlayerTurn);
};

#endif