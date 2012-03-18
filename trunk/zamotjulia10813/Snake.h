#ifndef _Snake_h_
#define _Snake_h_

enum Zmlist { Snakehead=2, Snaketail=3 };

class ZmElement {
public:
	ZmElement (int X, int Y); 
	int getx();
	int gety();
	bool setx(int new_x);
	bool sety(int new_y);
private:
int x, y;
};

class Zmeika { //состоит из головы и хвоста
public:
	int Headx, Heady;
	int napx, napy;
	int dlintail;
	ZmElement*Tail;

	Zmeika(int X, int Y, int Napx, int Napy);
	int showHead();
	int showTail();
	};

#endif