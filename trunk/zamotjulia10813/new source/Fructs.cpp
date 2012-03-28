#include "Fructs.h"

Fructs::Fructs (int len) {
		Nfructs=len;

		fruct = new Fruct*[Nfructs];
	
		// инициализация массива
		for (int i=0; i<Nfructs; i++)
		{
			fruct [i] = 0;
		}
	};

//добавить фрукты в массив
void Fructs::add (int Size1,int Size2) { 
		
		for(int i=0; i<Nfructs; i++)
		{
		int r=rand() %2+1;
		int x=rand() %Size1;
		int y=rand() %Size2;
		Apple*Ap= new Apple (x,y);
		Grusha*Gr= new Grusha (Grtime,x,y);
		switch (r) {
			case 1: 
				    fruct[i]=Ap;
					break;
		    case 2: 
	     			fruct[i]=Gr;
					break;
		} 
	    }
	};

	bool Fructs::setNfructs (int new_N)
	{
		if(new_N<0)
		{
			return false;
		}
		else
		{
			Nfructs=new_N;
			return true;
		}
	};
	int Fructs::getNfructs()
	{
		return Nfructs;
	};