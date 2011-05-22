#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "teacher.h"
#include "group.h"
#include <vector>
#include "price.h"

using namespace std;

class load
{
private :
	multimap <string,group> ld;
	map<string, int> pay;

	int rescost(teacher &tch);

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