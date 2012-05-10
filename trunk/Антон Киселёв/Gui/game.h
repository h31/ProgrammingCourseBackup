#ifndef GAME_H
#define GAME_H
#include "field.h"
#include "savedGames.h"

class Games
{
    SavedGames *SavedGame;
    void StartGame();
    void OutOfField();
    void PlayGame();
    void GameStep();
    void EndGame();
    void ControlField();
    void SaveGame();
    void LoadGame();
public:
    Field *GameField;
    Games(void);
    int GameLevel(int choice);
    void Menu();
    ~Games(void);
    friend class Test;
};


#endif // GAME_H
