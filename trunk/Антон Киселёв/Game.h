#pragma once
#include "Field.h"
#include "SavedGames.h"
class Game
{
	Field *GameField;
	SavedGames *SavedGame;
	int GameLevel();
	void StartGame();
	void OutOfField();
	void PlayGame();
	void GameStep();
	void EndGame();
	void ControlField();
	void SaveGame();
	void LoadGame();
public:
	Game(void);
	void Menu();
	~Game(void);
	friend class Test;
};
