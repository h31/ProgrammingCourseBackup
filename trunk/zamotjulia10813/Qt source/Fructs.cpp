
#include "Fructs.h"
Fructs::Fructs (int len) 
{
        numberfructs=len;
		Fruits.clear();
}

Fructs::Fructs () 
{
		numberfructs=0;
		Fruits.clear();
}

void Fructs::add (int size1,int size2) {

        for(int i=0; i<numberfructs; i++)
        {
        int random=rand() %2+1;
        int x=rand() %size1;
        int y=rand() %size2;
        Apple*ap= new Apple (x,y);
        Pear*pear= new Pear (peartime,x,y);
        switch (random) {
            case 1:
                    Fruits [i]=ap;
                    break;
            case 2:
                    Fruits [i]=pear;
                    break;
        }
        }
    }

    bool Fructs::set_numberfructs (int new_numberfructs)
    {
        if(new_numberfructs<0)
        {
            return false;
        }
        else
        {
            numberfructs=new_numberfructs;
            return true;
        }
    }
    int Fructs::get_numberfructs()
    {
        return numberfructs;
    }

	void Fructs::addApple(Apple *new_apple)
	{
		Fruits.push_back(new_apple);
	}

	void Fructs::addPear(Pear*new_pear)
	{
	
		Fruits.push_back(new_pear);
	}
	bool Fructs::deleteFruct(int number)
	{
		if(number<0 || number >= Fruits.size())
			return false;
		Fruits[number]->setx(-1);
		return true;
	}
