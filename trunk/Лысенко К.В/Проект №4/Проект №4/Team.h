#ifndef Team_h
#define Team_h

#include<iostream>
#include<list>
using namespace std;

#include "Game.h"

class Team
{
	string name;
	list<Game> games;
	int points;
	int position;
public:
	Team();
	Team(string &str);
	void set_position(int p);
	void add_game(Game &game);
	bool operator==(Team &team2);
	const string &get_name();
	int get_points();
	void calc_points();
	int res_conf(Team *team2);
	void print_stats(ostream &out);
	void print_results(ostream &out);
	void add_points(int p);
};

#endif