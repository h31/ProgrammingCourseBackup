#include <iostream>
#include <stdlib.h>
#include "test.h"

using namespace std;

int main(){
	srand((int)time(NULL));    
    //Test test;
    Field f(1);
    int x1, y1, x2, y2;
    cout<<f;
    cout<<"Input numbers: "<<endl;
    cin>>x1>>y1>>x2>>y2;
    f.deleteCell(x1, y1, x2, y2);
    f.addCells();
    cout<<f;
	return 0;
}
