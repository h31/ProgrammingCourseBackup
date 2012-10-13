#ifndef _TANK_
#define _TANK_

#include "include\hge\hgevector.h"
#include "Weapon.h"
#include <list>
#include <string>
//#include "Entity.h"
using namespace std;


//Танки союзников
class Tank//: public Entity
{
public:

	std::string Owner; //имя игрока-владельца
	DWORD color;		//цвет танка
	hgeVector position; //положение относительно начала карты

	double acceleration; //ускорение

	double speed; //текущая скорость 
	double speed_front_limit; //предел скорости вперед скорости
	double speed_angle; //угловая скорость 

	double angle_turret;			//текущий угол
	double angle_turret_prefer;		//желаемый угол
	double angle_turret_speed;//скорость поворота башни
	double angle_tank; //угол поворота башни и самого танка

	hgeVector ViewDist,r1,r2;//дальность обзора, левая и правая границы
	float angle;

	list <Weapon*> weapons; //список возможных орудий

	int direction_front; //-1 назад, 0 на месте, 1 вперед
	int direction_angle; //-1 налево, 0 на месте, 1 направо

	Weapon * weapon_left; //левое и правое орудия
	Weapon * weapon_right;
	void SetWeapon_left(Weapon * w){this->weapon_left=w;}
	void SetWeapon_right(Weapon * w){this->weapon_right=w;}
	//копирует вооружение в класс танк, тк предусматривается возможности улучшения оружия
	void CopyWeaponList(list<Weapon*> &l)
	{
		for (list<Weapon*>::iterator it= l.begin();it!=l.end();it++)
		{
			this->weapons.push_back(new Weapon(*it));
		}
	}

	Tank(
		std::string Owner,
		hgeVector position,
		double acceleration,
		double speed_front_limit,
		double speed_angle,
		DWORD color)
	{
		
		this->Owner=Owner;

		this->position=position;
		this->acceleration=acceleration;
		this->weapons= list<Weapon*>();
		this->speed_angle=speed_angle;
		this->color=color;
		this->speed=0;
		this->ViewDist = hgeVector(10,0);
		this->angle=M_PI_4/2;
		this->r1=this->ViewDist;
		this->r1.Rotate(this->angle);
		this->r2=this->ViewDist;
		this->r2.Rotate(-this->angle);

		this->angle_turret=0;this->angle_tank=0;

		this->direction_front=0;this->direction_angle=0;

		this->acceleration=acceleration;

		this->speed_front_limit=speed_front_limit;
		//this->speed_front_limit=4;

	};
	~Tank(){for(list<Weapon*>::iterator it=this->weapons.begin();it!=this->weapons.end();it++) delete *it;}
};
#endif