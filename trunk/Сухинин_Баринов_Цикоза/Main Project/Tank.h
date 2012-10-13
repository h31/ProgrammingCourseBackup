#ifndef _TANK_
#define _TANK_

#include "include\hge\hgevector.h"
#include "Weapon.h"
#include <list>
#include <string>
//#include "Entity.h"
using namespace std;


//����� ���������
class Tank//: public Entity
{
public:

	std::string Owner; //��� ������-���������
	DWORD color;		//���� �����
	hgeVector position; //��������� ������������ ������ �����

	double acceleration; //���������

	double speed; //������� �������� 
	double speed_front_limit; //������ �������� ������ ��������
	double speed_angle; //������� �������� 

	double angle_turret;			//������� ����
	double angle_turret_prefer;		//�������� ����
	double angle_turret_speed;//�������� �������� �����
	double angle_tank; //���� �������� ����� � ������ �����

	hgeVector ViewDist,r1,r2;//��������� ������, ����� � ������ �������
	float angle;

	list <Weapon*> weapons; //������ ��������� ������

	int direction_front; //-1 �����, 0 �� �����, 1 ������
	int direction_angle; //-1 ������, 0 �� �����, 1 �������

	Weapon * weapon_left; //����� � ������ ������
	Weapon * weapon_right;
	void SetWeapon_left(Weapon * w){this->weapon_left=w;}
	void SetWeapon_right(Weapon * w){this->weapon_right=w;}
	//�������� ���������� � ����� ����, �� ����������������� ����������� ��������� ������
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