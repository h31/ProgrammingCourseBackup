#include"game.h"
#include"field.h"
#include"player.h"
#include"shashki.h"

Game::Game()
{
    View winner=blank;//������������� ���������-�����
    isWhiteTurn=true;//������ ��� ��������� �����, �������� ������
}
Game::~Game()
{
}
void Game::findWinner(Field& field)//�������� ���������� ���� � ����������� ����������
{
    if(field.endOfGame()==1)//�������� ���������� ����. ���� �� ���� ��� ������ �����
    {
        winner=white;
        emit end();
    }
    if(field.endOfGame()==2)//���� �� ���� ��� ������ �����
    {
        winner=black;
     emit end();
    }
    if(field.endOfGame()==0)//���� ���� � ������, � ����� �����
        winner=blank;
}
bool Game::result(int Px,int  Py,int  x, int y,int variable,Field& field,Checker& checker, King &king,Player &player)
{
  if(((isWhiteTurn==true && field.gameField[x][y]==whiteShashka) ||
        (isWhiteTurn==false && field.gameField[x][y]==blackShashka))//���� ������ ������ ������ �����, �������� ������(�������), � ����� ������� ��� �� �����(������)
      &&(field.gameField[Px][Py]==empty))
        {
             checker.setx(x);
             checker.sety(y);
   if ((field.gameField[x][y]==whiteShashka && checker.makeMove1(Px,Py)==true)
             || (field.gameField[x][y]==blackShashka && checker.makeMove2(Px,Py)==true))//���� �� ������ �����(������) ����� � �������� ��� �� �� �������� ������
{
         if( player.permutation(Px,Py,x,y,field)==true)
         {
             field.transformKing();
             isWhiteTurn=!isWhiteTurn;//�������� ���� ������� ������
              return true;
         }
         if(player.testEatenChecker(Px,Py,x,y,field)==true)//���� ����� ����� "������" ����� ����������
         {
       player.eatenChecker(Px,Py,x,y,field);
        field.transformKing();
         if(player.secondCourse(Px,Py,field)==true)//���� �������� ������ ���
             variable=1;//� �������� ������ ����������� ���������� �������� 1
         else
             isWhiteTurn=!isWhiteTurn;//�������� ���� ������� ������
           return true;
         }
        emit printFalseTurn();
   }
  emit printFalseTurn();
  }
   if(((isWhiteTurn==true && field.gameField[x][y]==whiteKing) ||
         (isWhiteTurn==false && field.gameField[x][y]==blackKing))//���� ������ ������ ������ �����, �������� ������(�������), � ����� ������� ��� �� �����(������)
       &&(field.gameField[Px][Py]==empty))
     {
              king.setx(x);
              king.sety(y);
    if ((field.gameField[x][y]==whiteKing && king.makeMove1(Px,Py)==true)
              || (field.gameField[x][y]==blackKing && king.makeMove2(Px,Py)==true))//���� �� ������ �����(������) ����� � �������� ��� �� �� �������� ������
 {
          if( player.permutation(Px,Py,x,y,field)==true)
          {
              isWhiteTurn=!isWhiteTurn;//�������� ���� ������� ������
               return true;
          }
          if(player.testEatenChecker(Px,Py,x,y,field)==true)//���� ����� ����� "������" ����� ����������
          {
        player.eatenChecker(Px,Py,x,y,field);
          if(player.secondCourse(Px,Py,field)==true)//���� �������� ������ ���
              variable=1;//� �������� ������ ����������� ���������� �������� 1
          else
              isWhiteTurn=!isWhiteTurn;//�������� ���� ������� ������
            return true;
          }
         emit printFalseTurn();
          }
  emit printFalseTurn();
   }
  return false;
}
