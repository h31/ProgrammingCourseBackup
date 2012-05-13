#ifndef _Snake_h_
#define _Snake_h_

#include "Snakelem.h"
#include "Field.h"
#include "Fructs.h"
#include <vector>
enum zmlist { snakehead=2, snaketail=3 };
enum direction {dleft=0, dtop=1,dright=2,ddown=3,nodir=4};

class Zmeika {
private:
    int headx, heady;
    int napx, napy;
	bool Alive;
	int dir;
public:
    int score;
	
	
public:
	Zmeika();
    Zmeika(int X, int Y, int Napx, int Napy, int LTail);
	Zmeika(int X, int Y, int new_direction, int LTail);
	bool GetAlive();
	void SetAlive(bool newalive);
	~Zmeika();
	bool setdir(int newdir);
	int getdir();
    int get_headx();
    int get_heady();
    bool set_headx (int new_x);
    bool set_heady (int new_y);
    int get_napx();
    int get_napy();
    bool set_napx (int new_napx);
    bool set_napy (int new_napy);
	std::vector<ZmElement*>Tail2;
	ZmElement* GetElementTail2(int Number);
	//bool SetElementTail2(int Number,ZmElement *newTail);
    
    int enumerateHead ();
    int enumerateTail ();
	

    bool rotateUp();
    bool rotateDown();
    bool rotateLeft();
    bool rotateRight();
	bool rotateClockwise();
	bool rotateAClockwise();
    bool move();
	void shift();


	bool checkEatFruct(Fructs *AllFructs,Field *fullfield);
	bool checkWall(Field *fullfield);
	bool checkPosition(int X,int Y);
	bool checkSelfEating();
	bool AddTail(Field *fullfield);

    };
#endif

