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
DictionaryWord* Library::takeWord(QFile &in)
{
        QTextStream text(&in);
        srand(time(NULL));
        int numOfWords = 19000;//numberOfWords(in);
        randNum = rand() % numOfWords;
        int i = 0;
        while (i != randNum)
        {
            word->word=text.readLine();
            i++;
        }
    return word;
}
DictionaryWord* Library::takeWordOfLang()
{
    QFile file("c://eng_words.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    word=takeWord(file);
    return word;
}
