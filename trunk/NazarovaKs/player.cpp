#include "player.h"





// Ќе понимаю, почему происходит неверное распределение пам€ти, и почему не работает вывод на экран

Player::Cell::Cell() {
	for ( unsigned short i=0; i<maxColumns; i++)
		data[i]=NULL;
	prev=next=NULL;
}

Player::Cell::Cell( unsigned short key) {
	srand((unsigned short)time(NULL));
	for ( unsigned short i=0; i<maxColumns; i++)
		data[i]=1+rand()%9;
}

Player::Player() {
	rows=NULL;
	firstCell=NULL;
}

Player::Player(unsigned short amtRows) {
	rows=amtRows;
	Cell a(1);
	Cell* newCell, *endCell;
	firstCell=&a;
	//newCell=new Cell(1); //???
	endCell=firstCell;
	for ( unsigned short i=0; i<rows; i++) {
		newCell=&a; //???
		newCell->prev=firstCell;
		newCell->prev=endCell;
		endCell->next=newCell;
		endCell=newCell;
	}
}

ostream& operator << (ostream& out, const Player& player){
	Player c;
	c.firstCell=player.firstCell;
	while ( c.firstCell->next!=0 ) {
		out<<c.firstCell<<endl;
		c.firstCell=c.firstCell->next;
	}
	return out;
}