#include "DictionaryWord.h"
DictionaryWord::DictionaryWord()
{
    for (int i=0;i<6;i++)
        mistakes[i] = ' ';
}
void DictionaryWord::setWord(QString dword)
{
    word = dword;
}
