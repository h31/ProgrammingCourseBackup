#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class teacher
{
private :
	string name, surname, patr; // Имя Фамилия Отчество
	string phone;
	int exp;
public :
	void getTeacherName(istream &in) { in >> name >> surname >> patr;}
	string retName() {return name;}
	string retSurname() {return surname;}
	string retPatr() {return patr;};
	void getTeacherInfo(istream &in) {getTeacherName(in); in >> phone >> exp;}
	void AddTch(char *out_tch)
	{
		ofstream out(out_tch, ios::app);
		out << endl << name << " " << surname << " " << patr << " " << phone << " " << exp;
	}
};