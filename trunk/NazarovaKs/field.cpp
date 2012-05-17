#include "field.h"
List::Cell::Cell(): prev(NULL),next(NULL){
	for (unsigned short i=0; i<maxColumns; i++)
		arrCell[i] = NULL;
}

List::Cell::Cell(unsigned short key):prev(NULL),next(NULL) {
	for ( unsigned short i=0; i<maxColumns; i++)
		arrCell[i]=1+rand()%9;
}

List::List(unsigned short amtRows):rows(amtRows) {}

ostream& operator << (ostream& out, const List& list){
	List newList=list;
	List::Cell *cell=newList.makeCell();
	srand((unsigned short)time(NULL));
	for(unsigned short i=0; i<newList.rows; i++){
		cell=newList.makeList(cell);
		out<<*cell<<endl;
	}
	return out;
}

List::Cell* List::makeCell(){
	Cell* cell=new (Cell);
	cell->next=0; cell->prev=0;
	return cell;
}

List::Cell* List::makeList(Cell* start){
	Cell line(1);
	Cell *cell=makeCell();
	cell->next=start;
	start->prev=cell;
	start=cell;
	*cell=line;
	return start;
}