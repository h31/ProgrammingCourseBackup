#include "row.h"
#include <stdlib.h>

Row::Row(){
    arr.resize(maxColumns);
    isPressed.resize(maxColumns);
    for(int i=0; i<maxColumns; i++)
    {
        arr[i]=1+rand()%9;
        isPressed[i] = false;
    }
}

int Row::getData(int a){
    if (a<=maxColumns)
        return arr[a];
    else throw Exception();
}

void Row::clearCell(int a){
    if (a<=maxColumns)
        arr[--a]=0;
    else throw Exception();
}

void Row::setStateIsPressed(int i, bool j){
    isPressed[i]=j;
}

bool Row::getStateIsPressed(int i){
    return isPressed[i];
}

void Row::setData(int number, int value){
    if (number<=maxColumns)
        arr[number] = value;
    else throw Exception();
}
