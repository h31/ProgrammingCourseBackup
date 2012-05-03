#ifndef GAME_H
#define GAME_H
#include "DictionaryWord.h"
#include "UserWord.h"
#include "Library.h"
#include "Man.h"


class Game
{
public:
    Man *man;
    Library *lib;
    DictionaryWord *dword;
    bool isWon();
    bool isLose();
    ~Game();
    UserWord *uword;
    Game();
};
#endif // GAME_H
