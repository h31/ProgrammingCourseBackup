#include"Field.h"
#include<fstream>
#include<iostream>

using namespace std;

Field::Field()
{}

Field::~Field()
{}

bool Field::loadField(char* arg)
{
		ifstream fin(arg);
		int hor_row,hor_col,ver_row,ver_col;
		fin>>hor_row>>ver_row>>hor_col>>ver_col;
		height = ver_row;
		width = hor_row;
		int **hortmp = new int*[hor_row];
		for(int i=0;i<hor_row;i++)
			hortmp[i] = new int [hor_col];
		for(int i=0; i<hor_row; i++)
		{
			for(int j=0; j<hor_col; j++)
			{
                fin>>hortmp[i][j];
                //cout<<hortmp[i][j]<<" ";
			}
		//cout<<endl;
		}
		hor = hortmp;
		int **vertmp = new int*[ver_row];
		for(int i=0;i<ver_row;i++)
			vertmp[i] = new int [ver_col];
		for(int i=0; i<ver_row; i++)
		{
			for(int j=0; j<ver_col; j++)
			{
                fin>>vertmp[i][j];
                //cout<<vertmp[i][j]<<" ";
			}
		//cout<<endl;
		}
		ver = vertmp;
		return true;
	}

bool Field::show()
{
	for(int i=0; i<height; i++)
		{
			for(int j=0; j<width; j++)
			{
				cout << map[i][j].status<<" ";
			}
		cout<<endl;
		}
	return true;
}

bool Field::loadComplete(char* arg)
{
	ifstream fin(arg);
	int pr, kol = 0;
	while(!fin.eof())
	{
       fin >> pr;
       kol++;
	}

	char buf[256];
	int rows_k = 0;

	fin.close();
	fin.clear();
	fin.open(arg);

	while(!fin.eof())
	{
       fin.getline(buf, 255);
       rows_k++;
	}
	fin.close();
	fin.clear();
	fin.open(arg);

	int cols_k = kol/rows_k;

	height = rows_k;
	width = cols_k;

	Square **tmp = new Square*[rows_k];
	for(int i=0;i<rows_k;i++)
		tmp[i] = new Square [cols_k];
	for(int i=0; i<rows_k; i++)
		{
			for(int j=0; j<cols_k; j++)
			{
				fin >> tmp[i][j].status;
				tmp[i][j].s.x = i;
				tmp[i][j].s.y = j;
			}
		//cout<<endl;
		}
	map = tmp;
	//cout<<rows_k<<" "<<cols_k<<endl;
	return true;
}
