#include "Test.h"

//��������� �� ������
bool Test::fructsCreator( Fructs*Fruits) {
if (Fruits==NULL) {cout<< "Fructs is not created";
    return false;
}
    //������� �� ���������
    int size=(int) (sizeof (Fruits->fruct)/sizeof(Fruct));
    if (size==15) {cout<< "True. There are 15 objects";
    return true;}
    else {cout<< "False. There isn't 15 objects";
    return false;}

 }

bool Test::zmeikaCreator( Zmeika*Zmeia) { ; // � ������ � ����� ���������
if (Zmeia==NULL) {cout<< " Zmeia is not created";
return false;
}
  //�������� �� 0 ��� ������
if (Zmeia->Tail==NULL)
{ cout<< "Tail is not created";
return false;
}

cout<<"2 Proverki vupolnenu";
return true;
}

bool Test:: FieldCreator (Field*p) {
    if (p==NULL) {cout<<"Field is not created ";
    return false;}

    if(p->w*p->h==0) {cout<<"Hight or width =0";
    return false;}

    //int size=(int) (sizeof (p->p)/sizeof(int));
    //if (size==p->w*p->h) {cout<< "True. Field is correct size";
    //return true;}

    else {cout<< "Field is not correct size";
    return false;}
};
