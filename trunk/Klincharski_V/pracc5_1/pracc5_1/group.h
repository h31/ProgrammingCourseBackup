#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class group
{
private :
	string spec; // �������������
	string dep; // ���������
	int stu_num; // ���-�� ���������
public :
	void getInfo(istream &in){ in >> spec >> dep >> stu_num;}
	void getInfo(string _spec, string _dep, int _stu_num);
	void printInfo() {cout << spec << " " << dep << " " << stu_num;}
	void printInfo(ostream &out) {out << spec << " " << dep << " " << stu_num;}
};