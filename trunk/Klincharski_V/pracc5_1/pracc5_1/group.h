#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class group
{
private :
	string spec; // Специальность
	string dep; // Отделение
	int stu_num; // Кол-во студентов
public :
	void getInfo(istream &in){ in >> spec >> dep >> stu_num;}
	void getInfo(string _spec, string _dep, int _stu_num);
	void printInfo() {cout << spec << " " << dep << " " << stu_num;}
	void printInfo(ostream &out) {out << spec << " " << dep << " " << stu_num;}
};