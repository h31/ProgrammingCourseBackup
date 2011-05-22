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
	string subj; // Предмет
	string empl_type; // Тип занятия 

public :
	void getInfo(istream &in){ in >> spec >> dep >> stu_num >> empl_type >> subj;}
	void getInfo(string _spec, string _dep, int _stu_num);
	void printInfo() {cout << spec << " " << dep << " " << stu_num << " " << subj << " " << empl_type;}
	void printInfo(ostream &out) {out << spec << " " << dep << " " << stu_num << " " << subj << " " << empl_type;}

	string retSubj() { return subj;}
	string retEmpltype() { return empl_type;}
};