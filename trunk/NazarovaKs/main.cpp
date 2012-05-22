#include <iostream>

#include "field.h"

using namespace std;

int main(){
	srand((int)time(NULL));

	Field f(6);
	cout<<f;
	cout<<endl;

	int x1, y1, x2, y2;

	cout<<"Input numbers: ";
	cin>>x1>>y1>>x2>>y2;
	f.deleteCell(x1,y1,x2,y2);
	cout<<f;

	cout<<"Input numbers: ";
	cin>>x1>>y1>>x2>>y2;
	f.deleteCell(x1,y1,x2,y2);
	cout<<f;

	cout<<"Input numbers: ";
	cin>>x1>>y1>>x2>>y2;
	f.deleteCell(x1,y1,x2,y2);
	cout<<f;

	return 0;
}