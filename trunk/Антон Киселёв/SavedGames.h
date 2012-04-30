#pragma once
#include <iostream>
#include <fstream>
#include "Field.h"
class SavedGames
{
	int Number;
	char Name[ 100 ];
	int FirstArray[ 9 ][ 9 ];
	int SecondArray[ 9 ][ 9 ];
	void RecordData(char name[], Field* GameField);
	void RecordField(char name[], Field* GameField);
	void SaveGameField();
	void SaveGame();
	void LoadGame(char name[], Field* GameField);
public:
	SavedGames(void);
	void SaveField(Field* GameField, char name[]);
	bool SaveRequest(Field* GameField);
	void LoadRequest(Field* GameField);
	~SavedGames(void);
};
