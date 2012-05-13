#include "Snake.h"

Zmeika::Zmeika(int X, int Y, int Napx, int Napy,int LTail)
{
    headx=X;
    heady=Y;
    napx=Napx;
    napy=Napy;
	Alive=true;
    for(int i=0;i<LTail;i++)
    {

        ZmElement*ZmTeiltemp=new ZmElement(headx, heady+i+1);
		Tail2.push_back(ZmTeiltemp);
        Tail2[i]->set_napx(this->napx);
        Tail2[i]->set_napy(this->napy);
        
    }
}
Zmeika::Zmeika(int X,int Y,int new_direction,int LTail)
{
	headx=X;
	heady=Y;
	Alive=true;
	switch(new_direction)
	{
		case dtop:
			rotateUp();
			break;
		case ddown:
			rotateDown();
			break;
		case dright:
			rotateRight();
			break;
		case dleft:
			rotateLeft();
			break;
		case nodir:
		default:
			rotateUp();
			break;
	}

	for(int i=0;i<LTail;i++)
    {
        ZmElement*ZmTeiltemp=new ZmElement(headx, heady+i+1);
		Tail2.push_back(ZmTeiltemp);
		Tail2[i]->set_napx(this->napx);
        Tail2[i]->set_napy(this->napy);
        
    }
}
Zmeika::Zmeika () 
{
	Alive=true;
}

Zmeika::~Zmeika() 
{
		Tail2.clear();
}
int Zmeika::get_headx() {return headx;}
int Zmeika::get_heady() {return heady;}
bool Zmeika::set_headx (int new_headx) {
        headx=new_headx;
        return true;
    }
bool Zmeika::set_heady (int new_heady) {
        heady=new_heady;
        return true;
    }

int Zmeika::get_napx() {return napx;}
int Zmeika::get_napy() {return napy;}
bool Zmeika::set_napx (int new_napx) {
        napx=new_napx;
        return true;
    }
bool Zmeika::set_napy (int new_napy) {
        napy=new_napy;
        return true;
    }

int Zmeika::enumerateHead() { return snakehead;}
int Zmeika::enumerateTail() { return snaketail;}

bool Zmeika::move()
{
    headx+=napx;
    heady+=napy;

    for (unsigned int i=0; i<Tail2.size(); i++)
    {
          Tail2[i]->setx(Tail2[i]->getx()+Tail2[i]->getnapx());
          Tail2[i]->sety(Tail2[i]->gety()+Tail2[i]->getnapy());
    }
    shift();
    return true;

}
void Zmeika::shift() {


    for (unsigned int i=Tail2.size()-1; i>=1; i--) { 
        Tail2[i]->set_napx(Tail2[i-1]->getnapx());
        Tail2[i]->set_napy(Tail2[i-1]->getnapy());
    }
	Tail2[0]->set_napx(this->napx);
    Tail2[0]->set_napy(this->napy);
}

bool Zmeika:: rotateRight() 
{
	napx=1;
	napy=0;
	dir=dright;
 return true;
}

bool Zmeika:: rotateLeft() {
 napx=-1;
 napy=0;
 dir=dleft;
 return true;
}

bool Zmeika:: rotateUp() {
 napx=0;
 napy=-1;
 dir=dtop;
 return true;
}

bool Zmeika:: rotateDown() {
 napx=0;
 napy=1;
 dir=ddown;
 return true;
}
bool Zmeika::rotateClockwise()
{
	switch(dir) //without break;
	{
	case dtop:
        rotateRight();
		return true;
	case ddown:
        rotateLeft();
		return true;
	case dright:
		rotateDown();
		return true;
	case dleft:
		rotateUp();
		return true;
	case nodir:
	default:
		return false;

	}
	return false;
}

bool Zmeika::rotateAClockwise()
{
	switch(dir) //without break;
	{
	case dtop:
        rotateLeft();
		return true;
	case ddown:
        rotateRight();
		return true;
	case dright:
		rotateUp();
		return true;
	case dleft:
		rotateDown();
		return true;
	case nodir:
	default:
		return false;

	}
	return false;
}

bool Zmeika::checkEatFruct(Fructs *AllFructs,Field *fullfield)
{
	for(unsigned int i=0;i<AllFructs->Fruits.size();i++)
	{
		if(this->headx==AllFructs->Fruits[i]->getx() && this->heady==AllFructs->Fruits[i]->gety())
		{
            this->score+=AllFructs->Fruits[i]->gettype();
			AddTail(fullfield);
			AllFructs->deleteFruct(i);
			return true;
		}
			
	}
	return false;
}

bool Zmeika::AddTail(Field *fullfield)
{
	int L=this->Tail2.size();
	int ty=Tail2[L-1]->gety();
	int tx=Tail2[L-1]->getx();
    bool hasfruct=false;
    bool hasbody=false;
    if(this->dir=dtop)
        ty=ty+1;
    if(this->dir=ddown)
        ty=ty-1;
    if(this->dir==dleft)
        tx=tx+1;
    if(this->dir==dright)
        tx=tx-1;
	if(ty<fullfield->get_height())
	{
        ZmElement *newT = new ZmElement(tx,ty);
		newT->set_napx(Tail2[L-1]->getnapx());
		newT->set_napy(Tail2[L-1]->getnapy());
		this->Tail2.push_back(newT);
		return true;
	}

	return false;
	
}

bool Zmeika::checkSelfEating()
{
	for(unsigned int i=0;i<Tail2.size();i++)
	{
		if(headx ==Tail2[i]->getx() && heady ==Tail2[i]->gety())
		{
			SetAlive(false);
			return true;
		}
	}
	return false;
}
bool Zmeika::checkWall(Field *fullfield)
{
	if(headx<0 ||heady<0)
	{
		return true;
		SetAlive(false);
	}
	if(headx>=fullfield->get_width() || heady>=fullfield->get_height())
	{
		return true;
		SetAlive(false);
	}
	return false;
}

bool Zmeika::checkPosition(int X,int Y)
{
	if(headx==X && heady==Y)
		return true;
	return false;
}

bool Zmeika::GetAlive()
{
	return Alive;
}

void Zmeika::SetAlive(bool newalive)
{
	Alive=newalive;
}



int Zmeika::getdir()
{
	return dir;
}

bool Zmeika::setdir(int newdir)
{
	if(newdir ==dtop ||newdir ==ddown || newdir ==dright || newdir ==dleft ||newdir==nodir)
	{
		dir=newdir;
		return true;
	}
	return false;
}

ZmElement* Zmeika::GetElementTail2(int Number)
{
	if(Number>0 && Number<Tail2.size())
		return Tail2[Number];	
	else return Tail2[Tail2.size()-1];
}
/*bool SetElementTail2(int Number,ZmElement *newTail)
{
	Tail
}
*/
