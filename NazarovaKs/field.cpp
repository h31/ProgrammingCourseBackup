#include "field.h"
#include "check.h"

Field::Field():Cell(){
	rows=5;
	vector<Cell>v(rows);
	field=v;
}

Field::Field(int a){
	rows=a;
	vector<Cell>v(rows);
	field=v;
}

Field::~Field() {}

ostream& operator << (ostream& out, const Field& f){
	for(unsigned int i=0; i<f.field.size(); i++)
		out<<f.field[i]<<endl;
	return out;
}

void Field::deleteCell(int a1, int b1, int a2, int b2){
	Field newField;
	newField.field=field;
	Check check(newField);

	if (check.checkMove(a1, b1, a2, b2)){
		cout<<"Right move."<<endl;
		field[--a1].arr[--b1]=NULL;
		field[--a2].arr[--b2]=NULL;
	}
	else cout<<"Error!"<<endl;
}

void Field::addCells(){
	for (int i=0; i<rows; i++){
		field.push_back(field[i]);		
	}
	rows=field.size();
	cout<<"Size: "<<rows<<endl;
}

