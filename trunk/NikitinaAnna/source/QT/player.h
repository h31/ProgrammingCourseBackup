#ifndef _player_h_
#define _player_h_
#include"field.h"

class Player
{
    int opponentX;
    int opponentY;
public:
    Player();
    ~Player();
    void permutation(int Px,int Py, int x, int y,Field& field);//Реализация обычного хода
    bool testPermutation(int Px,int Py, int x, int y,Field& field);
    bool testEatenChecker(int Px,int Py, int x, int y,Field& field);//Проверка:возможно ли данной шашке или дамке "съесть" шашку противника
    void eatenChecker(int Px,int Py, int x, int y,Field& field);//Реализация хода при съедении шашки врага
    bool secondCourse(int Px,int Py,Field& field);//Реализация следующего хода той же шашки после того, как она "съела" шашку противника
    bool falseTurn(int x, int y,Field& field);
};

#endif
