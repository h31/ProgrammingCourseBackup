#include "Team.h"

bool Team::operator==(Team &team2)
{
	return (name == team2.name);
}

const string &Team::get_name()
{
	return name;
}

Team::Team(string &str)
{
	name = str;
}

void Team::add_game(Game &game)
{
	games.push_back(game);
}

void Team::print_stats(ostream &out)
{
	out << name << endl << "Игры: " << endl;
	for(list<Game>::iterator itt = games.begin(); itt != games.end(); itt++)
	{
		(*itt).print(out);
		out << endl;
	}
	out << "Занятое место: " << position << "\t" << "Очки: " << points;
}

int Team::res_conf(Team *team2)
{
	if(points != team2->points)
		return 1;
	list<Game>::iterator itt = games.begin();
	bool flag = true;
	for( ; itt != games.end() && flag; itt++)
	{
		if((*itt).get_t1name() == team2->name || (*itt).get_t2name() == team2->name)
			flag = false;
	}
	if(flag == true)
		return 0;
	if(itt->winner() == name)
	{
		points++;
		return 1;
	}
	if(itt->winner() == team2->name)
	{
		team2->points += 5;
		return 1;
	}
	return 0;
}

void Team::calc_points()
{
	points = 0;
	for(list<Game>::iterator itt = games.begin(); itt != games.end(); itt++)
	{
		if(itt->winner() == name)
			points += 10;
	}
}

int Team::get_points()
{
	return points;
}

void Team::print_results(ostream &out)
{
	out << position << ". " << name << ' ' << points;
}

void Team::set_position(int p)
{
	position = p;
}

void Team::add_points(int p)
{
	points += p;
}