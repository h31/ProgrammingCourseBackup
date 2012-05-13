#include "game.h"
#include "Field.h"


Game::Game():QMainWindow()
{
    initgame();
}
void Game::initgame()
{
   Gfield=new Field(field_width,field_height);
   Gfructs=new Fructs(0);
   Gzmeika= new Zmeika(snake_x,snake_y,dtop,snake_length);

   addfructs(apple_amount+pear_amount);
}



void Game::addfructs(int amount)
{
    int X=rand()%Gfield->get_width()-2;
    int Y=rand()%Gfield->get_height()-2;

    for (int i=0;i<apple_amount;i++)
    {
        while(!checkPositionForFruct(X,Y))
        {
            X=rand()%Gfield->get_width()-2;
            Y=rand()%Gfield->get_width()-2;
        }
        Apple *newapp=new Apple(X,Y);
        this->Gfructs->addApple(newapp);
    }
    X=rand()%Gfield->get_width()-2;
    Y=rand()%Gfield->get_width()-2;
    for (int i=0;i<pear_amount;i++)
    {
         while(!checkPositionForFruct(X,Y))
         {
             X=rand()%Gfield->get_width()-2;
             Y=rand()%Gfield->get_width()-2;
         }
       Pear *newpear=new Pear(10,X,Y);
        this->Gfructs->addPear(newpear);
    }
}

void Game::paintEvent(QPaintEvent*)
{

}

void Game::updatefield()
{
    for(int i=0;i<Gfield->get_height();i++)
    {
        for(int j=0;j<Gfield->get_width();j++)
        {
            Gfield->set_field(i,j,empty);
        }
    }
    int X=Gzmeika->get_headx();
    int Y=Gzmeika->get_heady();
    Gfield->set_field(Y,X,snakehead);
    for( unsigned int k=0;k<Gzmeika->Tail2.size();k++)
    {
        X=Gzmeika->Tail2[k]->getx();
        Y=Gzmeika->Tail2[k]->gety();
        Gfield->set_field(Y,X,snaketail);
    }
    int ftype;
    for(int q=0;q<Gfructs->Fruits.size();q++)
    {
        X=Gfructs->Fruits[q]->getx();
        Y=Gfructs->Fruits[q]->gety();
        ftype=Gfructs->Fruits[q]->gettype();
        Gfield->set_field(Y,X,ftype);
    }

}

void Game::update()
{
   // Gzmeika->move();
    //this->updatefield();
}

void Game::keyPressEvent(QKeyEvent *ev)
{
        switch (ev->key())
        {
            case 16777234:
               //this->Gzmeika->rotateClockwise();
                break;
            case 16777236:
                //this->Gzmeika->rotateAClockwise();
                break;
        }
}

bool Game::checkPositionForFruct(int X,int Y)
{
    if(X<0 ||Y<0)
        return false;
    if(X>Gfield->get_width() || Y>Gfield->get_height())
        return false;
    if(X==this->Gzmeika->get_headx() && Y==this->Gzmeika->get_heady())
        return false;
    for(int i=0;i<Gzmeika->Tail2.size();i++)
    {
        if(Gzmeika->Tail2[i]->getx()==X && Gzmeika->Tail2[i]->gety()==Y)
            return false;
    }
    for(int j=0;j<Gfructs->Fruits.size();j++)
    {
        if(Gfructs->Fruits[j]->getx()==X && Gfructs->Fruits[j]->gety()==Y)
            return false;
    }
    return true;
}
