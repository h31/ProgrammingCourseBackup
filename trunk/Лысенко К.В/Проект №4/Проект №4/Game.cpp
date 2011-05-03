#include "Game.h"
#include "Team.h"

string Game::winner()
{
	if(goals1 == goals2)
	{
		string tstr = "Ничья";
		return tstr;
	}
	if(goals1 > goals2)
		return team1->get_name();
	else
		return team2->get_name();
}

void Game::print(ostream &out)
{
	out << team1->get_name() << ":" << team2->get_name() << "\t";
	out << goals1 << ":" << goals2;
}

Game::Game(Team *t1, Team *t2, int g1, int g2)
{
	team1 = t1;
	team2 = t2;
	goals1 = g1;
	goals2 = g2;
}

const string &Game::get_t1name()
{
	return team1->get_name();
}

const string &Game::get_t2name()
{
	return team2->get_name();
}