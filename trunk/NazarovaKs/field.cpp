#include "field.h"
#include "check.h"

Field::Field(): field(5) {
	rows=5;
}

Field::Field(int a): field(a){
	rows=a;
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
		field[--a1].clearCell(b1);
		field[--a2].clearCell(b2);
	}
	else cout<<"Error!"<<endl;
}

void Field::addCells(){
	vector<Cell>f;
	f.resize(rows);

	int i_new = 0;
	int j_new = 0;
	cout << rows << endl;
	for (int i=0; i<rows; i++)
		for (int j=0; j<maxColumns; j++){
			if (field[i].getData(j) != 0)
			{
				if (j_new >= maxColumns)
				{
					i_new++;
					j_new = 0;
				}
				f[i_new].setData(j_new, field[i].getData(j) );	
				j_new++;
			}
	}
	cout<<endl;
	
	for (unsigned int i=0; i<f.size(); i++)
	{
		field.push_back(f[i]);		
	}
	rows=field.size();
	cout<<"Size: "<<rows<<endl;
}