#pragma once
#include "Field.h"
class GameLevel
{
	int level;//Уровень сложности
public:
	GameLevel(void);
	int Level(int num);
	int NumberOfGeneration(int level);
	~GameLevel(void);
};
