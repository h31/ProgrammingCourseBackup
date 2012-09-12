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
    if(this->GetPause()!=true)
    {
            Gzmeika->move();
            this->updatefield();
    }
}

void Game::keyPressEvent(QKeyEvent *ev)
{
        switch (ev->key())
        {
            case 16777234:
              this->Gzmeika->rotateClockwise();
                break;
            case 16777236:
                this->Gzmeika->rotateAClockwise();
                break;
        case Qt::Key_S:
            this->SaveToFile();
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


bool Game::SaveToFile()
{
    FILE * SaveFile=fopen("Game.txt","w+");
        if(SaveFile)
        {
            //список всех записываемых переменных

            int Rwidth=this->Gfield->get_width();
            int Rheight=this->Gfield->get_height();
            int RLtail=this->Gzmeika->Tail2.size();	//длина хвоста
            int RNfru=this->Gfructs->Fruits.size();	//число фруктов
            int RX=0;		//х-координата объекта
            int RY=0;		//y-координата объекта
            int Dirx=0;		//направление по x
            int Diry=0;		//направление по y
            int Type=1;		//Тип фрукта
            //int Time=0;	//время игры или фрукта
            //string Name	//имя игрока
            float score=this->MathPoints();//счет игры

            fprintf(SaveFile,"width%d\nheigth%d\n",Rwidth,Rheight);
            fprintf(SaveFile,"Tail%d\nFructs%d\n",RLtail,RNfru);
            RX=this->Gzmeika->get_headx();
            RY=this->Gzmeika->get_heady();
            Dirx=this->Gzmeika->get_napx();
            Diry=this->Gzmeika->get_napy();
            fprintf(SaveFile,"Head%d\t%d\t%d\t%d\n",RX,RY,Dirx,Diry);
            for (int i=0;i<RLtail;i++)
            {
                RX=this->Gzmeika->Tail2[i]->getx();
                RY=this->Gzmeika->Tail2[i]->gety();
                Dirx=this->Gzmeika->Tail2[i]->getnapx();
                Diry=this->Gzmeika->Tail2[i]->getnapy();
                fprintf(SaveFile,"Tail#%d\t%d\t%d\t%d\t%d\n",i,RX,RY,Dirx,Diry);
            }
            for (int ii=0;ii<RNfru;ii++)
            {
                RX=this->Gfructs->Fruits[ii]->getx();
                RY=this->Gfructs->Fruits[ii]->gety();
                Type=this->Gfructs->Fruits[ii]->gettype();
                fprintf(SaveFile,"Fruct#%d\t%d\t%d\t%d\n",ii,RX,RY,Type);
            }

            fprintf(SaveFile,"Score %d\n",score);
            fclose(SaveFile);
            return true;
        }
        fclose(SaveFile);
        return false;
}


float Game::MathPoints()
{
    float Summ=0;
    Summ=this->Gzmeika->Tail2.size();
    Summ+=Cycles;
    return Summ;
}

bool Game::checkSnakeAlive()
{
    if(this->Gzmeika->GetAlive()==false)
    {
        this->SetPause(true);	//делаем паузу
        MathPoints();			//считаем очки
        //записываем результат в файл
        return false;
    }
    return true;
}


int Game::GetCycles()
{
    return Cycles;
}
bool Game::SetCycles(int newNCycles)
{
    if (newNCycles<=0)
        Cycles=0;
    else
        Cycles=newNCycles;
    return true;
}
void Game::IncCycles()
{
    Cycles=Cycles+1;
}
bool Game::LoadGame()
{
    FILE * OpenFile=fopen("Game.txt","r");
    if(OpenFile)
    {
            //список считываемых данных
            int Rwidth=0;
            int Rheight=0;
            int RLtail=0;	//длина хвоста
            int RNfru=0;	//число фруктов
            int RX=0;		//х-координата объекта
            int RY=0;		//y-координата объекта
            int Dirx=0;		//направление по x
            int Diry=0;		//направление по y
            int Num=0;
            int Type=1;		//Тип фрукта
            //int Time=0;	//время игры или фрукта
            //string Name	//имя игрока
            float score=0;	//счет игры
            fscanf(OpenFile,"width%d\nheigth%d\n",&Rwidth,&Rheight);
            fscanf(OpenFile,"Tail%d\nFructs%d\n",&RLtail,&RNfru);
            fscanf(OpenFile,"Head%d\t%d\t%d\t%d\n",&RX,&RY,&Dirx,&Diry);
            this->Gzmeika->set_headx(RX);
            this->Gzmeika->set_heady(RY);
            this->Gzmeika->set_napx(Dirx);
            this->Gzmeika->set_napy(Diry);
            for(int j=0;j<RLtail;j++)
            {
                fscanf(OpenFile,"Tail#%d\t%d\t%d\t%d\t%d\n",&Num,&RX,&RY,&Dirx,&Diry);
                this->Gzmeika->Tail2[Num]->setx(RX);
                this->Gzmeika->Tail2[Num]->sety(RY);
                this->Gzmeika->Tail2[Num]->set_napx(Dirx);
                this->Gzmeika->Tail2[Num]->set_napy(Diry);
            }

            for (int ii=0;ii<RNfru;ii++)
            {
                fscanf(OpenFile,"Fruct#%d\t%d\t%d\t%d\n",&Num,&RX,&RY,&Type);
                this->Gfructs->Fruits[Num]->setx(RX);
                this->Gfructs->Fruits[Num]->sety(RY);
                this->Gfructs->Fruits[Num]->settype(Type);
            }

        //WriteFructsStatusToFile(game->Gfructs);
        //WriteTailStatusToFile(game->Gzmeika);
        fclose(OpenFile);
        return true;
    }
    fclose(OpenFile);
    return false;
}

bool Game::GetPause()
{
    return this->Pause;
}

void Game::SetPause(bool NPause)
{
    this->Pause=NPause;
}

