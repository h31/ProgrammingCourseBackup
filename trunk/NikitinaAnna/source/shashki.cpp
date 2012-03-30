#include"shashki.h"

Figure::Figure()
{
}
Figure::~Figure()
{
}
Checker::Checker()
{
}
Checker::~Checker()
{
}
King::King()
{
}
King::~King()
{
}
bool Figure::makeMove(int Px,int Py)
{
	return true;
}
bool Checker::makeMove(int Px,int Py)
{
	if(x-Px!=1 && Px-x!=1 )
		return false;
	if(y-Py!=1 && Py-y!=1 )
		return false;
	return true;
}

bool King::makeMove(int Px,int Py)
{
	if( Px-x==0 || Py-y==0 )
		return false;
	if(Px-x!=Py-y && x-Px!=Py-y)
		return false;
	else
		return true;
}