
#include "Fruct.h"

Fruct:: Fruct (int X, int Y) {
        x=X; y=Y;};

Apple:: Apple (int X, int Y) : Fruct(X,Y) {};
int Apple:: show() { return App;};

Grusha:: Grusha (int t, int X, int Y): Fruct( X,Y) {
        time=t;
    }
int Grusha::show( ) {return Grr;};


Fructs:: Fructs (int len) {

        fruct = new Fruct*[len];

        // инициализация массива
        for (int i=0; i<len; i++)
        {
            fruct [i] = 0;
        }
    };

//добавить фрукты в массив
void Fructs:: add() {

        for(int i=0; i<N; i++)
        {
        int r=rand() %2+1;
        int x=rand() %25;
        int y=rand() %25;
        Apple*Ap= new Apple (x,y);
        Grusha*Gr= new Grusha (Grtime,x,y);
        switch (r) {
            case 1:
                    fruct[i]=Ap;
                    break;
            case 2:
                    fruct[i]=Gr;
                    break;
        }
        }
    };


