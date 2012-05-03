#ifndef BASICWORD_H
#define BASICWORD_H
#include <QString>

class BasicWord
{
protected:
    QChar letter;
    QString word;
public:
    BasicWord();
    QChar mistakes[6];
    QString getWord();
    friend class Library;
    friend class MainWidget;
    friend class RussianWidget;
};
#endif
