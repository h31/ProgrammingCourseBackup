#include "stdafx.h"
#include "Game.h"
#include "iostream"
using namespace std;

Game::Game ()
{
    cycle_snake=1;
    time=0;
    scenario1=new Scenario1();
	scenario2=new Scenario2();
	scenario3=new Scenario3();
	score=0.0f;
}

Game::~Game()
{
}
void Game::update()
{
    system("cls");
    scenario0->run(cycle_snake);
	if (scenario0->scenarioZmeika->checkEatFruct(scenario0->scenarioFructs,scenario0->scenarioField))
	{
		score+=10;
		cout<<"eat fruct\n";
	}
	if(scenario0->scenarioZmeika->checkWall(scenario0->scenarioField))
	{
		updateField(scenario0);
		printField(scenario0);
		cout<<"boom... wall\n";
		system("pause");
		exit(2);

	}
	if(scenario0->scenarioZmeika->checkSelfEating())
	{
		updateField(scenario0);
		printField(scenario0);
		cout<<"eat herself\n";
		system("pause");
		exit(2);

	}
	updateField(scenario0);
	printField(scenario0);
	printToFile(cycle_snake,scenario0);
    _sleep(2000);
    time+=2000;
    cycle_snake++;
}
int Game::gettime() {
    return time;
}
bool Game::settime (int newtime) {
    if (newtime<0) return false;
    else
    {
        time=newtime;
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
	cout<<"score:"<<score<<endl;
	int iS=-1;
	for(int i=0;i<H;i++)
	{
		for(int j=0;j<W;j++)
		{
			iS=currentscenario->scenarioField->get_field(i,j);
			cout<<intToChar(iS)<<" ";
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
	for(unsigned int i=0;i<currentscenario->scenarioZmeika->Tail2.size();i++)
	{
		X=currentscenario->scenarioZmeika->Tail2[i]->getx();
		Y=currentscenario->scenarioZmeika->Tail2[i]->gety();
		currentscenario->scenarioField->set_field(X,Y,snaketail);
	}
	int TP=-1;
	for(unsigned int ii=0;ii<currentscenario->scenarioFructs->Fruits.size();ii++)
	{
		X=currentscenario->scenarioFructs->Fruits[ii]->getx();
		Y=currentscenario->scenarioFructs->Fruits[ii]->gety();
		TP=currentscenario->scenarioFructs->Fruits[ii]->gettype();
		currentscenario->scenarioField->set_field(X,Y,TP);
	}
}

char Game::intToChar (int code)
{
    switch(code)
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
        return '?';
        break;
    }
}

void Game::printToFile(int cycle,Scenario*currentscenario)
{
	FILE *wrFile=fopen("trace.txt","a+");
	FILE *fieldFile=fopen("field.txt","a+");
	if(wrFile)
	{
		int X,Y,nX,nY;
		if(cycle==1)
			fprintf(wrFile,"--------------------------\n");
		fprintf(wrFile,"[%d]\n",cycle);
		fprintf(wrFile,"%d\n",currentscenario->scenarioZmeika->getdir());
		X=currentscenario->scenarioZmeika->get_headx();
		Y=currentscenario->scenarioZmeika->get_heady();
		nX=currentscenario->scenarioZmeika->get_napx();
		nY=currentscenario->scenarioZmeika->get_napy();
		fprintf(wrFile,"Head    (%d,%d)(%d,%d)\n",X,Y,nX,nY);
		for(unsigned int ii=0;ii<currentscenario->scenarioZmeika->Tail2.size();ii++)
		{
			X=currentscenario->scenarioZmeika->Tail2[ii]->getx();
			Y=currentscenario->scenarioZmeika->Tail2[ii]->gety();
			nX=currentscenario->scenarioZmeika->Tail2[ii]->getnapx();
			nY=currentscenario->scenarioZmeika->Tail2[ii]->getnapy();
			fprintf(wrFile,"Tail[%2d](%d,%d)(%d,%d)\n",ii,X,Y,nX,nY);	
		}
	}
	if(fieldFile)
	{
		int H=currentscenario->scenarioField->get_height();
		int W=currentscenario->scenarioField->get_width();
		int C=8;
		if(cycle==1)
			fprintf(wrFile,"--------------------------\n");
		fprintf(fieldFile,"[%d]\n",cycle);
		for(int i=0;i<H;i++)
		{
			for(int j=0;j<W;j++)
			{
				C=currentscenario->scenarioField->get_field(i,j);
				fprintf(fieldFile,"%d ",C);
			}
			fprintf(fieldFile,"\n ");
		}

	}
	fclose(wrFile);
	fclose(fieldFile);
}