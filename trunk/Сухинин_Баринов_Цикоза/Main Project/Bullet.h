#ifndef _BULLET_
#define _BULLET_

//#include "Entity.h"
#include "include\hge\hgevector.h"
#include "include\hge\hgeparticle.h"
#include <list>
using namespace std;

enum LifeCircle {Life, Unused, CanRemove};

//������
class Bullet//: public Entity
{
public:
	int   type; //��� �������
	hgeVector position; //������ ���������
	hgeVector speed; //������ ����������� � ��������
	int damage; //��������� �����������
	double explodeRadius; //������ ���������
	double range; //������ ����� �������

	LifeCircle lifecircle;//������ ���������� ����� 


	Bullet(hgeVector position, hgeVector speed,int type,double range)
	{


		this->lifecircle=Life;
		this->position=position;
		this->speed=speed;
		this->type=type;
		this->range=range;
		
	}
};




#endif