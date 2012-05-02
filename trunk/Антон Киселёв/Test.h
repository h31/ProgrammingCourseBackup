#pragma once
#include "Field.h"
#include "SavedGames.h"
#include "Game.h"
class Test
{
	Game *Sudoku;
	Field *GameField;
	SavedGames *SavedGame;
public:
	void RecordFirstFile();
	void RecordSecondFile();
	bool Test1();
	bool Test2();
	bool Test3();
	bool Test4();
	bool Test5();
	bool Test6();
	bool Test7();
	bool Test8();
	bool Test9();
	bool Test10();
	Test(void);
	bool FullTest();
	~Test(void);
};
