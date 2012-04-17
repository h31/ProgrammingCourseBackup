#include "Game.h"
#include "iostream"
using namespace std;
Game::Game ()
{
    cycle_snake=1;
    time_pear=0;
    scenario1=new Scenario1();
    scenario2=new Scenario2();
    scenario3=new Scenario3();

}

Game::~Game()
{
}
void Game::update()
{
    system("cls");
    scenario1->run(cycle_snake);
    updateField(scenario3);
    printField(scenario3);
    _sleep(2000);
    time_pear+=200;
    cycle_snake++;

}
int Game::gettime_pear() {
    return time_pear;
}
bool Game::settime_pear (int newtime_pear) {
    if (newtime_pear<0) return false;
    else
    {
        time_pear=newtime_pear;
        return true;
    }

}
int Game::getcycle_snake () {
    return cycle_snake;
}
bool Game::setcycle_snake(int newcycle_snake) {
    cycle_snake=newcycle_snake;
    return true;
}
void Game::printField(Scenario*currentscenario)
{
    int H=currentscenario->scenarioField->get_height();
    int W=currentscenario->scenarioField->get_width();
    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
        {
            cout<<intToChar(currentscenario->scenarioField->get_field(i,j))<<" ";
        }
        cout<<"\n";
    }


}
void Game::updateField(Scenario*currentscenario)
{
    currentscenario->scenarioField->init();
    int X=0,Y=0;
    X=currentscenario->scenarioZmeika->get_headx();
    Y=currentscenario->scenarioZmeika->get_heady();
    currentscenario->scenarioField->set_field(X,Y,snakehead);
    for(int i=0;i<currentscenario->scenarioZmeika->Tail2.size();i++)
    {
        X=currentscenario->scenarioZmeika->Tail2[i]->getx();
        Y=currentscenario->scenarioZmeika->Tail2[i]->gety();
        currentscenario->scenarioField->set_field(X,Y,snaketail);
    }


    //int G=currentscenario->scenarioFructs->Apples.max_size();

    //for(unsigned int i=0;i<currentscenario->scenarioFructs->Apples.size();i++)
    {
        //X=currentscenario->scenarioFructs->Apples[i]->getx();
        //Y=currentscenario->scenarioFructs->Apples[i]->gety();
        //currentscenario->scenarioField->set_field(X,Y,app);
    }


    /*
    for(unsigned int i=0;i<currentscenario->scenarioFructs->Grushes.size();i++)
    {
        X=currentscenario->scenarioFructs->Grushes[i]->getx();
        Y=currentscenario->scenarioFructs->Grushes[i]->gety();
        currentscenario->scenarioField->set_field(X,Y,pear);
    }
    */


}

char Game::intToChar (int Code)
{
    switch(Code)
    {
    case app:
        return 'a';
        break;
    case pear:
        return 'g';
        break;
    case snakehead:
        return '@';
        break;
    case snaketail:
        return '#';
        break;
    case 8:
        return '_';
        break;
    default:
        return '_';
        break;
    }
}


