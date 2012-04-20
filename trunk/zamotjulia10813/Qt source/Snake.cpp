#include "Snake.h"


Zmeika::Zmeika(int X, int Y, int Napx, int Napy)
    {
    headx=X;
    heady=Y;
    napx=Napx;
    napy=Napy;
    dlintail=2; //нач.длина хвоста,пока статична

    tail= new ZmElement[2];

    for (int i=0; i<dlintail; i++)
    {
        ZmElement *Zmel=new ZmElement(headx+i+1, heady);
        tail[i]=*Zmel;
        tail[i].set_napx(this->napx); //напр. элементов совпадает с головой
        tail[i].set_napy(this->napy);

    }
    }
Zmeika::Zmeika(int X, int Y, int Napx, int Napy,int LTail)
{
    headx=X;
    heady=Y;
    napx=Napx;
    napy=Napy;

    for(int i=0;i<LTail;i++)
    {
        ZmElement*ZmTeiltemp=new ZmElement(headx+i+1, heady);
        Tail2.push_back(ZmTeiltemp);
    }
}
Zmeika::Zmeika () { }

Zmeika::~Zmeika() {

        delete [] tail;
}
int Zmeika::get_headx() {return headx;}
int Zmeika::get_heady() {return heady;}
bool Zmeika::set_headx (int new_headx) {
        headx=new_headx;
        return true;
    }
bool Zmeika::set_heady (int new_heady) {
        heady=new_heady;
        return true;
    }

int Zmeika::get_napx() {return napx;}
int Zmeika::get_napy() {return napy;}
bool Zmeika::set_napx (int new_napx) {
        napx=new_napx;
        return true;
    }
bool Zmeika::set_napy (int new_napy) {
        napy=new_napy;
        return true;
    }


int Zmeika::enumerateHead() { return snakehead;}
int Zmeika::enumerateTail() { return snaketail;}

bool Zmeika::move()
{
    //if (napx=-1)
    //	if (Headx<=0)
    //    return false;
    //if (napy=-1)
    //	if (Heady<=0)
     //   return false;

    headx+=napx;
    heady+=napy;

    for (int i=0; i<Tail2.size(); i++)
    {
          Tail2[i]->setx(Tail2[i]->getx()+Tail2[i]->getnapx());
          Tail2[i]->sety(Tail2[i]->gety()+Tail2[i]->getnapy());
    }

    shift();
    return true;

}
//изм направление элементов хв
void Zmeika::shift() {
    Tail2[0]->set_napx(this->napx); //присвоим направление для 1 по голове
    Tail2[0]->set_napy(this->napy);

    for (int i=1; i<Tail2.size(); i++) {
        Tail2[i]->set_napx(Tail2[i-1]->getnapx());
        Tail2[i]->set_napy(Tail2[i-1]->getnapy());
    }
}

bool Zmeika:: rotateRight() {
 napx=1; //для головы
 napy=0;
 return true;
}

bool Zmeika:: rotateLeft() {
 napx=-1;
 napy=0;
 return true;
}

bool Zmeika:: rotateUp() {
 napx=0;
 napy=-1;
 return true;
}

bool Zmeika:: rotateDown() {
 napx=0;
 napy=1;
 return true;
}

bool Zmeika:: check1() {
 if (headx==2 && heady==0)
     return true;
 else return false;

}

bool Zmeika:: check2() {
 if (headx<0 || heady<0)
     return true;
 else return false;

}

bool Zmeika:: check3() {
    for (int i=0; i<this->Tail2.size(); i++)
    if (headx==Tail2[i]->getx() && heady==Tail2[i]->getx())
     return true;
 else return false;

}



