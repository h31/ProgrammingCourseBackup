#ifndef FIELD_H
#define FIELD_H

#include "row.h"
#include <vector>

class Field{
    int rows;
    bool saveField;
public:
    Field();
    Field(int a);
    ~Field();

    vector<Row>field;
    bool deleteCell(int, int, int, int);
    void deleteEmptyRow();
    void addCells();
    void getState(bool);
    void saveGame();
    void loadGame();
    int getRows();
};

#endif // FIELD_H
