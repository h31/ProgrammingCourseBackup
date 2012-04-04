#include "Scenario.h"

Scenario1::Scenario1(void)
{
	Init();
}

Scenario1::~Scenario1(void)
{
}

void Scenario1::Init()
{
	ScenField= new Field(6,6);
	ScenZmeika= new Zmeika(1,2,-1,0,3);
	//ScenFructs->addApple();
}

bool Scenario1::Run(int Cycle)
{
	switch(Cycle)
	{
	case 1:
		return ScenZmeika->Move();
		break;
	case 2:
		return ScenZmeika->Move();
		break;
	case 3:
		return ScenZmeika->RotateRight();
		break;
	case 4:
		return ScenZmeika->Move();
		break;
	case 5:
		return ScenZmeika->Check();
		break;
	
	default:
		return false;
		break;
	}
}