#pragma once
#include "Field.h"
class GameLevel
{
	int level;//������� ���������
public:
	GameLevel(void);
	int Level(int num);
	int NumberOfGeneration(int level);
	~GameLevel(void);
};
