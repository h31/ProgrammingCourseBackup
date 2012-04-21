/*#include "field.h"

Move::Move() {}

Move::Move(Field& f, Cell& p1, Cell& p2)
{
	gameField=f;
	cell_1=p1;
	cell_2=p2;

	if (cell_1.x>gameField.x || cell_2.x>gameField.x || cell_1.y>gameField.y || cell_2.y>gameField.y) throw Exception();
	gameField.cells[cell_1.x][cell_1.y]=0;
	gameField.cells[cell_2.x][cell_2.y]=0;

	gameField.print();
}

Move::~Move() {}*/