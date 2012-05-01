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
    DictionaryWord* takeWord(QFile &in);
public:
    Library();
    ~Library();
    DictionaryWord* takeWordOfLang();
    int chooseTheme();
};
#endif
