#include "Field.h"

Pole:: Pole (int W, int H) {w=W; h=H;};
void Pole:: showpole( Fructs *Fruits, Zmeika *Zmeia ) {
		
	    p= new int *[h]; //поле состоит из символов
		
		for (int i=0; i<h; i++)
		{
			p[i]= new int[w];
		}
		
		for (int i=0; i<h; i++)
			 for (int g=0; g<w; g++)
				 p[i][g]=8; //там где ничего нет будет 8
		
		int x,y;
		for (int i=0; i<N; i++)
		{
			x= Fruits->fruct[i]->x;
		    y= Fruits->fruct[i]->y;
			p[x][y]= Fruits->fruct[i]-> show();

		}
		//голова змеи
		x= Zmeia->Headx;
		y= Zmeia->Heady;
		p[x][y]= Zmeia->showHead();

		//хвост
		for (int i=0; i<2; i++)
		{
			x=Zmeia->Tail[i].getx();
			y=Zmeia->Tail[i].gety();
			p[x][y]= Zmeia->showTail();
		}

		// вывод массива поля
				for (int i=0; i<h; i++)
				{
					for (int g=0; g<w; g++)
					cout<<p[i][g];
					cout<<endl;
				}
		

	};