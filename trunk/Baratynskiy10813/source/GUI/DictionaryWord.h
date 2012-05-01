#ifndef DICTIONARYWORD_H
#define DICTIONARYWORD_H
#include "BasicWord.h"

class DictionaryWord : public BasicWord
{
public:
    DictionaryWord();
    void setWord(QString dword);
};
#endif
