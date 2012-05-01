#include <iostream>
using namespace std;
#include"field.h"

void Field:: transformKing()//����������� ����� � �����
{ 
	for(int j=0;j<size;j++)
	{
	if(gameField[size-1][j]==whiteShashka)//���� ����� ����� ����������� �� ��������� �������
		gameField[size-1][j]=whiteKing;//����������� �� � ����� �����
	if(gameField[0][j]==blackShashka)//���� ������ ����� ����������� �� ������ �������
		gameField[0][j]=blackKing;//����������� �� � ������ �����
	}
}
bool Field::testEatenChecker(int Px,int Py, int x, int y)//��������:�������� �� ������ ����� ��� ����� "������" ����� ����������
{
	int i,j;
	if(gameField[x][y]==blackShashka || gameField[x][y]==whiteShashka)//���� �� �������� ������ ����� ��� ������ �����
	{
	i=x;j=y;
	if(gameField[x][y]==whiteShashka && ((Py-y==2 && (gameField[++i][++j]==blackShashka || gameField[++i][++j]==blackKing))//���� �� �������� ������ ����� �����
		||(y-Py==2 && (gameField[++i][--j]==blackShashka || gameField[++i][--j]==blackKing))))//� ����� ������������ ����� � ������������,�� ������� ����� �����������, ����� ������ ������
		return true;
	if(gameField[x][y]==blackShashka && ((Py-y==2 && (gameField[--i][++j]==whiteShashka || gameField[--i][++j]==whiteKing))//���� �� �������� ������ ������ �����
		|| (y-Py==2 && (gameField[--i][--j]==whiteShashka || gameField[--i][--j]==whiteKing))))//� ����� ������������ ����� � ������������,�� ������� ����� �����������, ����� ����� ������
		return true;
	}
	if(gameField[x][y]==blackKing || gameField[x][y]==whiteKing)//���� �� �������� ������ �����-���� �����
	{
		i=x;j=y;//���������� ������, ����� ������ �� � ������ �� ��� ������ ����������
		if(Px>x)
			i++;
		else
			i--;
		if(Py>y)
			j++;
		else
			j--;
		int k=0;//�������, �� ����� ������� ����� ���������� ����� ��������� ������������
		while(i!=Px && j!=Py)
		{
			if((gameField[x][y]==whiteKing && (gameField[i][j]==blackShashka || gameField[i][j]==blackKing ))//���� ��� ����������� ����� ������, � �� ������ ����� ���� ������ � ���, �� ������� ����������� ���, ����� ������ ������
				|| (gameField[x][y]==blackKing && (gameField[i][j]==whiteShashka || gameField[i][j]==whiteKing )))//���� ��� ����������� ������ ������, � �� ������ ����� ���� ������ � ���, �� ������� ����������� ���, ����� ����� ������
				k++;//����������� �������
			if(Px>x)//�������� ���� ��������� �����
				i++;
			else
				i--;
			if(Py>y)
				j++;
			else
				j--;
		}
		if(k==1)//���� ����� ����� ���� ���� ����������
			return true;
		}
		return false;
}
void Field::eatenChecker(int Px,int Py, int x, int y)//���������� ���� ��� �������� ����� �����
{
	int i,j;
	if(gameField[x][y]==blackShashka || gameField[x][y]==whiteShashka)
	{
	i=x;j=y;
	if(gameField[x][y]==whiteShashka && ((Py-y==2 && (gameField[++i][++j]==blackShashka || gameField[++i][++j]==blackKing))
		||(y-Py==2 && (gameField[++i][--j]==blackShashka || gameField[++i][--j]==blackKing))))//���� �� �������� ������ ����� �����,� �� ���,������� �� ����� "������",����� ������ �����
		{
			gameField[Px][Py]=gameField[x][y];
			gameField[i][j]=empty;
			gameField[x][y]=empty;//��������� �������� �������������� ����
		}
	if(gameField[x][y]==blackShashka && ((Py-y==2 && (gameField[--i][++j]==whiteShashka || gameField[--i][++j]==whiteKing)) ||
		(y-Py==2 && (gameField[--i][--j]==whiteShashka || gameField[--i][--j]==whiteKing))))//���� �� �������� ������ ������ �����,� �� ���,������� �� ����� "������",����� ����� �����
		{
			
			gameField[Px][Py]=gameField[x][y];
			gameField[i][j]=empty;
			gameField[x][y]=empty;//��������� �������� �������������� ����
		}
	}
	if(gameField[x][y]==blackKing || gameField[x][y]==whiteKing)//���� �� �������� ������ �����-���� �����
	{
		if(Px>x)
			i=x+1;
		else
			i=x-1;
		if(Py>y)
			j=y+1;
		else
			j=y-1;
		while(i!=Px && j!=Py)
		{
			if((gameField[x][y]==whiteKing && (gameField[i][j]==blackShashka || gameField[i][j]==blackKing ))
				|| (gameField[x][y]==blackKing && (gameField[i][j]==whiteShashka || gameField[i][j]==whiteKing )))
				gameField[i][j]=empty;
			if(Px>x)
			i++;
			else
				i--;
			if(Py>y)
			j++;
			else
			j--;
		} 
		gameField[Px][Py]=gameField[x][y];
		gameField[x][y]=empty;//��������� �������� �������������� ����
		}
}
bool Field:: secondCourse(int Px,int Py)//���������� ���������� ���� ��� �� ����� ����� ����, ��� ��� "�����" ����� ����������
 {
	 int i=Px;
	 int j=Py;
	 if(gameField[Px][Py]==whiteShashka)//���� ���������� ��� ��� �������� ����� ������
	 {
		 if((gameField[++i][++j]==blackShashka || gameField[i][j]==blackKing) && gameField[++i][++j]==empty)//���� �� �������� ������ ������ ������, � ��������� ����� ��� ������
			 return true;
			 i=Px;
			 j=Py;
		 if((gameField[++i][--j]==blackShashka || gameField[i][j]==blackKing) && gameField[++i][--j]==empty)
			return true;
		 else 
			 return false;
	 }
	 i=Px;
	 j=Py;
	 if(gameField[Px][Py]==blackShashka)//���� ���������� ��� ��� �������� ������ ������
	 {
		 if((gameField[--i][++j]==whiteShashka || gameField[i][j]==whiteKing) && gameField[--i][++j]==empty)//���� �� �������� ������ ����� ������, � ��������� ����� ��� ������
			 return true;
		 i=Px;
		 j=Py;
		 if((gameField[--i][--j]==whiteShashka || gameField[i][j]==whiteKing) && gameField[--i][--j]==empty)
			 return true;
		 else 
			 return false;
	 }
	 if(gameField[Px][Py]==whiteKing)//���� ���������� ��� ��� �������� ����� ������
	 {
		i=Px+1;//�������� ������������ �����������
		j=Py+1;
			while(gameField[i][j]==empty   && (i<7 && i>0 && j<7 && j>0))//"����" �� ���������� 
			{
				i++;
				j++;
			}
			if((gameField[i][j]==blackShashka || gameField[i][j]==blackKing ) && gameField[++i][++j]==empty)//���� �� ��������� ����� ������ ������ ������,� ��������� ����� ��� ������ ������
				return true;//������ ��� ��������
		i=Px+1;//�������� ������ ���������
		j=Py-1;
			while(gameField[i][j]==empty   && (i<7 && i>0 && j<7 && j>0))
			{
				i++;
				j--;
			}
			if((gameField[i][j]==blackShashka || gameField[i][j]==blackKing ) && gameField[++i][--j]==empty)
				return true;
		i=Px-1;
		j=Py-1;
			while(gameField[i][j]==empty   && (i<7 && i>0 && j<7 && j>0))
			{
				i--;
				j--;
			}
			if((gameField[i][j]==blackShashka || gameField[i][j]==blackKing ) && gameField[--i][--j]==empty)
				return true;
		i=Px-1;
		j=Py+1;
			while(gameField[i][j]==empty  && (i<7 && i>0 && j<7 && j>0))
			{
				i--;
				j++;
			}
			if((gameField[i][j]==blackShashka || gameField[i][j]==blackKing ) && gameField[--i][++j]==empty)
				return true;
			}
	 if(gameField[Px][Py]==blackKing)//���� ���������� ��� ��� �������� ������ ������
	 {
		 i=Px+1;
		 j=Py+1;
		 while(gameField[i][j]==empty  && (i<7 && i>0 && j<7 && j>0))//"����" �� ���������
		{
			i++;
			j++;
		}
		if((gameField[i][j]==whiteShashka || gameField[i][j]==whiteKing ) && gameField[++i][++j]==empty)//���� �� ��������� ����� ������ ������ ������,� ��������� ����� ��� ������ ������
			return true;//������ ��� ��������
		i=Px+1;//�������� ������ ���������
		j=Py-1;
		while(gameField[i][j]==empty  && (i<7 && i>0 && j<7 && j>0))
		{
			i++;
			j--;
		}
		if((gameField[i][j]==whiteShashka || gameField[i][j]==whiteKing ) && gameField[++i][--j]==empty)
			return true;
		i=Px-1;
		j=Py-1;
		while(gameField[i][j]==empty && (i<7 && i>0 && j<7 && j>0))
		{
			i--;
			j--;
		}
		if((gameField[i][j]==whiteShashka || gameField[i][j]==whiteKing ) && gameField[--i][--j]==empty)
			return true;
		i=Px-1;
		j=Py+1;
		while(gameField[i][j]==empty  && (i<7 && i>0 && j<7 && j>0) )
		{
			i--;
			j++;
		}
		if((gameField[i][j]==whiteShashka || gameField[i][j]==whiteKing ) && gameField[--i][++j]==empty)
			return true;
	 }
return false;
}
bool Field::permutation(int Px,int  Py,int  x, int y)//���������� �������� ����
{
	if((Px-x==1 && gameField[x][y]==whiteShashka) || (x-Px==1 && gameField[x][y]==blackShashka))//��� �� �������� ������ �����
	{
	gameField[Px][Py]=gameField[x][y];
	gameField[x][y]=empty;
	return true;
	}
	if((Px-x==1 || x-Px==1 )&& (gameField[x][y]==whiteKing || gameField[x][y]==blackKing))//��� �� �������� ������ �����
	{
	gameField[Px][Py]=gameField[x][y];
	gameField[x][y]=empty;
	return true;
	}
	if((Px-x==y-Py || x-Px==Py-y )&& (gameField[x][y]==whiteKing || gameField[x][y]==blackKing))//��� ����� �� �� �������� ������
	{
		int i;int j;
		if(Px>x) 
			i=x+1;
		else
			i=x-1;
		if(Py>y)
			j=y+1;
		else
			j=y-1;
		while(gameField[i][j]==empty  && i>0 && j>0 && i<8 && j<8 && i!=Px && j!=Py)//"����" �� ��������� � �������� ��� ������ �� �������
		{
			if(Px>x)
			i++;
			else
				i--;
			if(Py>y)
			j++;
			else
				j--;
		}
		if(i==Px && j==Py)//���� ��� ������ ������
		{
			gameField[Px][Py]=gameField[x][y];//��������� ������ �������������� ����
			gameField[x][y]=empty;
			return true;
		}
		else
			return false;
	}
	return false;
}
void Field::print()//����� ����
{
		for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
			cout<<gameField[i][j];
		cout<<endl;
	}
		cout<<endl;
}
Field::~Field()
 {	
	/*for(int i=0;i<size;i++)
		 delete[] gameField[i];
	 delete[] gameField;*/
}
Field::Field()
{
	/*Cell** gameField=new Cell* [size];
	for(int i=0;i<size;i++)
		gameField[i]=new Cell [size];*/

}
void Field::fieldMake()//���������� ����
{
	for(int i=0;i<size/2-1;i=i+2)
	{
		for (int j=0; j<size; j+=2)
			gameField[i][j]=empty;
		for (int j=1; j<size; j+=2)
			gameField[i][j]=whiteShashka;
	}
	for(int i=1;i<size/2-1;i+=2)
	{
		for (int j=1; j<size; j+=2)
			gameField[i][j]=empty;
		for (int j=0; j<size; j+=2)
			gameField[i][j]=whiteShashka;	
	}
	for(int i=size/2+1;i<size;i=i+2)
	{
		for (int j=0; j<size; j+=2)
			gameField[i][j]=blackShashka;
		for (int j=1; j<size; j+=2)
			gameField[i][j]=empty;
	}
	for(int i=size/2+2;i<size-1;i+=2)
	{ 
		for (int j=0; j<size; j+=2)
			gameField[i][j]=empty;
		for (int j=1; j<size; j+=2)
			gameField[i][j]=blackShashka;
	}
	for(int j=0;j<size;j++)
	{
		gameField[size/2][j]=empty;
		gameField[size/2-1][j]=empty;
	}

}
int Field::endOfGame()//�������� ��������� ����
{
	int k=0;
	int m=0;
	for(int i=0;i<size;i++)
	{
		for (int j=0; j<size; j++)
			{
				if(gameField[i][j]==whiteShashka || gameField[i][j]==whiteKing)
					k++;//������� ����� ����� �� ��������� �����
				if(gameField[i][j]==blackShashka || gameField[i][j]==blackKing)
					m++;//������� ������ ����� �� ��������� �����
		}
	}
	if(k==0)
		return 2;//��� ����� �����,�� ���� ������� �����,�������� �������
	if(m==0)
		return 1;//��� ������ �����,�� ���� ������� �����, �������� ������
	return 0;
}