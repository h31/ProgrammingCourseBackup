#ifndef MAN_H
#define MAN_H
#include <QString>
#include "QPainter"
#include "QPicture"

class Man
{
public:
    QChar man[6];
    int maxMisses;
    int curMisses;
    QPicture picture;
    Man();
    QPicture createMan();
};
#endif // MAN_H
