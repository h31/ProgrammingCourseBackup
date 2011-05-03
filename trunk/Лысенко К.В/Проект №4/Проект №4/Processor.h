#ifndef Processor_h
#define Processor_h

#include<fstream>
#include<algorithm>
using namespace std;

#include "Team.h"
#include "AllGameMatrix.h"

class Processor
{
public:
	void load_table(ifstream &fin, AllGameMatrix *matr, list<Team> *teams);
	int form_list(AllGameMatrix &matr, list<Team> *teams);
	void form_results(list<Team> *teams, vector<Team*> *ChampTable);
	int enter_table(AllGameMatrix *matr, list<Team> *teams);
};

bool Comp_teams(Team *elem1, Team *elem2);

#endif