#include "BasicWord.h"
BasicWord::BasicWord()
{
    for (int i=0;i<6;i++)
        mistakes[i] = ' ';
}
QString BasicWord::getWord()
{
    return word;
}
