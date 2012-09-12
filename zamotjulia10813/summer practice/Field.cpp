#include "Field.h"

Field::Field (int W, int H)
{
    width=W; height=H;
    createField ();
	init();
}

Field:: ~Field ()
{
    for (int i=0; i<height; i++)
        delete field [i];
    delete [ ] field;
}

bool Field::set_field (int x, int y, int new_value)
{ 
	if(x>=0 && x<width && y>=0 && y<height)
	{
		field [x][y] = new_value;
		return true;
	}
	else
		return false;


}

int Field::get_field (int x, int y) {
    return field [x][y]; }

int Field::get_width () { return width;}

bool Field::set_width (int new_width) {
    if (new_width<0) return false;
    else
    {
        width=new_width;
        return true;
    }
}

int Field::get_height ()  {return height;}

bool Field::set_height (int new_height) {
    if (new_height<0) return false;
    else
    {
        height=new_height;
        return true;
    }
}

bool Field::createField()
{
    field = new int *[height];

        for (int i=0; i<height; i++)
        {
            field [i]= new int [width];
        }
        return true;
}

void Field::init () {


        for (int i=0; i<height; i++)
             for (int g=0; g<width; g++)
                 field [i][g]=8;
    }


bool Field::resize(int size1, int size2) {
    if (size1<=0 || size2<=0)
        return false;
    width=size1;
    height=size2;
    for(int i=0; i<height;i++)
        delete field [i];
    delete field;
    createField();
    return true;
}

