#ifndef _Scenario_h_
#define _Scenario_h_

#include "Snake.h"
#include "Field.h"
class Scenario1
{
public:
	Field *ScenField;
	Zmeika *ScenZmeika;
	Fructs *ScenFructs;
	Scenario1(void);
	~Scenario1(void);
	void Init();
	bool Run(int Cycle);
};

#endif