#ifndef _WEAPON_
#define _WEAPON_

#include <string>

//возможное оружие
class Weapon
{
public:
	std::string Name;//дл€ большео удобства
	int type; //тип оружи€(пуль, которыми срел€ет), а также id в ParticleArr
	double damage;//урон
	double radius; //радиус поражени€
	double explodeRadius; //если 0, то не взрываетс€
	float countDown; //врем€ перезар€дки
	float ready;//>=0 значит оредие готово 
	float startSpeed;//начальна€ скорость полета снар€да
	Weapon(std::string Name,int countDown,float radius,float startSpeed,int type)
	{
		this->Name=Name;
		this->countDown=countDown;
		this->radius=radius;
		this->ready =countDown;
	    this->startSpeed=startSpeed;
		this->type=type;
	}
	Weapon (Weapon *wep )
	{
		this->Name=wep->Name;
		this->countDown=wep->countDown;
		this->radius=wep->radius;
		this->ready =wep->countDown;
	    this->startSpeed=wep->startSpeed;
		this->type=wep->type;
	}
	double damage_up; //прыжок улучшени€ повреждений
	//...
	~Weapon(){}
	
};
#endif