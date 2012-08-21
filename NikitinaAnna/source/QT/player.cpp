#include"player.h"
#include"field.h"

Player::Player()
{
}
Player::~Player()
{
}
bool Player::testEatenChecker(int Px,int Py, int x, int y,Field& field)//ѕроверка:возможно ли данной шашке или дамке "съесть" шашку противника
{
    int i,j;
    if(field.gameField[x][y]==blackShashka || field.gameField[x][y]==whiteShashka)//если на заданной €чейке бела€ или черна€ шашка
    {
    i=x;j=y;
    if(Px>x) i++;//проверка всех остальных €чеек
    else  i--;
    if(Py>y)   j++;
    else   j--;
    if((field.gameField[x][y]==whiteShashka && (field.gameField[i][j]==blackShashka || field.gameField[i][j]==blackKing ))//если ход совершаетс€ белой дамкой, и на €чейке между этой дамкой и той, на которую совершаетс€ ход, стоит черна€ фигура
        || (field.gameField[x][y]==blackShashka && (field.gameField[i][j]==whiteShashka || field.gameField[i][j]==whiteKing )))//если ход совершаетс€ черной дамкой, и на €чейке между этой дамкой и той, на которую совершаетс€ ход, стоит бела€ фигура
    {
        opponentX=i;opponentY=j;
        return true;
    }
    else
        return false;
    }
    if(field.gameField[x][y]==blackKing || field.gameField[x][y]==whiteKing)//если на заданной €чейке кака€-либо дамка
    {
        i=x;j=y;//координаты €чейки, будем мен€ть их и искать по ним фигуру противника
        int k=0;//счетчик, он будет считать шашки противника между заданными координатами
         do
        {
            if(Px>x) i++;//проверка всех остальных €чеек
            else  i--;
            if(Py>y)   j++;
            else   j--;
            if((field.gameField[x][y]==whiteKing && (field.gameField[i][j]==blackShashka || field.gameField[i][j]==blackKing ))//если ход совершаетс€ белой дамкой, и на €чейке между этой дамкой и той, на которую совершаетс€ ход, стоит черна€ фигура
                || (field.gameField[x][y]==blackKing && (field.gameField[i][j]==whiteShashka || field.gameField[i][j]==whiteKing )))//если ход совершаетс€ черной дамкой, и на €чейке между этой дамкой и той, на которую совершаетс€ ход, стоит бела€ фигура
            {
                opponentX=i;
                opponentY=j;
                k++;//увеличиваем счетчик
            }
        } while(i!=Px && j!=Py);
        if(k==1)//если стоит всего одна шашка противника
            return true;
        else
            return false;
    }
    return false;
}
void Player::eatenChecker(int Px,int Py, int x, int y,Field& field )//–еализаци€ хода при съедении шашки врага
{
    field.gameField[opponentX][opponentY]=empty;
    field.gameField[Px][Py]=field.gameField[x][y];
    field.gameField[x][y]=empty;
}
bool Player::secondCourse(int Px,int Py,Field& field )//–еализаци€ следующего хода той же шашки после того, как она "съела" шашку противника
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
             i=Px+di[dir];j=Py+dj[dir];//проверка всевозможных направлений
                 while(field.gameField[i][j]==empty)//"идем" по диагонал€м
                 {
                     i=i+di[dir];j=j+dj[dir];
                 }
                 if(((field.gameField[i][j]==blackShashka || field.gameField[i][j]==blackKing ) && field.gameField[i+di[dir]][j+dj[dir]]==empty && field.gameField[Px][Py]==whiteKing)//если на диагонали будет сто€ть черна€ фигура,а следующа€ после нее €чейка пуста€
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
    if((Px-x==1 && field.gameField[x][y]==whiteShashka) || (x-Px==1 && field.gameField[x][y]==blackShashka))//’од на соседнюю €чейку шашки
        return true;
    if((Px-x==y-Py || x-Px==y-Py )&& (field.gameField[x][y]==whiteKing || field.gameField[x][y]==blackKing))//’од дамки не на соседнюю €чейку
     {
         int i=x;int j=y;
         do
         {
         if(Px>x) i++;
         else i--;
         if(Py>y)  j++;
         else    j--;
         }
         while(field.gameField[i][j]==empty  && i!=Px && j!=Py);//"»дем" по диагонали и провер€ем  все €чейки на пустоту
         if(i==Px && j==Py)//если все €чейки пустые
             return true;
     }
    return false;
}

void Player::permutation(int Px,int  Py,int  x, int y,Field& field)//–еализаци€ обычного хода
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
