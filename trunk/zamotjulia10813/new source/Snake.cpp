#include "Snake.h"


Zmeika::Zmeika(int X, int Y, int Napx, int Napy)
    {
    //Game1=Game2;
    Headx=X;
    Heady=Y;
    napx=Napx;
    napy=Napy;
    dlintail=2; //нач.длина хвоста,пока статична

    Tail= new ZmElement[2];

    for (int i=0; i<dlintail; i++)
    {
        ZmElement *Zmel=new ZmElement(Headx+i+1, Heady);
        Tail[i]=*Zmel;
        Tail[i].napx=this->napx; //напр. элементов совпадает с головой
        Tail[i].napy=this->napy;
    }

    };
Zmeika::Zmeika(int X, int Y, int Napx, int Napy,int LTail)
{
    Headx=X;
    Heady=Y;
    napx=Napx;
    napy=Napy;
    //Tail2.resize(LTail);
    for(int i=0;i<LTail;i++)
    {
        ZmElement*ZmTeiltemp=new ZmElement(Headx+i+1, Heady);
        Tail2.push_back(ZmTeiltemp);
    }
}
Zmeika::Zmeika(){};

Zmeika::~Zmeika() {

        delete [] Tail;
};

int Zmeika::enumHead() { return Snakehead;};
int Zmeika::enumTail() { return Snaketail;};

bool Zmeika::Move()
{
    //if (napx=-1)
    //	if (Headx<=0)
    //    return false;
    //if (napy=-1)
    //	if (Heady<=0)
     //   return false;

    Headx+=napx;
    Heady+=napy;

    for (int i=0; i<Tail2.size(); i++)
    {
          Tail2[i]->setx(Tail2[i]->getx()+Tail2[i]->napx);
          Tail2[i]->sety(Tail2[i]->gety()+Tail2[i]->napy);
    }

    Shift();
    return true;

}
//изм направление элементов хв
void Zmeika::Shift() {
    Tail2[0]->napx=this->napx; //присвоим направление для 1 по голове
    Tail2[0]->napy=this->napy;

    for (int i=1; i<Tail2.size(); i++) {
        Tail2[i]->napx=Tail2[i-1]->napx;
        Tail2[i]->napy=Tail2[i-1]->napy;
    }
}

bool Zmeika:: RotateRight() {
 napx=1; //для головы
 napy=0;
 return true;
}

bool Zmeika:: RotateLeft() {
 napx=-1;
 napy=0;
 return true;
}

bool Zmeika:: RotateUp() {
 napx=0;
 napy=-1;
 return true;
}

bool Zmeika:: RotateDown() {
 napx=0;
 napy=1;
 return true;
}

bool Zmeika:: Check() {
 if (Headx==2 && Heady==0)
     return true;
 else return false;

}



