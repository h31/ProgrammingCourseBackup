#include"Square.h"

Square::Square()
{}

Square::~Square()
{}


int Square::getStat()
{
	return status;
}

istream& operator >>(istream& in, Square& sq)
{
	in >> sq.status;
	return in;
}

ostream& operator <<(ostream& out, const Square& sq)
{
	out << sq.status;
	return out;
}