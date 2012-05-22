
#include"player.h"
#include"field.h"

Player::Player()
{
}
Player::~Player()
{
}
bool Player::testEatenChecker(int Px,int Py, int x, int y,Field& field)//Проверка:возможно ли данной шашке или дамке "съесть" шашку противника
{
    int i,j;
    if(field.gameField[x][y]==blackShashka || field.gameField[x][y]==whiteShashka)//если на заданной ячейке белая или черная шашка
    {
    i=x;j=y;
    if(field.gameField[x][y]==whiteShashka && ((Py-y==2 && (field.gameField[++i][++j]==blackShashka || field.gameField[++i][++j]==blackKing))//если на заданной ячейке белая шашка
        ||(y-Py==2 && (field.gameField[++i][--j]==blackShashka || field.gameField[++i][--j]==blackKing))))//а между координатами шашки и координатами,на которые хотим переместить, стоит черная фигура
        return true;
    if(field.gameField[x][y]==blackShashka && ((Py-y==2 && (field.gameField[--i][++j]==whiteShashka || field.gameField[--i][++j]==whiteKing))//если на заданной ячейке черная шашка
        || (y-Py==2 && (field.gameField[--i][--j]==whiteShashka || field.gameField[--i][--j]==whiteKing))))//а между координатами шашки и координатами,на которые хотим переместить, стоит белая фигура
        return true;
    }
    if(field.gameField[x][y]==blackKing || field.gameField[x][y]==whiteKing)//если на заданной ячейке какая-либо дамка
    {
        i=x;j=y;//координаты ячейки, будем менять их и искать по ним фигуру противника
        int k=0;//счетчик, он будет считать шашки противника между заданными координатами
         do
        {
            if(Px>x) i++;//проверка всех остальных ячеек
            else  i--;
            if(Py>y)   j++;
            else   j--;
            if((field.gameField[x][y]==whiteKing && (field.gameField[i][j]==blackShashka || field.gameField[i][j]==blackKing ))//если ход совершается белой дамкой, и на ячейке между этой дамкой и той, на которую совершается ход, стоит черная фигура
                || (field.gameField[x][y]==blackKing && (field.gameField[i][j]==whiteShashka || field.gameField[i][j]==whiteKing )))//если ход совершается черной дамкой, и на ячейке между этой дамкой и той, на которую совершается ход, стоит белая фигура
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
void Player::eatenChecker(int Px,int Py, int x, int y,Field& field )//Реализация хода при съедении шашки врага
{
    int i,j;
    if(field.gameField[x][y]==blackShashka || field.gameField[x][y]==whiteShashka)
    {
    i=x;j=y;
    if((field.gameField[x][y]==whiteShashka && ((Py-y==2 && (field.gameField[++i][++j]==blackShashka || field.gameField[++i][++j]==blackKing))
        ||(y-Py==2 && (field.gameField[++i][--j]==blackShashka || field.gameField[++i][--j]==blackKing))))
        ||(field.gameField[x][y]==blackShashka && ((Py-y==2 && (field.gameField[--i][++j]==whiteShashka || field.gameField[--i][++j]==whiteKing)) ||
        (y-Py==2 && (field.gameField[--i][--j]==whiteShashka || field.gameField[--i][--j]==whiteKing)))))//если на заданной ячейки белая шашка,а на той,которой мы хотим "съесть",стоит черная шашка
        {
            field.gameField[Px][Py]=field.gameField[x][y];
            field.gameField[i][j]=empty;
            field.gameField[x][y]=empty;//Совершаем заданные преобразования поля
        }
    }
    if(field.gameField[x][y]==blackKing || field.gameField[x][y]==whiteKing)//если на заданной ячейке какая-либо дамка
    {
        field.gameField[opponentX][opponentY]=empty;
        field.gameField[Px][Py]=field.gameField[x][y];
        field.gameField[x][y]=empty;//совершаем заданные преобразования поля
    }
}
bool Player::secondCourse(int Px,int Py,Field& field )//Реализация следующего хода той же шашки после того, как она "съела" шашку противника
 {
     int i=Px; int j=Py;
     if(field.gameField[Px][Py]==whiteShashka//если предыдущий ход был совершен белой шашкой
         &&(((field.gameField[++i][++j]==blackShashka || field.gameField[i][j]==blackKing) && field.gameField[++i][++j]==empty)
         || ((field.gameField[--i][j=j-3]==blackShashka || field.gameField[i][j]==blackKing) && field.gameField[++i][--j]==empty)))
            return true;
     i=Px;  j=Py;
     if(field.gameField[Px][Py]==blackShashka//если предыдущий ход был совершен черной шашкой
         &&(((field.gameField[--i][++j]==whiteShashka || field.gameField[i][j]==whiteKing) && field.gameField[--i][++j]==empty)
         || ((field.gameField[++i][j=j-3]==whiteShashka || field.gameField[i][j]==whiteKing) && field.gameField[--i][--j]==empty)))
             return true;
     if(field.gameField[Px][Py]==whiteKing || field.gameField[Px][Py]==blackKing)
    while(i<size && i>0 && j<size && j>0)
     {
        i=Px+1;	j=Py+1;//проверка всевозможных направлений
            while(field.gameField[i][j]==empty)//"идем" по диагоналям
            {
                i++;j++;
            }
            if(((field.gameField[i][j]==blackShashka || field.gameField[i][j]==blackKing ) && field.gameField[++i][++j]==empty && field.gameField[Px][Py]==whiteKing)//если на диагонали будет стоять черная фигура,а следующая после нее ячейка пустая
                ||(field.gameField[--i][--j]==whiteShashka || field.gameField[i][j]==whiteKing ) && field.gameField[++i][++j]==empty && field.gameField[Px][Py]==blackKing)
                return true;//второй ход возможен
        i=Px+1;j=Py-1;//проверка другой диагонали
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
bool Player::permutation(int Px,int  Py,int  x, int y,Field& field)//Реализация обычного хода
{
    if((Px-x==1 && field.gameField[x][y]==whiteShashka) || (x-Px==1 && field.gameField[x][y]==blackShashka))//Ход на соседнюю ячейку шашки
    {
    field.gameField[Px][Py]=field.gameField[x][y];
    field.gameField[x][y]=empty;
    return true;
    }
   if((Px-x==y-Py || x-Px==y-Py )&& (field.gameField[x][y]==whiteKing || field.gameField[x][y]==blackKing))//Ход дамки не на соседнюю ячейку
    {
        int i=x;int j=y;
        do
        {
        if(Px>x) i++;
        else i--;
        if(Py>y)  j++;
        else    j--;
        }
        while(field.gameField[i][j]==empty  && i!=Px && j!=Py);//"Идем" по диагонали и проверяем  все ячейки на пустоту
        if(i==Px && j==Py)//если все ячейки пустые
        {
            field.gameField[Px][Py]=field.gameField[x][y];//совершаем нужные преобразования поля
            field.gameField[x][y]=empty;
            return true;
        }
    }
    return false;
}
