#ifndef _Fructs_h_
#define _Fructs_h_

#include "Fruct.h"

#include <vector>

class Fructs { //������, ��������� �� �������
private:
	//vector <Fruct> Fructs2;

	int Nfructs; //����� �������
public:
	Fruct** fruct;
	Fructs (int len);
	void add (int Size1,int Size2); 
	bool setNfructs (int new_N);
	int getNfructs ();
};

#endif
