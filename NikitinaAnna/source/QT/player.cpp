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
    if(Px>x) i++;//�������� ���� ��������� �����
    else  i--;
    if(Py>y)   j++;
    else   j--;
    if((field.gameField[x][y]==whiteShashka && (field.gameField[i][j]==blackShashka || field.gameField[i][j]==blackKing ))//���� ��� ����������� ����� ������, � �� ������ ����� ���� ������ � ���, �� ������� ����������� ���, ����� ������ ������
        || (field.gameField[x][y]==blackShashka && (field.gameField[i][j]==whiteShashka || field.gameField[i][j]==whiteKing )))//���� ��� ����������� ������ ������, � �� ������ ����� ���� ������ � ���, �� ������� ����������� ���, ����� ����� ������
    {
        opponentX=i;opponentY=j;
        return true;
    }
    else
        return false;
    }
    if(field.gameField[x][y]==blackKing || field.gameField[x][y]==whiteKing)//���� �� �������� ������ �����-���� �����
    {
        i=x;j=y;//���������� ������, ����� ������ �� � ������ �� ��� ������ ����������
        int k=0;//�������, �� ����� ������� ����� ���������� ����� ��������� ������������
         do
        {
            if(Px>x) i++;//�������� ���� ��������� �����
            else  i--;
            if(Py>y)   j++;
            else   j--;
            if((field.gameField[x][y]==whiteKing && (field.gameField[i][j]==blackShashka || field.gameField[i][j]==blackKing ))//���� ��� ����������� ����� ������, � �� ������ ����� ���� ������ � ���, �� ������� ����������� ���, ����� ������ ������
                || (field.gameField[x][y]==blackKing && (field.gameField[i][j]==whiteShashka || field.gameField[i][j]==whiteKing )))//���� ��� ����������� ������ ������, � �� ������ ����� ���� ������ � ���, �� ������� ����������� ���, ����� ����� ������
            {
                opponentX=i;
                opponentY=j;
                k++;//����������� �������
            }
        } while(i!=Px && j!=Py);
        if(k==1)//���� ����� ����� ���� ����� ����������
            return true;
        else
            return false;
    }
    return false;
}
void Player::eatenChecker(int Px,int Py, int x, int y,Field& field )//���������� ���� ��� �������� ����� �����
{
    field.gameField[opponentX][opponentY]=empty;
    field.gameField[Px][Py]=field.gameField[x][y];
    field.gameField[x][y]=empty;
}
bool Player::secondCourse(int Px,int Py,Field& field )//���������� ���������� ���� ��� �� ����� ����� ����, ��� ��� "�����" ����� ����������
 {
    int i; int j;
    const int di[4] = { 1, 1, -1, -1 };
    const int dj[4] = { 1, -1, 1, -1 };
          if(field.gameField[Px][Py]==whiteShashka || field.gameField[Px][Py]==blackShashka)
          {
           for (int dir=0; dir<4; dir++)
           {
               i=Px+di[dir];j=Py+dj[dir];
         if((((field.gameField[i][j]==blackShashka || field.gameField[i][j]==blackKing)  && field.gameField[Px][Py]==whiteShashka)
                 ||((field.gameField[i][j]==whiteShashka || field.gameField[i][j]==whiteKing)  && field.gameField[Px][Py]==blackShashka))
                 && field.gameField[i+di[dir]][j+dj[dir]]==empty && (i+di[dir]>=0 && i+di[dir]<8 && j+dj[dir]>=0 && j+dj[dir]<8))
                 return true;
          }
          }
         if(field.gameField[Px][Py]==whiteKing || field.gameField[Px][Py]==blackKing)
         {
             for (int dir=0; dir<4; dir++)
             {
             i=Px+di[dir];j=Py+dj[dir];//�������� ������������ �����������
                 while(field.gameField[i][j]==empty)//"����" �� ����������
                 {
                     i=i+di[dir];j=j+dj[dir];
                 }
                 if(((field.gameField[i][j]==blackShashka || field.gameField[i][j]==blackKing ) && field.gameField[i+di[dir]][j+dj[dir]]==empty && field.gameField[Px][Py]==whiteKing)//���� �� ��������� ����� ������ ������ ������,� ��������� ����� ��� ������ ������
                     ||(field.gameField[i][j]==whiteShashka || field.gameField[i][j]==whiteKing ) && field.gameField[i+di[dir]][j+dj[dir]]==empty && field.gameField[Px][Py]==blackKing)
                    {
                     if(i+di[dir]>=0 && i+di[dir]<8 && j+dj[dir]>=0 && j+dj[dir]<8)
                         return true;
                 }
             }
         }
return false;
}

bool Player::testPermutation(int Px,int Py, int x, int y,Field& field)
{
    if((Px-x==1 && field.gameField[x][y]==whiteShashka) || (x-Px==1 && field.gameField[x][y]==blackShashka))//��� �� �������� ������ �����
        return true;
    if((Px-x==y-Py || x-Px==y-Py )&& (field.gameField[x][y]==whiteKing || field.gameField[x][y]==blackKing))//��� ����� �� �� �������� ������
     {
         int i=x;int j=y;
         do
         {
         if(Px>x) i++;
         else i--;
         if(Py>y)  j++;
         else    j--;
         }
         while(field.gameField[i][j]==empty  && i!=Px && j!=Py);//"����" �� ��������� � ���������  ��� ������ �� �������
         if(i==Px && j==Py)//���� ��� ������ ������
             return true;
     }
    return false;
}

void Player::permutation(int Px,int  Py,int  x, int y,Field& field)//���������� �������� ����
{

    field.gameField[Px][Py]=field.gameField[x][y];
    field.gameField[x][y]=empty;     
}
bool Player::falseTurn(int x,int y,Field& field)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
    if(secondCourse(i,j,field)==true)
    {
       if(i==x && j==y)
        {
            field.gameField[x][y]=empty;
            return true;
        }
        if(((field.gameField[i][j]==whiteShashka || field.gameField[i][j]==whiteKing) &&
                (field.gameField[x][y]==whiteShashka || field.gameField[x][y]==whiteKing))
            || ((field.gameField[i][j]==blackShashka || field.gameField[i][j]==blackKing) &&
                (field.gameField[x][y]==blackShashka || field.gameField[x][y]==blackKing)))
   {
           field.gameField[i][j]=empty;
           return true;
        }
    }
    }
    }
    return false;
}
