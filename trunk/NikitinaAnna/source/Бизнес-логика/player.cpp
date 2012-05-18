#include"player.h"
#include"field.h"

Player::Player()
{
}
Player::~Player()
{
}
bool Player::testEatenChecker(int Px,int Py, int x, int y,Field& field)//��������:�������� �� ������ ����� ��� ����� "������" ����� ����������
{
	int i,j;
	if(field.gameField[x][y]==blackShashka || field.gameField[x][y]==whiteShashka)//���� �� �������� ������ ����� ��� ������ �����
	{
	i=x;j=y;
	if(field.gameField[x][y]==whiteShashka && ((Py-y==2 && (field.gameField[++i][++j]==blackShashka || field.gameField[++i][++j]==blackKing))//���� �� �������� ������ ����� �����
		||(y-Py==2 && (field.gameField[++i][--j]==blackShashka || field.gameField[++i][--j]==blackKing))))//� ����� ������������ ����� � ������������,�� ������� ����� �����������, ����� ������ ������
		return true;
	if(field.gameField[x][y]==blackShashka && ((Py-y==2 && (field.gameField[--i][++j]==whiteShashka || field.gameField[--i][++j]==whiteKing))//���� �� �������� ������ ������ �����
		|| (y-Py==2 && (field.gameField[--i][--j]==whiteShashka || field.gameField[--i][--j]==whiteKing))))//� ����� ������������ ����� � ������������,�� ������� ����� �����������, ����� ����� ������
		return true;
	}
	if(field.gameField[x][y]==blackKing || field.gameField[x][y]==whiteKing)//���� �� �������� ������ �����-���� �����
	{
		i=x;j=y;//���������� ������, ����� ������ �� � ������ �� ��� ������ ����������
		int k=0;//�������, �� ����� ������� ����� ���������� ����� ��������� ������������
		while(i!=Px && j!=Py)
		{
			if((field.gameField[x][y]==whiteKing && (field.gameField[i][j]==blackShashka || field.gameField[i][j]==blackKing ))//���� ��� ����������� ����� ������, � �� ������ ����� ���� ������ � ���, �� ������� ����������� ���, ����� ������ ������
				|| (field.gameField[x][y]==blackKing && (field.gameField[i][j]==whiteShashka || field.gameField[i][j]==whiteKing )))//���� ��� ����������� ������ ������, � �� ������ ����� ���� ������ � ���, �� ������� ����������� ���, ����� ����� ������
			{
				opponentX=i;
				opponentY=j;
				k++;//����������� �������
			}
			if(Px>x) i++;//�������� ���� ��������� �����
			else  i--;
			if(Py>y)   j++;
			else   j--;
		}
		if(k==1)//���� ����� ����� ���� ����� ����������
			return true;
	}
	return false;
}
void Player::eatenChecker(int Px,int Py, int x, int y,Field& field )//���������� ���� ��� �������� ����� �����
{
	int i,j;
	if(field.gameField[x][y]==blackShashka || field.gameField[x][y]==whiteShashka)
	{
	i=x;j=y;
	if((field.gameField[x][y]==whiteShashka && ((Py-y==2 && (field.gameField[++i][++j]==blackShashka || field.gameField[++i][++j]==blackKing))
		||(y-Py==2 && (field.gameField[++i][--j]==blackShashka || field.gameField[++i][--j]==blackKing))))
		||(field.gameField[x][y]==blackShashka && ((Py-y==2 && (field.gameField[--i][++j]==whiteShashka || field.gameField[--i][++j]==whiteKing)) ||
		(y-Py==2 && (field.gameField[--i][--j]==whiteShashka || field.gameField[--i][--j]==whiteKing)))))//���� �� �������� ������ ����� �����,� �� ���,������� �� ����� "������",����� ������ �����
		{
			field.gameField[Px][Py]=field.gameField[x][y];
			field.gameField[i][j]=empty;
			field.gameField[x][y]=empty;//��������� �������� �������������� ����
		}
	}
	if(field.gameField[x][y]==blackKing || field.gameField[x][y]==whiteKing)//���� �� �������� ������ �����-���� �����
	{
		field.gameField[opponentX][opponentY]=empty;
		field.gameField[Px][Py]=field.gameField[x][y];
		field.gameField[x][y]=empty;//��������� �������� �������������� ����
	}
}
bool Player::secondCourse(int Px,int Py,Field& field )//���������� ���������� ���� ��� �� ����� ����� ����, ��� ��� "�����" ����� ����������
 {
	 int i=Px; int j=Py;
	 if(field.gameField[Px][Py]==whiteShashka//���� ���������� ��� ��� �������� ����� ������
		 &&(((field.gameField[++i][++j]==blackShashka || field.gameField[i][j]==blackKing) && field.gameField[++i][++j]==empty)
		 || ((field.gameField[i][j=j-2]==blackShashka || field.gameField[i][j]==blackKing) && field.gameField[++i][--j]==empty)))
			return true;
	else 
			 return false;
	 i=Px;  j=Py;
	 if(field.gameField[Px][Py]==blackShashka//���� ���������� ��� ��� �������� ������ ������
		 &&(((field.gameField[--i][++j]==whiteShashka || field.gameField[i][j]==whiteKing) && field.gameField[--i][++j]==empty)
		 || ((field.gameField[i][j=j-2]==whiteShashka || field.gameField[i][j]==whiteKing) && field.gameField[--i][--j]==empty)))
			 return true;
	 else 
			 return false;
	while(i<7 && i>0 && j<7 && j>0)
	 {
		i=Px+1;	j=Py+1;//�������� ������������ �����������
			while(field.gameField[i][j]==empty)//"����" �� ���������� 
			{
				i++;j++;
			}
			if(((field.gameField[i][j]==blackShashka || field.gameField[i][j]==blackKing ) && field.gameField[++i][++j]==empty && field.gameField[Px][Py]==whiteKing)//���� �� ��������� ����� ������ ������ ������,� ��������� ����� ��� ������ ������
				||(field.gameField[--i][--j]==whiteShashka || field.gameField[i][j]==whiteKing ) && field.gameField[++i][++j]==empty && field.gameField[Px][Py]==blackKing)
				return true;//������ ��� ��������
		i=Px+1;j=Py-1;//�������� ������ ���������
			while(field.gameField[i][j]==empty)
			{
				i++;j--;
			}
			if(((field.gameField[i][j]==blackShashka || field.gameField[i][j]==blackKing ) && field.gameField[++i][--j]==empty  && field.gameField[Px][Py]==whiteKing)
				||(field.gameField[--i][++j]==whiteShashka || field.gameField[i][j]==whiteKing ) && field.gameField[++i][--j]==empty && field.gameField[Px][Py]==blackKing)
				return true;
		i=Px-1;j=Py-1;
			while(field.gameField[i][j]==empty)
			{
				i--;j--;
			}
			if(((field.gameField[i][j]==blackShashka || field.gameField[i][j]==blackKing ) && field.gameField[--i][--j]==empty && field.gameField[Px][Py]==whiteKing)
				||(field.gameField[++i][++j]==whiteShashka || field.gameField[i][j]==whiteKing ) && field.gameField[--i][--j]==empty && field.gameField[Px][Py]==blackKing)
				return true;
		i=Px-1;j=Py+1;
			while(field.gameField[i][j]==empty)
			{
				i--;j++;
			}
			if(((field.gameField[i][j]==blackShashka || field.gameField[i][j]==blackKing ) && field.gameField[--i][++j]==empty && field.gameField[Px][Py]==whiteKing)
				||(field.gameField[++i][--j]==whiteShashka || field.gameField[i][j]==whiteKing ) && field.gameField[--i][++j]==empty && field.gameField[Px][Py]==blackKing)
				return true;
	}
return false;
}
bool Player::permutation(int Px,int  Py,int  x, int y,Field& field)//���������� �������� ����
{
	if((Px-x==1 && field.gameField[x][y]==whiteShashka) || (x-Px==1 && field.gameField[x][y]==blackShashka))//��� �� �������� ������ �����
	{
	field.gameField[Px][Py]=field.gameField[x][y];
	field.gameField[x][y]=empty;
	return true;
	}
	if((Px-x==1 || x-Px==1 )&& (field.gameField[x][y]==whiteKing || field.gameField[x][y]==blackKing))//��� �� �������� ������ �����
	{
	field.gameField[Px][Py]=field.gameField[x][y];
	field.gameField[x][y]=empty;
	return true;
	}
	if((Px-x==y-Py || x-Px==Py-y )&& (field.gameField[x][y]==whiteKing || field.gameField[x][y]==blackKing))//��� ����� �� �� �������� ������
	{
		int i=x;int j=y;
		do
		{
		if(Px>x) i++;
		else i--;
		if(Py>y)  j++;
		else    j--;
		}
		while(field.gameField[i][j]==empty  && i>0 && j>0 && i<8 && j<8 && i!=Px && j!=Py);//"����" �� ��������� � ���������  ��� ������ �� �������
		if(i==Px && j==Py)//���� ��� ������ ������
		{
			field.gameField[Px][Py]=field.gameField[x][y];//��������� ������ �������������� ����
			field.gameField[x][y]=empty;
			return true;
		}
		else
			return false;
	}
	return false;
}