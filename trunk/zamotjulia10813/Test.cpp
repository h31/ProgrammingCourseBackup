#include "Test.h"

//создалось ли вообще
bool Test:: fructsCreator( Fructs*Fruits) {
if (Fruits==NULL) {cout<< "Fructs is not created";
	return false;
}
    //столько ли создалось
	int size=(int) (sizeof (Fruits->fruct)/sizeof(Fruct));
	if (size==15) {cout<< "True. There are 15 objects";
	return true;}
	else {cout<< "False. There isnt 15 objects";
	return false;}

 }

bool Test:: zmeikaCreator( Zmeika*Zmeia) { ; // И голова и хвост указатель
if (Zmeia==NULL) {cout<< " Zmeia is not created";
return false;
}
  //проверка на 0 оба хвоста
if (Zmeia->Tail==NULL)
{ cout<< "Tail is not created";
return false;
}

cout<<"2 Proverki vupolnenu";
return true;
}

bool Test::  poleCreator(Pole*p) {
	if (p==NULL) {cout<<"Pole is not created ";
	return false;}

	if(p->w*p->h==0) {cout<<"Hight or width =0";
	return false;}

    int size=(int) (sizeof (p->p)/sizeof(int));
	if (size==p->w*p->h) {cout<< "True. Pole is correct size";
	return true;}

	else {cout<< "Pole is not correct size";
	return false;}
};

