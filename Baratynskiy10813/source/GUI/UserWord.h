#ifndef USERWORD_H
#define USERWORD_H
#include "BasicWord.h"
#include "DictionaryWord.h"

class UserWord : public BasicWord
{
public:
    void enterLetter();
    UserWord();
    void makeUserWord(DictionaryWord dword);
    void putMistake(int curMisses);
    bool checkLetter(DictionaryWord dword);
    void putLetter(DictionaryWord dword);
};
#endif
