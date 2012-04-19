#ifndef _PLAYER_H
#define _PLAYER_H

#include"Field.h"

using namespace std;

class Player
{
public:
	Player();
	~Player();
	int ChangeStat(int st,Square &square);
	bool ChangeStat(int st,Field &field, int x, int y);
};

#endif