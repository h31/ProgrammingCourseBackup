#include "Man.h"
Man:: Man()
{
    maxMisses=6;
    curMisses=0;
}
QPicture Man::createMan()
{
    switch(curMisses)
    {
    case 1:
        picture.load("#1.png");
    case 2:
        picture.load("#2.png");
    case 3:
        picture.load("#3.png");
    case 4:
        picture.load("#4.png");
    case 5:
        picture.load("#5.png");
    case 6:
        picture.load("#6.png");
    }
    return picture;
}

