#ifndef _field_h_
#define _field_h_

#include <iostream>
#include <time.h>

using namespace std;

const unsigned short maxColumns = 7; 
const unsigned short maxCells = 343; 

class List{
private:
	unsigned short rows;
	struct Cell{
		unsigned short arrCell [maxColumns];
		Cell *prev,*next;
		Cell();
		Cell(unsigned short);
		~Cell() {}		
		friend ostream& operator<<(ostream& out, const Cell& line) {
			for ( unsigned short i=0; i<maxColumns; i++ )
				out<<line.arrCell[i]<<" ";
			out<<endl;
			return out;
		}		
	};
public:
	List():rows(NULL) {}
	List(unsigned short);
	~List() {};
	friend ostream& operator << (ostream& out, const List&);
	Cell* makeCell();
	Cell* makeList(Cell*);
};

#endif