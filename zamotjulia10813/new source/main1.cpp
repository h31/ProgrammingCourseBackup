#include <iostream>
#include <stdlib.h>
using namespace std;

#include "Field.h"
#include "Fruct.h"
#include "Snake.h"

#include "Game.h"


void main() {
    system("title Snake");
    Game * G1=new Game();

    while(1)
    {
        G1->update();
    }
    system("pause");

}
