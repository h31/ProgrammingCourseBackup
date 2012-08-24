#ifndef SAVEDGAMES_H
#define SAVEDGAMES_H

#include <QFile>
#include <QTextStream>
#include <cstdlib>
#include <string>
#include "field.h"

class SavedGames
{
public:
    SavedGames(void);
    void RecordData(char name[], Field* GameField);
    void LoadGame(char name[], Field* GameField);
    void SaveReadyField(Field* GameField, char name[]);
    void SaveRequest(Field* GameField);
    void LoadRequest(Field* GameField);
    ~SavedGames(void);
};
#endif // SAVEDGAMES_H
