#ifndef _DATA_
#define _DATA_

#include "Tank.h"
#include "Bullet.h"
#include "HGETileMap.h"
#include <list>
#include "RenderData.h"
#include"include\hge\hgeresource.h"
#include <boost\thread\mutex.hpp>

using namespace std;
using namespace boost;


static mutex mut_Data;


class Data
{
public:
	
	RenderData * renderdat;//for render only
	HGETileMap *tilemap;//map, for render only
	list<Bullet*> bullets;//all bullets on map, not all of them for render
	list<Tank*> tanks;//all friendly units "Tank"
	//list <Mobs> mobs;
	//hgeResourceManager* res;
	list<Weapon*> weapons;//all kinds of weapon
	Data(HGE*);
	Tank* My_tank;
	Data(){}
	void Free();
	
};

#endif