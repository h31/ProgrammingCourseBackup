#ifndef LIBRARY_H
#define LIBRARY_H
#include "QFile"
#include "QTextStream"
#include "DictionaryWord.h"

class Library
{
    int randNum;
    int var;
    DictionaryWord *word;
    int numberOfWords(QFile &in);
public:
    Library();
    ~Library();
    DictionaryWord* takeEng();
    DictionaryWord* takeRus();
};
#endif
