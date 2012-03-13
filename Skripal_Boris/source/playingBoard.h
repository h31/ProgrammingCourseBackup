#include "figure.h"

#ifndef _playingBoard_h_
#define _playingBoard_h_

class Desk
{
	//очистка доски
	void createNewPlayingBoard();
	//проверка на мат
	bool checkKingsMat(bool whitePlayerTurn);
	//проверка на шах
	bool checkKingsShah(bool whitePlayerTurn);
	//возможность хода пешки
	bool canPawnTurn(int startX,int startY,int finishX,int finishY, bool whitePlayer);
	//возможность хода короля
	bool canKingTurn(int startX,int startY,int finishX,int finishY);
	//возможность хода ладьи
	bool canRookTurn(int startX,int startY,int finishX,int finishY);
	//возможность хода ферзя
	bool canQueenTurn(int startX,int startY,int finishX,int finishY);
	//возможность хода коня
	bool canHourseTurn(int startX,int startY,int finishX,int finishY);
	//возможность хода слона
	bool canElephantTurn(int startX,int startY,int finishX,int finishY);
public:
	//игровая доска
	Figure desk[8][8];
	//конструктор
	Desk();
	//распечатка доски
	void printBoard();
	//постановка отдельной фигуры
	void putFigure(Type typeFigure, bool white, int x, int y);

	friend class Player;
};

#endif