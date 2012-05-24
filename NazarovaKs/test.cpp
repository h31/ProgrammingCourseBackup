#include "test.h"

Test::Test()
{
    if (test_1())
        cout << "Test_1 passed."<<endl;
    else cout << "Test_1 didn't pass."<<endl;
    if (test_2())
        cout << "Test_2 passed."<<endl;
    else cout << "Test_2 didn't pass."<<endl;
    if (test_3())
        cout << "Test_3 passed."<<endl;
    else cout << "Test_3 didn't pass."<<endl;
}

bool Test::test_1(){
    Field f(3);
    cout<<f<<endl;
    f.field[0].setData(0, 1);
    f.field[0].setData(1, 1);
    cout<<f<<endl;
    return f.deleteCell(1, 1, 1, 2);
}

bool Test::test_2(){
    Field c(3);
    cout<<c<<endl;
    c.field[0].setData(0, 0);
    c.field[0].setData(1, 1);
    cout<<c<<endl;
    return c.deleteCell(1, 1, 1, 2);
}

bool Test::test_3(){
    Field f(3);
    cout<<f<<endl;
    f.field[2].setData(4, 1);
    f.field[1].setData(4, 0);
    f.field[0].setData(4, 1);
    cout<<f<<endl;
    return f.deleteCell(3, 5, 1, 5);
}



