#include"field.h"

void Field:: transformKing(int Px,int Py)//превращение шашки в дамку
{
    if(Px==size-1 && gameField[Px][Py]==whiteShashka)
        gameField[Px][Py]=whiteKing;
    if(Px==0 && gameField[Px][Py]==blackShashka)
        gameField[Px][Py]=blackKing;
}
Field::~Field()
{
}
Field::Field()
{
for(int i=0;i<size/2-1;i=i+2)
    {
        for (int j=0; j<size; j+=2)
            gameField[i][j]=whiteShashka;
        for (int j=1; j<size; j+=2)
            gameField[i][j]=empty;
    }
    for(int i=1;i<size/2-1;i+=2)
    {
        for (int j=1; j<size; j+=2)
            gameField[i][j]=whiteShashka;
        for (int j=0; j<size; j+=2)
            gameField[i][j]=empty;
    }
    for(int i=size/2+1;i<size;i=i+2)
    {
        for (int j=0; j<size; j+=2)
            gameField[i][j]=empty;
        for (int j=1; j<size; j+=2)
            gameField[i][j]=blackShashka;
    }
    for(int i=size/2+2;i<size-1;i+=2)
    {
        for (int j=0; j<size; j+=2)
            gameField[i][j]=blackShashka;
        for (int j=1; j<size; j+=2)
            gameField[i][j]=empty;
    }
    for(int j=0;j<size;j++)
    {
        gameField[size/2][j]=empty;
        gameField[size/2-1][j]=empty;
    }
        sumWhite=0;sumBlack=0;
}
int Field::endOfGame()//Проверка окончания игры
{
    int k=0;int m=0;
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
    {
        for(int i=0;i<size;i++)
        {
            for (int j=0; j<size; j++)
            {
                if(gameField[i][j]==blackShashka)
                    sumBlack=sumBlack+5;
            if(gameField[i][j]==blackKing)
                sumBlack=sumBlack+10;
            }
        }
        return 2;//Нет белых шашек,то есть выиграл игрок,играющий черными
    }
    if(m==0)
    {
        for(int i=0;i<size;i++)
        {
            for (int j=0; j<size; j++)
            {
                if(gameField[i][j]==whiteShashka)
                    sumWhite=sumWhite+10;
            if(gameField[i][j]==whiteKing)
                sumWhite=sumWhite+20;
        }
    }
        return 1;//нет черных шашек,то есть выиграл игрок, играющий белыми
}
      return 0;
}
int Field::getSumWhite()
{
    return sumWhite;
}
int Field::getSumBlack()
{
    return sumBlack;
}
void Field::setSumWhite(int var)
{
    sumWhite=var;
}
void Field::setSumBlack(int var)
{
    sumBlack=var;
}

