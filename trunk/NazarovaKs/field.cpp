#include "field.h"
#include "check.h"
#include "mainwindow.h"
#include "QtGui"
#include <stdlib.h>
#include <fstream>

Field::Field(): field() {
    saveField=false;
    rows=5;
    srand((int)time(NULL));
    for (int i=0; i<rows; i++)
        field.push_back(Row());
}

Field::Field(int a): field(){
    saveField=false;
    rows=a;
    srand((int)time(NULL));
    for (int i=0; i<rows; i++)
        field.push_back(Row());    
}

Field::~Field() {}

bool Field::deleteCell(int a1, int b1, int a2, int b2){
    Field newField;
    newField.field=field;
    Check check(newField);

    if (check.checkMove(a1, b1, a2, b2)){
        field[--a1].clearCell(b1);
        field[--a2].clearCell(b2);
        return true;
    }
    else return false;
}

void Field::addCells(){
    vector<Row>f;
    f.resize(rows);
    int i_new = 0;
    int j_new = 0;
    for (int i=0; i<field.size(); i++)
        for (int j=0; j<maxColumns; j++){
            if (field[i].getData(j)!=0){
                if (j_new >= maxColumns){
                    i_new++;
                    j_new = 0;
                }
                f[i_new].setData(j_new, field[i].getData(j) );
                ++j_new;
            }
    }

    j_new++;
    for (j_new; j_new<=maxColumns; j_new++){
            f[i_new].clearCell(j_new++);
            j_new--;
    }

    for (unsigned int i=0; i<=i_new; i++)
        field.push_back(f[i]);
    rows=field.size();
}

void Field::getState(bool state){
    saveField=state;
}

void Field::saveGame(){
    ofstream out("Save.txt");
    for (int i=0; i<field.size(); i++){
        for (int j=0; j<maxColumns; j++)
            out<<field[i].getData(j)<<" ";
        out<<endl;
    }
    out.close();
}

void Field::loadGame(){
    vector<Row>f;
    int amt=0;
    int* arr=new int[maxRows*maxColumns];
    ifstream in("Save.txt");
    for (int i=0; !in.eof(); i++){
        in>>arr[i];
        amt++;
    }
    f.resize((amt+1)/maxColumns);
    int k=0;
    for (int i=0; i<f.size(); i++)
        for (int j=0; j<maxColumns; j++)
            if(k<amt){
                f[i].setData(j, arr[k]);
                k++;
            }
    field=f;
    in.close();
}

int Field::getRows(){
    return rows;
}

void Field::deleteEmptyRow(){
    for (vector<Row>::iterator it=field.begin(); it!=field.end(); it++){
        bool isEmpty = true;
        for (int i=0; i<maxColumns; i++)
            if (it->getData(i) != 0){
                isEmpty = false;
                break;
            }
        if (isEmpty)
            field.erase(it);
    }
}
