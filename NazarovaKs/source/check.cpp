#include "check.h"
#include "cstdlib"
Check::Check() {}

Check::Check(Field&field){
    f=field;
}

bool Check::checkMove(int a1, int b1, int a2, int b2){
    if ((checkSameValues(a1, b1, a2, b2) || checkSumValues(a1, b1, a2, b2)) && checkPlace(a1, b1, a2, b2) && nullValue(a1, b1, a2, b2)
          && (checkLoss()==false) && (checkSamePlace(a1, b1, a2, b2)) && (checkWin()==false))
        return true;
    else return false;
}

bool Check::getLoss(){
    return (checkLoss());
}

bool Check::getWin(){
    return (checkWin());
}

bool Check::checkSameValues(int a1, int b1, int a2, int b2){
    if (f.field[--a1].getData(--b1)==f.field[--a2].getData(--b2))
        return true;
    else return false;
}

bool Check::checkSumValues(int a1, int b1, int a2, int b2){
    if (f.field[--a1].getData(--b1)+f.field[--a2].getData(--b2)==10)
        return true;
    else return false;
}

bool Check::checkPlace(int a1, int b1, int a2, int b2){
    if (a1==a2 || b1==b2){
        if (a1==a2){
            for(int i=++b1; i<--b2; i++)
                if (f.field[--a1].getData(--i)!=0)
                    return false;
        }
        else return true;
        if (b1==b2){
            for(int i=++a1; i<--a2; i++)
                if (f.field[--i].getData(--b1)!=0)
                    return false;
        }
        else return true;
    }
    else return false;
}

bool Check::nullValue(int a1, int b1, int a2, int b2){
    if (f.field[--a1].getData(--b1)==0 || f.field[--a2].getData(--b2)==0)
        return false;
    else return true;
}

bool Check::checkSamePlace(int a1, int b1, int a2, int b2){
    if (a1==a2 && b1==b2) return false;
    else return true;
}

bool Check::checkLoss(){
    if(f.field.size()>=maxRows)
        return true;
    else return false;
}

bool Check::checkWin(){
    int amt=0;
    for (int i=0; i<f.field.size(); i++)
        for (int j=0; j<maxColumns; j++)
            if (f.field[i].getData(j)==0)amt++;
    if (f.field.size()*maxColumns==amt) return true;
    else return false;
}

