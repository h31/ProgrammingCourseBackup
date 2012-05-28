#ifndef ROW_H
#define ROW_H

#include <time.h>
#include <vector>

using namespace std;

const int maxColumns=7;
const int maxRows=49;

class Exception {};

class Row{
    vector<int> arr;
public:
    Row();
    int getData(int);
    void setData(int number, int value);
    void clearCell(int a);
};


#endif // ROW_H
