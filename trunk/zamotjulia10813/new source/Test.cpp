#include "stdafx.h"
#include "Test.h"

//создалось ли вообще
bool Test::fructsCreator( Fructs*fruits) {
if (fruits==NULL) {cout<< "Fructs is not created";
    return false;
}
    //столько ли создалось
    int size=(int) (sizeof (fruits->Fruits.size())/sizeof(Fruct));
    if (size==15) {cout<< "True. There are 15 objects";
    return true;}
    else {cout<< "False. There isn't 15 objects";
    return false;}

 }

bool Test::zmeikaCreator( Zmeika*zmeia) { ; // И голова и хвост указатель
if (zmeia==NULL) {cout<< " Zmeia is not created";
return false;
}

cout<<"2 Proverki vupolnenu";
return true;
}

bool Test:: fieldCreator (Field*field) {
    if (field==NULL) {cout<<"Field is not created ";
    return false;}

    if(field->get_width()*field->get_height()==0) {cout<<"Hight or width =0";
    return false;}

    else {cout<< "Field is not correct size";
    return false;}
};
