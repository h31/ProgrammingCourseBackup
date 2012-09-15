#ifndef ROW_H
#define ROW_H

#include <time.h>
#include <vector>

using namespace std;

const int maxColumns=7;
const int maxRows=35;

class Exception {};

class Row{
    vector<int> arr;
    vector<bool> isPressed;
public:
    Row();
    int getData(int);
    void setData(int number, int value);
    void clearCell(int a);
    void setStateIsPressed(int, bool);
    bool getStateIsPressed(int);
};


#endif // ROW_H
