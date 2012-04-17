#ifndef _Scenario_h_
#define _Scenario_h_

#include "Snake.h"
#include "Field.h"

class Scenario
{
	public:
    Field *scenarioField;
    Zmeika *scenarioZmeika;
    Fructs *scenarioFructs;
    Scenario(void);
    ~Scenario(void);
    void virtual init ()=0;
    bool virtual run(int cycle_snake)=0;

};
class Scenario1: public Scenario
{
public: 
    Scenario1(void);
    ~Scenario1(void);
    void init ();
    bool run(int cycle_snake);
};

class Scenario2:  public Scenario
{
public:
    Scenario2(void);
    ~Scenario2(void);
    void init ();
    bool run(int cycle_snake);
};

class Scenario3: public Scenario
{
public:
    Scenario3(void);
    ~Scenario3(void);
    void init ();
    bool run(int cycle_snake);
};


#endif
