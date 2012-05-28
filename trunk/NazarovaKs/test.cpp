#include "test.h"

Test::Test()
{
    if (nearSameNumber())
        cout << "Test #1 passed."<<endl;
    else cout << "Test #1 didn't pass."<<endl;
    cout<<endl;
    if (emptyOrFilledCell())
        cout << "Test #2 passed."<<endl;
    else cout << "Test #2 didn't pass."<<endl;
    cout<<endl;
    if (sameNumThroughEmptyCell())
        cout << "Test #3 passed."<<endl;
    else cout << "Test #3 didn't pass."<<endl;
    cout<<endl;
}

bool Test::nearSameNumber(){
    cout<<"Test #1. The choice of identical adjacent numbers."<<endl;
    Field f(3);
    cout<<f<<endl;
    f.field[0].setData(0, 1);
    f.field[0].setData(1, 1);
    cout<<f<<endl;
    return f.deleteCell(1, 1, 1, 2);
}

bool Test::emptyOrFilledCell(){
    cout<<"Test #2. The choice of empty and filled cell."<<endl;
    Field c(3);
    cout<<c<<endl;
    c.field[0].setData(0, 0);
    c.field[0].setData(1, 1);
    cout<<c<<endl;
    return c.deleteCell(1, 1, 1, 2);
}

bool Test::sameNumThroughEmptyCell(){
    cout<<"Test #3. The choice of identical numbers, among which is an empty cell."<<endl;
    Field f(3);
    cout<<f<<endl;
    f.field[2].setData(4, 1);
    f.field[1].setData(4, 0);
    f.field[0].setData(4, 1);
    cout<<f<<endl;
    return f.deleteCell(3, 5, 1, 5);
}
