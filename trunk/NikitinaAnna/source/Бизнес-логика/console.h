#ifndef _console_h_
#define _console_h_
class Console
{
int conx;int cony;
int conPx;int conPy;
public:
void print(Field& field);//Вывод поля
void dialog( int Px, int Py, int variable,Field& field, Player& player, Game& game);
void check(Field& field,Checker& checker,King& king,int Px, int Py, int x, int y);
void printResult(Game& game);
int getConx();
int getCony();
int getConPx();
int getConPy();
};

#endif