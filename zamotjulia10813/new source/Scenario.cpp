#include "stdafx.h"
#include "Scenario.h"

Scenario:: Scenario(void)
{
}
Scenario:: ~Scenario(void){};

Scenario1::Scenario1(void) { init();};
Scenario1:: ~Scenario1(void) {};

void Scenario1::init ()
{
    scenarioField= new Field(6,6);
    scenarioZmeika= new Zmeika(1,2,dtop,4);
	scenarioFructs =new Fructs(0);
	Apple* ScApp=new Apple(3,0);
	this->scenarioFructs->addApple(ScApp);
}

bool Scenario1::run(int cycle_snake)
{
    switch (cycle_snake)
    {
    case 1:
        return scenarioZmeika->move();
        break;
    case 2:
        return scenarioZmeika->move();
        break;
    case 3:
        return scenarioZmeika->rotateRight();
        break;
    case 4:
        return scenarioZmeika->move();
        break;
	case 5:
        return scenarioZmeika->move();
        break;
	case 6:
        return scenarioZmeika->move();
        break;
    default:
        return false;
        break;
    }
	return false;
}

Scenario2::Scenario2(void) {init();};
Scenario2:: ~Scenario2(void) {};

void Scenario2:: init() {
    scenarioField= new Field(8,8);
    scenarioZmeika= new Zmeika(2,2,dtop,4);
	scenarioFructs =new Fructs(0);

}

bool Scenario2::run(int cycle_snake) // в стенку
{
    switch (cycle_snake)
    {
    case 1:
        return scenarioZmeika->move();
        break;
    case 2:
        return scenarioZmeika->move();
        break;
    case 3:
        return scenarioZmeika->move();
        break;
   
    default:
        return false;
        break;
    }
	return false;
}

Scenario3::Scenario3(void) {init();};
Scenario3:: ~Scenario3(void) {};

void Scenario3:: init() 
{
	scenarioField= new Field(5,5);
	scenarioZmeika= new Zmeika(1,1,dtop,4);
	scenarioFructs =new Fructs(0);

}

bool Scenario3::run(int cycle_snake) // в себя
{
    switch (cycle_snake)
    {
    case 1:
        return scenarioZmeika->rotateRight();
        break;
    case 2:
        return scenarioZmeika->move();
        break;
    case 3:
        return scenarioZmeika->rotateDown();
        break;
    case 4:
        return scenarioZmeika->move();
        break;
	case 5:
		return scenarioZmeika->rotateLeft();
        break;
	case 6:
    return scenarioZmeika->move();
        break;
	default:
        return false;
        break;
    }
	return false;
}