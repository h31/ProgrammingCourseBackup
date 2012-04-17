#pragma once
#include <iostream>
#include <fstream>
#include "Field.h"
class SavedGames
{
	int Number;
	char Name[ 100 ];
	int Array[ 9 ][ 9 ];
	void RecordData(char name[], Field GameField);
	void RecordField(char name[], int** GameField);
	void SaveGame();
	void LoadGame(char name[], Field GameField);
public:
	SavedGames(void);
	void SaveField(int** GameField, char name[]);
	bool SaveRequest(Field GameField);
	void LoadRequest(Field GameField);
	~SavedGames(void);
};
