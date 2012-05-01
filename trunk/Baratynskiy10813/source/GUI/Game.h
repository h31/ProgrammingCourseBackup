#ifndef GAME_H
#define GAME_H
#include "DictionaryWord.h"
#include "UserWord.h"
#include "Library.h"
#include "Man.h"


class Game
{
    Man *man;
    Library *lib;
    DictionaryWord *dword;
    bool isWon();
    bool isLose();
    bool playAgain();
    void reset();
    ~Game();
    UserWord *uword;
    Game();
public:
    friend class Widget;
};
#endif // GAME_H
