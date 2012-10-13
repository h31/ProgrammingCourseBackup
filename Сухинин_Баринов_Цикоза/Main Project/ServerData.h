#ifndef _SERVERDATA_
#define _SERVERDATA_

#include "Tank.h"
#include "Bullet.h"
#include "HGETileMap.h"
#include <list>

using namespace std;

class ServerData
{
	public:
	//HGETileMap *tilemap;//map, for render only
	list<Bullet*> bullets;//all bullets on map, not all of them for render
	list<Tank*> tanks;//all friendly units "Tank"
	//list <Mobs> mobs;
	
	list<Weapon*> weapons;//all kinds of weapon
	ServerData();
	//ServerData(){}
	void Free();
};


#endif