#include "Field.h"

Pole::Pole (int W, int H, Fructs* Fruits, Zmeika*Zmeia)
{
    w=W; h=H;
    createPole();
    init (Fruits, Zmeia);
};

bool Pole::createPole()
{
    p= new int *[h]; //поле состоит из символов

        for (int i=0; i<h; i++)
        {
            p[i]= new int[w];
        }
        return true;
};

void Pole::init( Fructs *Fruits, Zmeika *Zmeia ) {

        //началный вывод, там где ничего нет - будут 8
        for (int i=0; i<h; i++)
             for (int g=0; g<w; g++)
                 p[i][g]=8;

        int x,y;
        for (int i=0; i<Fruits->getNfructs(); i++)
        {
            x= Fruits->fruct[i]->x;
            y= Fruits->fruct[i]->y;
            p[x][y]= Fruits->fruct[i]->enumfunc ();

        }
        //голова змеи
        x= Zmeia->Headx;
        y= Zmeia->Heady;
        p[x][y]= Zmeia->enumHead();

        //хвост
        for (int i=0; i<2; i++)
        {
            x=Zmeia->Tail[i].getx();
            y=Zmeia->Tail[i].gety();
            p[x][y]= Zmeia->enumTail();
        }

    };

void Pole::show() {
            // вывод массива поля
                for (int i=0; i<h; i++)
                {
                    for (int g=0; g<w; g++)
                    cout<<intToChar(p[i][g]);
                    cout<<endl;
                }
};

char Pole::intToChar (int Code)
{
    switch(Code)
    {
    case App:
        return 'a';
        break;
    case Grr:
        return 'g';
        break;
    case Snakehead:
        return '@';
        break;
    case Snaketail:
        return '#';
        break;
    case 8:
        return '_';
        break;
    default:
        return '_';
        break;
    }
}


