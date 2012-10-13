#ifndef _BULLET_
#define _BULLET_

//#include "Entity.h"
#include "include\hge\hgevector.h"
#include "include\hge\hgeparticle.h"
#include <list>
using namespace std;

enum LifeCircle {Life, Unused, CanRemove};

//Снаряд
class Bullet//: public Entity
{
public:
	int   type; //тип снаряда
	hgeVector position; //вектор координат
	hgeVector speed; //вектор направления и скорости
	int damage; //наносимые повреждения
	double explodeRadius; //радиус поражения
	double range; //радиус жизни снаряда

	LifeCircle lifecircle;//модель жизненного цикла 


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