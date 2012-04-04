#include "Game.h"
#include "iostream"
using namespace std;
Game::Game ()
{
    Cycle=1;
    Time=0;
    Sc1=new Scenario1();
};

Game::~Game()
{
};
void Game::Upd()
{
    //system("cls");
    Sc1->Run(Cycle);
    cout<<Sc1->ScenZmeika->Headx<<"\t"<<Sc1->ScenZmeika->Heady<<endl;
    //cout<<Sc1->ScenZmeika->napx<<endl;
    //cout<<Sc1->ScenZmeika->Heady<<endl;
    //cout<<Sc1->ScenZmeika->napy<<endl<<endl;
    _sleep(2000);
    Time+=200;
    Cycle++;

}
