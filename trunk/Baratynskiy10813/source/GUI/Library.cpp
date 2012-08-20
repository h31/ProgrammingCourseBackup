#include "Library.h"
#include <ctime>
#include "QTextStream"
Library::Library()
{
    word = new DictionaryWord;
}
Library::~Library()
{
    delete [] word;
}

DictionaryWord* Library::takeEng()
{
    QFile file("c://Hangman/eng_words.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream text(&file);
    srand(time(NULL));
    int numOfWords = 19776;
    randNum = rand() % numOfWords;
    int i = 0;
    while (i != randNum)
    {
        word->word=text.readLine();
        i++;
    }
    return word;
}

DictionaryWord* Library::takeRus()
{
    QFile file("c://Hangman/rus_words.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream text(&file);
    srand(time(NULL));
    int numOfWords = 14842;
    randNum = rand() % numOfWords;
    int i = 0;
    while (i != randNum)
    {
        word->word=text.readLine();
        i++;
    }
    return word;
}
