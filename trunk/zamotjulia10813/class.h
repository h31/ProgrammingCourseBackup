#include <iostream>
#include <stdlib.h>
using namespace std;

int N=15; //число фруктов
int Grtime=20;

class Fruct {
public:
	int x, y;
	Fruct (int X, int Y) {
		x=X; y=Y;} 
	virtual char show()=0;
	
};

class Apple: public Fruct {
public:
	Apple (int X, int Y) : Fruct(X,Y) {};	
};
	char show() { return 'a';};
	

class Grusha: public Fruct {
public:
	int time;
	Grusha (int t, int X, int Y): Fruct( X,Y) {
		time=t;
	}
	char show( ) {return 'g';};
	
};

class Fructs {
public:
	Fruct** fruct;
	Fructs (int len) {
		
		fruct = new Fruct*[len];

		// инициализация массива
		for (int i=0; i<len; i++)
		{
			fruct [i] = 0;
		}
	}
	void add() { 
		
		for(int i=0; i<N; i++)
		{
		int r=rand() %2+1;
		int x=rand() %25;
		int y=rand() %25;
		Apple *Ap;
		Ap = new Apple (x,y);
		Grusha*Gr=new Grusha(Grtime,x,y);
		switch (r) {
			case 1: 
				    fruct[i]=Ap;
					break;
				
		    case 2: 

	     			fruct[i]=Gr;
					break;
		} 
	    }
	}

};

class Pole {
	int w,h;
public:
	Pole (int W, int H) {w=W; h=H;};
	void showpole () {
		char** p;
	    p= new char *[h]; //поле состоит из символов
		
		for (int i=0; i<h; i++)
		{
			p[i]= new char[w];
		}
		
		for (int i=0; i<h; i++)
			 for (int g=0; g<w; g++)
				 p[i][g]='_';
		
		for (int i=0; i<N; i++)
		{
			int x= Fruits->fruct[i]->x;
		    int y= Fruits->fruct[i]->y;
			p[x][y]= Fruits->fruct[i]->show();

		}
				for (int i=0; i<h; i++)
				{
					for (int g=0; g<w; g++)
					cout<<p[i][g];
					cout<<endl;
				}


	}
	

	
};

class ZmElement {
int x, y;
ZmElement (int X, int Y) {x=X; y=Y;}
};

class Zmeika {
public:
	int Headx, Heady;
	int napx, napy;
	int dlintail;
	ZmElement*Tail;

	Zmeika(int X, int Y, int Napx, int Napy)
	{
	Headx=X;
	Heady=Y;
	napx=Napx;
	napy=Napy;

	dlintail=2; //нач.длина, не считая головы

	Tail= (ZmElement*)malloc(sizeof(ZmElement)*2);

	for (int i=0; i<dlintail; i++)
	{
		ZmElement *Zmi=new ZmElement(Headx+1, Heady);
		Tail[i]=Zmi;
	}

	}
	};


	






