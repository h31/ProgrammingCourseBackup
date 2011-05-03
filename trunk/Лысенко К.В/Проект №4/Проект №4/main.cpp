#include<cstring>
using namespace std;

#include "Processor.h"

int main()
{
	setlocale(LC_ALL,"Russian");
	list<Team> teams;
	vector<Team*> ChampionshipTable;
	AllGameMatrix matrix;
	Processor proc;

	cout << "�������� ������ ������� ������� ���: " << endl;
	bool flag = true;
	while(flag)
	{
		cout << "1) �������\t2) �� �����" << endl;
		int num;
		cin.ignore(cin.rdbuf()->in_avail());
		cin >> num;
		switch(num)
		{
		case 1:
			{
				if(proc.enter_table(&matrix, &teams))
					flag = false;
				else
				{
					matrix.clear();
					teams.erase(teams.begin(), teams.end());
					cout << "������������ ���� ������, ���������� �����" << endl;
				}
				break;
			}
		case 2:
			{
				char *ifname;
				bool flag2 = true;
				cout << "��� �������� �����" << endl;
				cout << "1) ������ �������\t2) ������������ �� ���������" << endl;
				while(flag2)
				{
					int num;
					cin.ignore(cin.rdbuf()->in_avail());
					cin >> num;
					switch(num)
					{
					case 1:
						{
							cout << "��� �����: ";
							string tstr;
							cin >> tstr;
							ifname = new char [tstr.size() + 1];
							strcpy(ifname, tstr.c_str());
							flag2 = false;
							break;
						}
					case 2:
						{
							ifname = new char [strlen("table.txt") + 1];
							strcpy(ifname, "table.txt");
							flag2 = false;
							break;
						}
					}
				}
				ifstream fin(ifname);
				if(!fin)
				{
					cout << "������ �������� �������� �����" << endl;
					return -1;
				}
				proc.load_table(fin, &matrix, &teams);
				if(!matrix.issquare() || matrix.numstr() != teams.size())
				{
					cout << "������������ ������ ������� ������" << endl;
					return -2;
				}
			}
			flag = false;
		}
	}
	proc.form_list(matrix, &teams);
	proc.form_results(&teams, &ChampionshipTable);

	cout << endl << "�������� ������ ������" << endl;
	cout << "1) � ����\t2) �� �������\t3) � � ���� � �� �������" << endl;
	bool file = false;
	bool cons = false;
	flag = true;
	while(flag)
	{
		int num;
		cin.ignore(cin.rdbuf()->in_avail());
		cin >> num;
		switch(num)
		{
		case 1: file = true; flag = false; break;
		case 2: cons = true; flag = false; break;
		case 3: file = true; cons = true; flag = false; break;
		}
	}
	ofstream fout;
	if(file)
	{
		char *ofname;
		bool flag2 = true;
		cout << "��� ��������� �����" << endl;
		cout << "1) ������ �������\t2) ������������ �� ���������" << endl;
		while(flag2)
		{
			int num;
			cin.ignore(cin.rdbuf()->in_avail());
			cin >> num;
			switch(num)
			{
			case 1:
				{
					cout << "��� �����: ";
					string tstr;
					cin >> tstr;
					ofname = new char [tstr.size() + 1];
					strcpy(ofname, tstr.c_str());
					flag2 = false;
					break;
				}
			case 2:
				{
					ofname = new char [strlen("output.txt") + 1];
					strcpy(ofname, "output.txt");
					flag2 = false;
					break;
				}
			}
		}
		fout.open(ofname);
			if(!fout)
			{
				cout << "������ �������� ��������� �����" << endl;
				cout << "������ �� ����� �������� � ����" << endl;
				file = false;
			}
	}
	flag = true;
	while(flag)
	{
		cout << endl << "�������� ��������" << endl << endl;
		cout << "1) ������� ���������� �� ��������� ��������" << endl;
		cout << "2) ������� ������� �����������" << endl;
		cout << "3) ������� ������� �����" << endl;
		cout << "4) ��������� ������ ���������" << endl;
		bool flag2 = true;
		while(flag2)
		{
			int num;
			cin.ignore(cin.rdbuf()->in_avail());
			cin >> num;
			switch(num)
			{
			case 1:
				{
					cout << "��������:" << endl;
					list<Team>::iterator itt = teams.begin();
					for(int ix = 0; itt != teams.end(); itt++, ix++)
					{
						cout << ix+1 << ") " << itt->get_name() << endl;
					}
					bool flag3 = true;
					int sel;
					while(flag3)
					{
						cin.ignore(cin.rdbuf()->in_avail());
						cin >> sel;
						if(sel > 0 && sel <= teams.size())
							flag3 = false;
					}
					itt = teams.begin();
					for(int ix = 1; ix < sel; ix++)
						itt++;
					if(cons)
					{
						itt->print_stats(cout);
						cout << endl << endl;
					}
					if(file)
					{
						itt->print_stats(fout);
						fout << endl << endl;
					}
					flag2 = false;
					break;
				}
			case 2:
				{
					if(cons)
					{
						cout << "������� �����������" << endl << endl;
						for(int ix = 0; ix < ChampionshipTable.size(); ix++)
						{
							ChampionshipTable[ix]->print_results(cout);
							cout << endl;
						}
						cout << endl;
					}
					if(file)
					{
						fout << "������� �����������" << endl;
						for(int ix = 0; ix < ChampionshipTable.size(); ix++)
						{
							ChampionshipTable[ix]->print_results(fout);
							fout << endl;
						}
						fout << endl;
					}
					flag2 = false;
					break;
				}
			case 3:
				{
					if(cons)
					{
						list<Team>::iterator itt = teams.begin();
						cout << "������� �����" << endl;
						for(int ix = 0; ix < teams.size(); ix++, itt++)
						{
							cout << itt->get_name() << ' ';
							matrix.print_str(ix + 1, cout);
							cout << endl;
						}
						cout << endl;
					}
					if(file)
					{
						list<Team>::iterator itt = teams.begin();
						for(int ix = 0; ix < teams.size(); ix++, itt++)
						{
							fout << itt->get_name() << ' ';
							matrix.print_str(ix + 1, fout);
							fout << endl;
						}
					}
					flag2 = false;
					break;
				}
			case 4:
				flag2 = false;
				flag = false;
			}
		}
	}
	return 0;
}