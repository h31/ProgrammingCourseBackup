#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "teacher.h"
#include "group.h"
#include <vector>

using namespace std;

class load
{
private :
	group gr;
	teacher tch;
	multimap <string,group> ld;
	map<string, int> pay;

public :
	int paycoef;
	void printLoad();
	void printPay();
	void AddLd(teacher tch1, group gr1, char *out);
	void AddLd(teacher tch1, group gr1);
	void findData(teacher tch1);
	void buildLd(ifstream &in);
	void buildPay(ifstream &in_tch);


	load(ifstream &in, ifstream &in_tch)
	{
		paycoef = 500;
		buildLd(in);
		in.seekg(0,ios::beg);
		buildPay(in_tch);
	}
	load() {}
};