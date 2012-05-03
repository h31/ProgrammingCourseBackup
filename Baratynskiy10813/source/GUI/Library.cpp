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
//int Library::numberOfWords(QFile &in)
//{
////        in.seekg(0, ios::end);
////        const int numOfWords = in.tellg();
////        in.seekg(0, ios::beg);
////        return numOfWords;
//}

DictionaryWord* Library::takeEng()
{
    QFile file("c://eng_words.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream text(&file);
    srand(time(NULL));
    int numOfWords = 197776;
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
    QFile file("c://rus_words.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream text(&file);
    srand(time(NULL));
    int numOfWords = 1146266;
    randNum = rand() % numOfWords;
    int i = 0;
    while (i != randNum)
    {
        word->word=text.readLine();
        i++;
    }
    return word;
}
