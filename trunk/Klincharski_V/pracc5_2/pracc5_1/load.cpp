#include "load.h"

void load::AddLd(teacher tch1, group gr1, char *_out)
{
	ofstream out(_out,ios::app);
	out << endl << tch1.retName()  << " " << tch1.retSurname() << " " << tch1.retPatr() << " ";gr1.printInfo(out);
}

void load::AddLd(teacher tch1, group gr1)
{
	string tch_name;
	tch_name = tch1.retName() + " " + tch1.retSurname() + " " + tch1.retPatr();
	ld.insert (pair<string,group>(tch_name,gr1));
}

void load::buildLd(ifstream &in)
{
	teacher tch;
	group gr;

	while(!in.eof())
	{
		tch.getTeacherName(in);
		gr.getInfo(in);
		string temp;

		// in >> temp >> temp;
		AddLd(tch, gr);
	}
}

void load::printLoad()
{
	multimap<string,group>::iterator it = ld.begin();
	multimap<string,group>::const_iterator end = ld.end();

	for ( ; it != end; ++it) 
	{
		cout << (it->first);
		cout << " ";
		(it->second).printInfo();
		cout << endl;

	}
}

void load::buildPay(std::ifstream &in_tch)
{
	multimap<string,group> _ld;
	_ld = ld;
	while (!in_tch.eof())
	{
		teacher tch1;
		tch1.getTeacherInfo(in_tch);
		string tch_name = tch1.retName() + " " + tch1.retSurname() + " " + tch1.retPatr();
		int count = 0;
		for(;;)
		{
			if(_ld.find(tch_name) != _ld.end())
			{
				count++;
				_ld.erase(_ld.find(tch_name));
			}
			else
			{
				break;
			}
		}
		pay[tch_name] = rescost(tch1);
	}
}

void load::printPay()
{
	map<string,int>::iterator it = pay.begin();
	map<string,int>::const_iterator end = pay.end();

	for ( ; it != end; ++it) 
	{
		cout << (it->first);
		cout << " ";
		cout << (it->second);
		cout << endl;

	}
}

void load::findData(teacher tch1)
{
	cout << endl << "Для преподавателя " << tch1.retName() << " " << tch1.retSurname() << " " << tch1.retPatr() << " " << "найдено :" << endl;

	multimap<string, group> _ld;
	_ld = ld;
	string tch_name = tch1.retName() + tch1.retSurname() + tch1.retPatr();
	
	for(;;)
		{
		if(_ld.find(tch_name)!= _ld.end())
		{
			_ld.find(tch_name)->second.printInfo();
			_ld.erase(_ld.find(tch_name));
			cout << endl;
		}
		else
		{
			break;
		}
	}
	cout << endl << "Заработано: " << pay.find(tch_name)->second << endl;
}

int load::rescost(teacher &tch)
{
	int cost = 0;
	string tch_name = tch.retName() + " " + tch.retSurname() + " " + tch.retPatr();

	if (ld.find(tch_name) == ld.end())
	{
		return 0;
	}
	multimap<string, group> _ld;
	_ld = ld;
	
	while(_ld.find(tch_name) != _ld.end())
	{
		string temp_subj;
		string temp_empltype;
		
		temp_subj = _ld.find(tch_name)->second.retSubj();
		temp_empltype = _ld.find(tch_name)->second.retEmpltype();

		
		if(temp_empltype == "lection")
		{
			cost = cost + LECTION_COST;
		}
		else if(temp_empltype == "practice")
		{
			cost = cost + PRACTICE_COST;
		}

		if(temp_subj == "math")
		{
			cost = cost + SUBJ_MATH;
		}
		else if(temp_subj == "fiz")
		{
			cost = cost + SUBJ_FIZ;
		}
		else if(temp_subj == "eco")
		{
			cost = cost + SUBJ_ECO;
		}

		_ld.erase(tch_name);
	}

	return cost;
}