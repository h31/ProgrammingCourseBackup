#ifndef SAVEDGAMES_H
#define SAVEDGAMES_H

#include <iostream>
#include <fstream>
#include "field.h"

class SavedGames
{
public:
    SavedGames(void);
    void RecordData(char name[], Field* GameField);
    void SaveNameLastGame(char name[]);
    void LoadGame(char name[], Field* GameField);
    void SaveReadyField(Field* GameField, char name[]);
    void SaveRequest(Field* GameField);
    void LoadRequest(Field* GameField);
    ~SavedGames(void);
};


#endif // SAVEDGAMES_H
