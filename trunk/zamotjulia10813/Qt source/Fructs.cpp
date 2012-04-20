#include "Fructs.h"

Fructs::Fructs (int len) {
        numberfructs=len;

        fruct = new Fruct*[numberfructs];

        // инициализация массива
        for (int i=0; i<numberfructs; i++)
        {
            fruct [i] = 0;
        }
    }

//добавить фрукты в массив
void Fructs::add (int size1,int size2) {

        for(int i=0; i<numberfructs; i++)
        {
        int random=rand() %2+1;
        int x=rand() %size1; //чтобы не вылететь за пределы поля
        int y=rand() %size2;
        Apple*ap= new Apple (x,y);
        Pear*pear= new Pear (peartime,x,y);
        switch (random) {
            case 1:
                    fruct [i]=ap;
                    break;
            case 2:
                    fruct [i]=pear;
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
        //Apples.push_back(new_apple);
    }
