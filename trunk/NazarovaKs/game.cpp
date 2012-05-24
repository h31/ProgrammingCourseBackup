#include "test.h"
#include "game.h"

Game::Game(){}

bool Game::checkEnd(Field& f){
   if(f.field.size()>=maxRows)
        return true;
   /*  for (int i=0; i<f.field.size(); i++)
        for(int j=0; j<maxColumns; j++){
            if (f.field[i].getData(j)){
                break;
                return false;
            }
            else if (i==f.field.size()-1 && j==maxColumns-1){
                cout<<"You're winner!";
                return true;
            }
                else{
                    break;
                    return false;
                }
            }*/
    return true;
}
