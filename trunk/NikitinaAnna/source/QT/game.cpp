#include"game.h"
#include"field.h"
#include"player.h"
#include"shashki.h"

Game::Game()
{
    View winner=blank;//Первоначально состояние-ничья
    isWhiteTurn=true;//Первый ход совершает игрок, играющий белыми
    setpoy(-1);setpox(-1);
}
Game::~Game()
{
}
void Game::findWinner(Field& field)//проверка завершения игры и определение победителя
{
    if(field.endOfGame()==1 )//проверка завершения игры. Если на поле нет черных шашек
    {
        winner=white;
        emit end();
    }
    if(field.endOfGame()==2)//если на поле нет черных шашек
    {
     winner=black;
    emit end();
    }
    if(field.endOfGame()==0)//если есть и черные, и белые шашки
        winner=blank;
}
bool Game::test(int  x, int y,Field& field)
{
    if(field.gameField[x][y]==empty)
    {
        emit empty1();
        return true;
    }
    if((isWhiteTurn==false && (field.gameField[x][y]==whiteShashka || field.gameField[x][y]==whiteKing)) ||
          (isWhiteTurn==true && (field.gameField[x][y]==blackShashka || field.gameField[x][y]==blackKing)))
    {
        emit strangeStroke1();
        return true;
    }
    return false;
}
bool Game::result(int Px,int  Py,int  x, int y,Field& field,Checker& checker, King &king,Player &player)
{
    setpoy(-1);setpox(-1);
  if(((isWhiteTurn==true && field.gameField[x][y]==whiteShashka) ||
        (isWhiteTurn==false && field.gameField[x][y]==blackShashka))//если сейчас должен ходить игрок, играющий белыми(черными), и шашка выбрана так же белая(черная)
      &&(field.gameField[Px][Py]==empty))
        {
             checker.setx(x);
             checker.sety(y);
   if ((field.gameField[x][y]==whiteShashka && checker.makeMove1(Px,Py)==true)
             || (field.gameField[x][y]==blackShashka && checker.makeMove2(Px,Py)==true))//если на ячейке белая(черная) шашка и возможен ход ее на заданную ячейку
{
         if( player.testPermutation(Px,Py,x,y,field)==true)
         {
             if(player.falseTurn(x,y,field)==true)
                 emit falseTurn();
             player.permutation(Px,Py,x,y,field);
              field.transformKing(Px,Py);
              isWhiteTurn=!isWhiteTurn;//передача хода другому игроку
              return true;
         }
         if(player.testEatenChecker(Px,Py,x,y,field)==true)//если шашка может "съесть" шашку противника
         {
       player.eatenChecker(Px,Py,x,y,field);
        field.transformKing(Px,Py);
         if(player.secondCourse(Px,Py,field)==true)//если возможен второй ход
         {
             setpox(Px);setpoy(Py);
         }
         else
             isWhiteTurn=!isWhiteTurn;//передача хода другому игроку
           return true;
         }
   }
  emit printFalseTurn();
  }
   if(((isWhiteTurn==true && field.gameField[x][y]==whiteKing) ||
         (isWhiteTurn==false && field.gameField[x][y]==blackKing))//если сейчас должен ходить игрок, играющий белыми(черными), и шашка выбрана так же белая(черная)
       &&(field.gameField[Px][Py]==empty))
     {
              king.setx(x);
              king.sety(y);
    if ((field.gameField[x][y]==whiteKing && king.makeMove1(Px,Py)==true)
              || (field.gameField[x][y]==blackKing && king.makeMove2(Px,Py)==true))//если на ячейке белая(черная) шашка и возможен ход ее на заданную ячейку
 {
        if( player.testPermutation(Px,Py,x,y,field)==true)
        {
            if(player.falseTurn(x,y,field)==true)
                emit falseTurn();
            player.permutation(Px,Py,x,y,field);
             isWhiteTurn=!isWhiteTurn;//передача хода другому игроку
             return true;
        }
          if(player.testEatenChecker(Px,Py,x,y,field)==true)//если шашка может "съесть" шашку противника
          {
        player.eatenChecker(Px,Py,x,y,field);
          if(player.secondCourse(Px,Py,field)==true)//если возможен второй ход
          {
               setpox(Px);setpoy(Py);
          }
          else
              isWhiteTurn=!isWhiteTurn;//передача хода другому игроку
            return true;
          }
          }
  emit printFalseTurn();
   }
  return false;
    }
int Game::getpox()
{
    return pox;
}
int Game::getpoy()
{
    return poy;
}
void Game::setpox(int x)
{
    pox=x;
}
void Game::setpoy(int y)
{
    poy=y;
}
