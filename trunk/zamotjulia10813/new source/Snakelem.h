#ifndef _Snakelem_h_
#define _Snakelem_h_

class ZmElement {
private:
int x, y;
public:
	ZmElement ();
	ZmElement (int X, int Y); 
	int getx();
	int gety();
	bool setx (int new_x);
	bool sety (int new_y);

};

#endif