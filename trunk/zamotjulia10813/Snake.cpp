#ifndef _Snake_h_
#define _Snake_h_

ZmElement:: ZmElement (int X, int Y) {x=X; y=Y;}

Zmeika:: Zmeika(int X, int Y, int Napx, int Napy)
	{
	Headx=X;
	Heady=Y;
	napx=Napx;
	napy=Napy;

	dlintail=2; //нач.длина хвоста,пока статична

	//Tail= (ZmElement*)malloc(sizeof(ZmElement)*2);

	Tail= new ZmElement[2];

	for (int i=0; i<dlintail; i++)
	{
		ZmElement *Zmel=new ZmElement(Headx+i, Heady);
		Tail[i]=Zmel;
	}

	}

int Zmeika:: showHead() { return Snakehead};
int Zmeika:: showTail() { return Snaketail};

int Zmeika::getx() {return x;};
int Zmeika::gety() {return y;};

bool Zmeika:: setx (int new_x) {
	if (new_x<0) return false;  
};
bool Zmeika:: sety (int new_y) {
	if (new_y<0) return false;  
};

#endif