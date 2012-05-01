#include "OpenFileTest.h"


OpenFileTest::OpenFileTest()
{
}


OpenFileTest::~OpenFileTest()
{
}

void OpenFileTest::openTest(Field &f)
{
	if(f.loadField("test12.txt"))
		cout << "Successfull opening" <<endl;
	else cout << "Opening failed" <<endl;
	if(!f.loadField("non-existent_file.txt"))
		cout << "Success, there is no file" <<endl;
	else cout << "?!" <<endl;
}