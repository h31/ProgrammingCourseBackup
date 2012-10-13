//Автор Дима Баринов 3081/4

#ifndef _CONTROL_
#define _CONTROL_

#include "Tank.h"
#include "Data.h"
#include "RenderData.h"
#include "Bullet.h"
#include <math.h>
#include "Counter.h"
using namespace boost;

class Control
{
	//объекты, с которыми работает класс
	HGE * hge;
	Data *data;

public:
	
	bool left,right,forward,backward,fire_weapon1,fire_weapon2;//флаи нажатия клавиши
	bool space, ar_left,ar_right,ar_up,ar_down;//debug
	float	mouse_x, mouse_y;//координаты мышки
	float d_x,d_y;//debug
	bool weaponready;//debug
	Control(HGE* hge,Data * data/*,Counter* counter*/)
	{
		d_x=0;d_y=0;
		this->data=data;
		this->hge=hge; 
		//this->counter=counter;
		this->space=false;
		this->ar_left=false;
		this->ar_right=false;
		this->ar_up=false;
		this->ar_down=false;
		this->left=false;
		this->right=false;
		this->forward=false;
		this->backward=false;
		this->fire_weapon1=false;
		this->fire_weapon2=false;
		this->weaponready=true;
	}
	bool Detect_input(float,float);//слушаем данные от пользователя(нажатие клавиши)
	void Tank_shoot(Tank*);//выстрел
};

#endif