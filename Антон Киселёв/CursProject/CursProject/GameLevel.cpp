#include "GameLevel.h"
#include "Field.h"
GameLevel::GameLevel(void)
{
}
//Возвращаем число пропусков
int GameLevel::Level(int num)
{
	int level = num;
	int Gener = NumberOfGeneration(level);
	return Gener;
}
//Определяем число пропусков
int GameLevel::NumberOfGeneration(int level)
{
	if (level == 1)
		return 9;
	else if (level == 2)
		return 20;
	else if (level == 3)
		return 60;
}

GameLevel::~GameLevel(void)
{
}
