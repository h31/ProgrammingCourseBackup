#include <iostream>
#include <stdlib.h>
using namespace std;

#include "Field.h"
#include "Fruct.h"
#include "Snake.h"

#include "Game.h"

void main() {
    system("title Snake");
    Game * G1=new Game (25,12,12,1,0,15);

    while(1)
    {
        G1->Upd();
    }
    system("pause");

}
