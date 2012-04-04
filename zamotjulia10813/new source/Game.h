#ifndef _Game_h_
#define _Game_h_
#include "Scenario.h"

class Game { //только она консольная, все остальное-нет.
public:
    Game ();
    ~Game();
    void Upd ();
    int Time; //для груши
    int Cycle; //для змейки
    Scenario1 *Sc1;
};

#endif
