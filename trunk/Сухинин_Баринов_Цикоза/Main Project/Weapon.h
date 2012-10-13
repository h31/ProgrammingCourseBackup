#ifndef _WEAPON_
#define _WEAPON_

#include <string>

//��������� ������
class Weapon
{
public:
	std::string Name;//��� ������� ��������
	int type; //��� ������(����, �������� �������), � ����� id � ParticleArr
	double damage;//����
	double radius; //������ ���������
	double explodeRadius; //���� 0, �� �� ����������
	float countDown; //����� �����������
	float ready;//>=0 ������ ������ ������ 
	float startSpeed;//��������� �������� ������ �������
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
	double damage_up; //������ ��������� �����������
	//...
	~Weapon(){}
	
};
#endif