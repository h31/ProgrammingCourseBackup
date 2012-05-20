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
	if (!fin.is_open())
		return false;
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
		}
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
		}
	}
	ver = vertmp;
	return true;
}

bool Field::show()
{
	for(int j=0; j<height; j++)
		{
			for(int i=0; i<width; i++)
			{
				cout << map[i][j].getStat()<<" ";
			}
		cout<<endl;
		}
	return true;
}

bool Field::loadComplete(char* arg)
{
	ifstream fin(arg);
	if (!fin.is_open())
		return false;

	fin>>width>>height;
	int rows_k = height;
	int cols_k = width;
	int temp;


	Square **tmp = new Square*[width];
        for(int i=0;i<width;i++)
            tmp[i] = new Square [height];
        for(int j=0;j<height;j++)
            {
                for(int i=0;i<width;i++)
                {
				fin >> temp; 
				tmp[i][j].setStat(temp);
				tmp[i][j].s.x = i;
				tmp[i][j].s.y = j;
			}
		}
	map = tmp;
	return true;
}

void Field::setSqStat(int st,int x, int y)
{
	map[x][y].setStat(st);
}

int Field::getSqStat(int x,int y)
 {
     return map[x][y].getStat();
 }

void Field::createEmpty()
 {
    Square **tmp = new Square*[width];
    for(int i=0;i<width;i++)
        tmp[i] = new Square [height];
    for(int i=0; i<width; i++)
        {
            for(int j=0; j<height; j++)
            {
                tmp[i][j].setStat(2);
                tmp[i][j].s.x = i;
                tmp[i][j].s.y = j;
            }
        }
    map = tmp;
 }