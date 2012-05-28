#ifndef CHECK_H
#define CHECK_H

#include "field.h"

class Check{
    Field f;
    bool checkSameValues(int, int, int, int);
    bool checkSumValues(int, int, int, int);
    bool checkPlace(int, int, int, int);
    bool nullValue(int, int, int, int);
    bool checkSamePlace(int, int, int, int);
    bool checkLoss();
    bool checkWin();
public:
    Check();
    Check(Field&);
    bool checkMove(int, int, int, int);
    bool getLoss();
};


#endif // CHECK_H
