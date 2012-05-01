#include <iostream>
using namespace std;
#include"field.h"

void Field:: transformKing()//превращение шашки в дамку
{ 
	for(int j=0;j<size;j++)
	{
	if(gameField[size-1][j]==whiteShashka)//если белая шашка оказывается на последней строчке
		gameField[size-1][j]=whiteKing;//превращение ее в белую дамку
	if(gameField[0][j]==blackShashka)//если черная шашка оказывается на первой строчке
		gameField[0][j]=blackKing;//превращение ее в черную дамку
	}
}
bool Field::testEatenChecker(int Px,int Py, int x, int y)//Проверка:возможно ли данной шашке или дамке "съесть" шашку противника
{
	int i,j;
	if(gameField[x][y]==blackShashka || gameField[x][y]==whiteShashka)//если на заданной ячейке белая или черная шашка
	{
	i=x;j=y;
	if(gameField[x][y]==whiteShashka && ((Py-y==2 && (gameField[++i][++j]==blackShashka || gameField[++i][++j]==blackKing))//если на заданной ячейке белая шашка
		||(y-Py==2 && (gameField[++i][--j]==blackShashka || gameField[++i][--j]==blackKing))))//а между координатами шашки и координатами,на которые хотим переместить, стоит черная фигура
		return true;
	if(gameField[x][y]==blackShashka && ((Py-y==2 && (gameField[--i][++j]==whiteShashka || gameField[--i][++j]==whiteKing))//если на заданной ячейке черная шашка
		|| (y-Py==2 && (gameField[--i][--j]==whiteShashka || gameField[--i][--j]==whiteKing))))//а между координатами шашки и координатами,на которые хотим переместить, стоит белая фигура
		return true;
	}
	if(gameField[x][y]==blackKing || gameField[x][y]==whiteKing)//если на заданной ячейке какая-либо дамка
	{
		i=x;j=y;//координаты ячейки, будем менять их и искать по ним фигуру противника
		if(Px>x)
			i++;
		else
			i--;
		if(Py>y)
			j++;
		else
			j--;
		int k=0;//счетчик, он будет считать шашки противника между заданными координатами
		while(i!=Px && j!=Py)
		{
			if((gameField[x][y]==whiteKing && (gameField[i][j]==blackShashka || gameField[i][j]==blackKing ))//если ход совершается белой дамкой, и на ячейке между этой дамкой и той, на которую совершается ход, стоит черная фигура
				|| (gameField[x][y]==blackKing && (gameField[i][j]==whiteShashka || gameField[i][j]==whiteKing )))//если ход совершается черной дамкой, и на ячейке между этой дамкой и той, на которую совершается ход, стоит белая фигура
				k++;//увеличиваем счетчик
			if(Px>x)//проверка всех остальных ячеек
				i++;
			else
				i--;
			if(Py>y)
				j++;
			else
				j--;
		}
		if(k==1)//если стоит всего одна шака противника
			return true;
		}
		return false;
}
void Field::eatenChecker(int Px,int Py, int x, int y)//Реализация хода при съедении шашки врага
{
	int i,j;
	if(gameField[x][y]==blackShashka || gameField[x][y]==whiteShashka)
	{
	i=x;j=y;
	if(gameField[x][y]==whiteShashka && ((Py-y==2 && (gameField[++i][++j]==blackShashka || gameField[++i][++j]==blackKing))
		||(y-Py==2 && (gameField[++i][--j]==blackShashka || gameField[++i][--j]==blackKing))))//если на заданной ячейки белая шашка,а на той,которой мы хотим "съесть",стоит черная шашка
		{
			gameField[Px][Py]=gameField[x][y];
			gameField[i][j]=empty;
			gameField[x][y]=empty;//Совершаем заданные преобразования поля
		}
	if(gameField[x][y]==blackShashka && ((Py-y==2 && (gameField[--i][++j]==whiteShashka || gameField[--i][++j]==whiteKing)) ||
		(y-Py==2 && (gameField[--i][--j]==whiteShashka || gameField[--i][--j]==whiteKing))))//если на заданной ячейки черная шашка,а на той,которой мы хотим "съесть",стоит белая шашка
		{
			
			gameField[Px][Py]=gameField[x][y];
			gameField[i][j]=empty;
			gameField[x][y]=empty;//Совершаем заданные преобразования поля
		}
	}
	if(gameField[x][y]==blackKing || gameField[x][y]==whiteKing)//если на заданной ячейке какая-либо дамка
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
		gameField[x][y]=empty;//совершаем заданные преобразования поля
		}
}
bool Field:: secondCourse(int Px,int Py)//Реализация следующего хода той же шашки после того, как она "съела" шашку противника
 {
	 int i=Px;
	 int j=Py;
	 if(gameField[Px][Py]==whiteShashka)//если предыдущий ход был совершен белой шашкой
	 {
		 if((gameField[++i][++j]==blackShashka || gameField[i][j]==blackKing) && gameField[++i][++j]==empty)//если на соседней ячейке черная фигура, а следующая после нее пустая
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
	 if(gameField[Px][Py]==blackShashka)//если предыдущий ход был совершен черной шашкой
	 {
		 if((gameField[--i][++j]==whiteShashka || gameField[i][j]==whiteKing) && gameField[--i][++j]==empty)//если на соседней ячейке белая фигура, а следующая после нее пустая
			 return true;
		 i=Px;
		 j=Py;
		 if((gameField[--i][--j]==whiteShashka || gameField[i][j]==whiteKing) && gameField[--i][--j]==empty)
			 return true;
		 else 
			 return false;
	 }
	 if(gameField[Px][Py]==whiteKing)//если предыдущий ход был совершен белой дамкой
	 {
		i=Px+1;//проверка всевозможных направлений
		j=Py+1;
			while(gameField[i][j]==empty   && (i<7 && i>0 && j<7 && j>0))//"идем" по диагоналям 
			{
				i++;
				j++;
			}
			if((gameField[i][j]==blackShashka || gameField[i][j]==blackKing ) && gameField[++i][++j]==empty)//если на диагонали будет стоять черная фигура,а следующая после нее ячейка пустая
				return true;//второй ход возможен
		i=Px+1;//проверка другой диагонали
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
	 if(gameField[Px][Py]==blackKing)//если предыдущий ход был совершен черной дамкой
	 {
		 i=Px+1;
		 j=Py+1;
		 while(gameField[i][j]==empty  && (i<7 && i>0 && j<7 && j>0))//"идем" по диагонали
		{
			i++;
			j++;
		}
		if((gameField[i][j]==whiteShashka || gameField[i][j]==whiteKing ) && gameField[++i][++j]==empty)//если на диагонали будет стоять черная фигура,а следующая после нее ячейка пустая
			return true;//второй ход возможен
		i=Px+1;//проверка другой диагонали
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
bool Field::permutation(int Px,int  Py,int  x, int y)//Реализация обычного хода
{
	if((Px-x==1 && gameField[x][y]==whiteShashka) || (x-Px==1 && gameField[x][y]==blackShashka))//Ход на соседнюю ячейку шашки
	{
	gameField[Px][Py]=gameField[x][y];
	gameField[x][y]=empty;
	return true;
	}
	if((Px-x==1 || x-Px==1 )&& (gameField[x][y]==whiteKing || gameField[x][y]==blackKing))//Ход на соседнюю ячейку дамки
	{
	gameField[Px][Py]=gameField[x][y];
	gameField[x][y]=empty;
	return true;
	}
	if((Px-x==y-Py || x-Px==Py-y )&& (gameField[x][y]==whiteKing || gameField[x][y]==blackKing))//Ход дамки не на соседнюю ячейку
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
		while(gameField[i][j]==empty  && i>0 && j>0 && i<8 && j<8 && i!=Px && j!=Py)//"Идем" по диагонали и проверка все ячейки на пустоту
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
		if(i==Px && j==Py)//если все ячейки пустые
		{
			gameField[Px][Py]=gameField[x][y];//совершаем нужные преобразования поля
			gameField[x][y]=empty;
			return true;
		}
		else
			return false;
	}
	return false;
}
void Field::print()//Вывод поля
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
void Field::fieldMake()//заполнение поля
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
int Field::endOfGame()//Проверка окончания игры
{
	int k=0;
	int m=0;
	for(int i=0;i<size;i++)
	{
		for (int j=0; j<size; j++)
			{
				if(gameField[i][j]==whiteShashka || gameField[i][j]==whiteKing)
					k++;//счетчик белых фигур на шахматной доске
				if(gameField[i][j]==blackShashka || gameField[i][j]==blackKing)
					m++;//счетчик черных фигур на шахматной доске
		}
	}
	if(k==0)
		return 2;//Нет белых шашек,то есть выиграл игрок,играющий черными
	if(m==0)
		return 1;//нет черных шашек,то есть выиграл игрок, играющий белыми
	return 0;
}