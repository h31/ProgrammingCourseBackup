#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

#include "Field.h"
#include "Fruct.h"
#include "Snake.h"
#include "Game.h"

void main() {
    system("title Snake");
    Game * G1=new Game();
    int choice;
    int choice2;
    for(; ;)
    {
        system("cls");
        cout<<"The Game <Snake>\n";
        cout<<"MENU\n";
        cout<<"1. Choose one of the game scenarios\n"; //выбрать 1 из сценариев
        cout<<"2. Program description\n"; //описание программы (сценариев)
        cout<<"3. Exit\n";
        cout<<"Please, choose one option of the menu:\n";
        cin>>choice;
        switch(choice)
        {
        case 1:
            for(;;)
            {
                cout<< "1. The first Scenario\n";
                cout<< "2. The second Scenario\n";
                cout<< "3. The third Scenario\n";
                cout<< "Please, choose one of the game scenarios:\n";
                cin>>choice2;
                switch(choice2)
                {
                    case 1:
                        cout<<"Run Scenario1\n";
                        G1->scenario0=G1->scenario1;
                        break;
                    case 2:
                        cout<<"Run Scenario2\n";
                        G1->scenario0=G1->scenario2;
                        break;
                    case 3:
                        cout<<"Run Scenario1\n";
                        G1->scenario0=G1->scenario3;
                        break;
                    default:
                        cout<<"Error, choose one option again:\n";
                        system("pause");
                        continue;

                }
                break;
            }
            break;
        case 2:
            cout<<"1. move to fruct and eat\n"; //описание
            cout<<"2. move to wall\n";
            cout<<"3. eat  tail\n";
            system("pause");
            system("cls");
            continue;
            break;
        case 3:
            cout<<"exit.Goodbye!\n";
            system("pause");
            exit(1);
            break;
        default:
            cout<<"Error, choose one option again:\n";
            system("pause");
            continue;
        }
        break;
    }
    while(G1->scenario0->scenarioZmeika->getAlive())
    {
        G1->update();
    }
    system("pause");

}
