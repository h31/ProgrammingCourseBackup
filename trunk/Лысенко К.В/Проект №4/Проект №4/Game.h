#ifndef Game_h
#define Game_h

#include<string>
using namespace std;

class Team;

class Game
{
	Team *team1;
	Team *team2;
	int goals1;
	int goals2;
public:
	Game();
	Game(Team *t1, Team *t2, int g1, int g2);
	string winner();
	const string &get_t1name();
	const string &get_t2name();
	void print(ostream &out);
};

#endif