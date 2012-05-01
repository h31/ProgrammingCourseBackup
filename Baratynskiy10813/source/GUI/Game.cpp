#include "Game.h"

Game::Game()
{
    man = new Man;
    dword = new DictionaryWord;
    uword = new UserWord;
    lib = new Library;
}
Game::~Game()
{
    delete[] man;
    delete[] dword;
    delete[] uword;
    delete[] lib;
}
bool Game::isWon()
{
    if (uword->getWord() == dword->getWord())
        return true;
    else return false;
}
bool Game::isLose()
{
    if (man->curMisses==man->maxMisses)
        return true;
    else return false;
}
void Game::reset()
{
    man->curMisses=0;
    for (int i=0;i<=man->maxMisses;i++)
    {
        man->man[i] = ' ';
        uword->mistakes[i] = ' ';
    }
}
