#pragma once
#include <iostream>
#include <fstream>
#include "Field.h"
class SavedGames
{
	int Number;
	char Name[ 100 ];
	int Array[ 9 ][ 9 ];
public:
	SavedGames(void);
	void SaveField(Field GameField, char name[]);
	bool SaveRequest(Field GameField);
	void RecordData(char name[], Field GameField);
	void SaveGame();
	void LoadRequest(Field GameField);
	void LoadGame(char name[], Field GameField);
	~SavedGames(void);
};
