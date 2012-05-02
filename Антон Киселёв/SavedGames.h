#pragma once
#include <iostream>
#include <fstream>
#include "Field.h"
class SavedGames
{
public:
	SavedGames(void);
	void RecordData(char name[], Field* GameField);
	void SaveNameLastGame(char name[]);
	void LoadGame(char name[], Field* GameField);
	void SaveReadyField(Field* GameField, char name[]);
	bool SaveRequest(int choice, Field* GameField);
	void LoadRequest(int choice, Field* GameField);
	~SavedGames(void);
};
