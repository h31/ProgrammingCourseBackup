#ifndef _Game_h_
#define _Game_h_
#include "Scenario.h"

class Game { //консольный класс, все остальные - к консоли не прив€заны
private:
    int time_pear;
    int cycle_snake;
public:
    Game ();
    ~Game();
    Scenario1 *scenario1;
	Scenario2 *scenario2;
	Scenario3 *scenario3;
    int gettime_pear();
    bool settime_pear(int newtime_pear);
    int getcycle_snake();
    bool setcycle_snake(int newcycle_snake);
    void update();
	void printField(Scenario*currentscenario);
	void updateField(Scenario*currentscenario);
	static char intToChar (int Code); //служебна€ функци€ дл€ норм.отрисовки пол€

};

#endif

