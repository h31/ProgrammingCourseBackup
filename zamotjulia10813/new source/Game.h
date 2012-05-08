#ifndef _Game_h_
#define _Game_h_
#include "Scenario.h"
class Game { //единственный консольный класс
private:
    int time;
    int cycle_snake;
	float score;
public:
    Game ();
    ~Game();
    Scenario1 *scenario1;
	Scenario2 *scenario2;
	Scenario3 *scenario3;
	Scenario  *scenario0;
    int gettime();
    bool settime(int newtime);
    int getcycle_snake();
    bool setcycle_snake(int newcycle_snake);
    void update();
	void printField(Scenario*currentscenario);
	void updateField(Scenario*currentscenario);
	static char intToChar (int code); //служебная функция для норм.отрисовки поля
	static void printToFile(int cycle,Scenario*currentscenario);
};

#endif
