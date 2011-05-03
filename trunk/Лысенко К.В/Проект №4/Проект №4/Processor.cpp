#include "Processor.h"

bool Comp_teams(Team *elem1, Team *elem2)
{
	return elem1->get_points() > elem2->get_points();
}

void Processor::load_table(ifstream &fin, AllGameMatrix *matr, list<Team> *teams)
{
	int beg = fin.tellg();
	for(int num = 0; !fin.eof(); num++)
	{
		string tstr;
		fin >> tstr;
		Team tteam(tstr);
		teams->push_back(tteam);
		bool flag = true;
		while(flag && !fin.eof())
		{
			int tval;
			int pos = fin.tellg();
			fin >> tval;
			if(fin.fail() && !fin.eof())
			{
				fin.seekg(pos);
				flag = false;
			}
			else
			{
				matr->add(tval, num + 1);
			}
		}
	}
	fin.seekg(beg);
}

int Processor::form_list(AllGameMatrix &matr, list<Team> *teams)
{
	list<Team>::iterator itt = teams->begin();
	for(int ix = 0; ix < matr.numstr(); ix++, itt++)
	{
		if(matr[ix][ix] != 0)
			return -5;
		for(int iy = 0; iy < matr[ix].size(); iy++)
		{
			list<Team>::iterator titt = teams->begin();
			for(int j = 0; j < iy; j++, titt++);
			if(ix != iy)
			{
				Game tgame(&(*itt), &(*titt), matr[ix][iy], matr[iy][ix]);
				itt->add_game(tgame);
			}
		}
	}
	return 0;
}

void Processor::form_results(list<Team> *teams, vector<Team*> *ChampTable)
{
	for(list<Team>::iterator itt = teams->begin(); itt != teams->end(); itt++)
		itt->calc_points();
	list<Team>::iterator itt1;
	list<Team>::iterator itt2;
	list<Team>::iterator titt;
	bool flag = true;
	while(flag)
	{
		flag = false;
		for(itt1 = teams->begin(), itt2 = teams->begin(), itt2++; itt2 != teams->end() && !flag; itt1++, itt2++)
		{
			if(itt1->get_points() == itt2->get_points())
			{
				if(itt1->res_conf(&(*itt2)))
				{
					titt = itt1;
					flag = true;
				}
			}
		}
		if(flag)
		{
			list<Team>::iterator itt = teams->begin();
			for( ; itt != titt; itt++)
				itt->add_points(1);
		}
	}
	for(list<Team>::iterator itt = teams->begin(); itt != teams->end(); itt++)
		ChampTable->push_back(&(*itt));
	sort(ChampTable->begin(), ChampTable->end(), Comp_teams);
	int ix = 0;
	int prevpoint = 0;
	int pos = 0;
	for(int ix = 0; ix < ChampTable->size(); ix++)
	{
		if((*ChampTable)[ix]->get_points() != prevpoint)
			pos++;
		(*ChampTable)[ix]->set_position(pos);
		prevpoint = (*ChampTable)[ix]->get_points();
	}
}

int Processor::enter_table(AllGameMatrix *matr, list<Team> *teams)
{
	cout << "¬ведите количество команд: ";
	int kol;
	cin >> kol;
	for(int ix = 0; ix < kol; ix++)
	{
		cout << "¬ведите им€ " << ix+1 << " команды: ";
		string name;
		cin >> name;
		Team tteam(name);
		teams->push_back(tteam);
		cout << "¬ведите строку забитых голов из " << kol << " элементов:" << endl;
		for(int iy = 0; iy < kol; iy++)
		{
			int val;
			cin >> val;
			if(cin.fail())
				return 0;
			matr->add(val, ix + 1);
		}
	}
	return 1;
}