#ifndef FIELD_H
#define FIELD_H

#include "row.h"
#include <vector>

class Field{
    int rows;
    bool saveField;

    int firstB;
    int secondB;

    int canceled;
    int deleted;

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

    int setCanceled(int);
    bool getStatus();
    void lastCells(int, int, int, int);
};

#endif // FIELD_H
