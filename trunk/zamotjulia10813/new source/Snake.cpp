#include "Snake.h"

Zmeika::Zmeika(int X, int Y, int Napx, int Napy)
    {
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
    }

    };
Zmeika::Zmeika(){};

int Zmeika::enumHead() { return Snakehead;};
int Zmeika::enumTail() { return Snaketail;};

