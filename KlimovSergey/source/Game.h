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
	bool Start(Field &field, char* arg, Player &player);
};

#endif