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
	string subj; // �������
	string empl_type; // ��� ������� 

public :
	void getInfo(istream &in){ in >> spec >> dep >> stu_num >> empl_type >> subj;}
	void getInfo(string _spec, string _dep, int _stu_num);
	void printInfo() {cout << spec << " " << dep << " " << stu_num << " " << subj << " " << empl_type;}
	void printInfo(ostream &out) {out << spec << " " << dep << " " << stu_num << " " << subj << " " << empl_type;}

	string retSubj() { return subj;}
	string retEmpltype() { return empl_type;}
};