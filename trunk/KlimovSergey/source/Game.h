#ifndef _GAME_H
#define _GAME_H

#include"Field.h"
#include"Player.h"

class Game
{
public:
	int number;
	Game();
	~Game();
	bool Check(Field &field, char* arg);
	bool Start(Field &field, char* arg, Player &player);
};

#endif