#include "field.h"

Field::Field():Cell()
{
	fx=7;
	fy=8;

	cells=new Cell *[fy];
	for (int i=0; i<fy; i++)
		cells[i]=new Cell[fx];
}

Field::Field(int xsize, int ysize):Cell()
{
	fx=xsize;
	fy=ysize;

	cells=new Cell *[fy];
	for (int i=0; i<fy; i++)
		cells[i]=new Cell[fx];
}

Field::~Field() {}

void Field::createField()
{
	for (int i=0; i<fx; i++)
		for (int j=0; j<fy; j++)
			cells[i][j]=1 + rand() %9; // �����, ��� ����� �������� ��� ����������, �� �� ����, ��� ����� ��������� ��� ������. �������
									   // ��������� ��������� ������ �� �����, � ����� �����, �� ����� ��������� �������� � ���������� �����.
}

void Field::print(Field& f) 
{
	cout<<f;							// ���� � ��������� �������
}

ostream& operator << (ostream& out, const Field&f)
{
	for (int i=0; i<f.fx; i++)
	{
		for (int j=0; j<f.fy; j++)
			out<<f.cells[i][j];
		cout<<endl;
	}
	cout<<endl;
	return out;
}