#ifndef _Fructs_h_
#define _Fructs_h_

#include "Fruct.h"

#include <vector>

class Fructs { //Фрукты, состоящие из фруктов
private:
	//vector <Fruct> Fructs2;

	int Nfructs; //число фруктов
public:
	Fruct** fruct;
	Fructs (int len);
	void add (int Size1,int Size2); 
	bool setNfructs (int new_N);
	int getNfructs ();
};

#endif
