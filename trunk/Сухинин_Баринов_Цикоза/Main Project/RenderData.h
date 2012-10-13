//Автор Дима Баринов 3081/4

#ifndef _RENDERDATA_
#define _RENDERDATA_

#include "include\hge\hgeresource.h"
#include <string>
#include <list>
#include "Bullet.h"
#include "Effects.h"
using namespace std;
//максимальное возможное число вариантов спрайтов и частиц
#define MAX_SPRITES 20
#define MAX_PARTICLES 20

class MyType
{
public:
	std::string name;//using for load
	int id;
};
class SpriteClass: public MyType//хранит все варианты спрайтов для рисования
{
public:
	hgeSprite* sprite;
	SpriteClass(int id,string name,hgeSprite*sprite){this->id=id;this->name=name;this->sprite=sprite;}
	~SpriteClass(){delete sprite;}
};
class ParticleClass : public MyType//хранит все виды систем частиц
{
public:
	hgeParticleSystem * particleSistem;
	ParticleClass(int id,string name,hgeParticleSystem* particleSistem){this->id=id;this->name=name;this->particleSistem=particleSistem;}
	~ParticleClass(){delete particleSistem;}
};


//класс, хранящий все данные для рисования
class RenderData
{
	HTEXTURE tex;
public:
	//hgeParticleManager *particleManager;
	(SpriteClass *)  Arr[MAX_SPRITES];//массив спрайтов
	(ParticleClass*) ParticleArr[MAX_PARTICLES];//массив систем частиц
	list <Effects*> ef;//массив эффектов
	int count_Arr,count_ParticleArr;
	//hgeParticleSystem * p;//debug
	//hgeSprite *test;//debug
	hgeFont* fnt;//шрифт
	//functions
	RenderData(){count_Arr=0;count_ParticleArr=0;}
	bool LoadAll();
	bool LoadSprite(SpriteClass *);
	bool LoadParticle(ParticleClass *);
	hgeSprite* GetSprite(int id){return Arr[id]->sprite;}
	HTEXTURE LoadTex(HGE *,string);
	void Free(){ 
		HGE * hge=hgeCreate(HGE_VERSION);
		delete fnt;hge->Texture_Free(this->tex);
		for (int i=0;i<count_Arr;i++)
		{
			delete Arr[i];
		}
		for (int i=0;i<count_ParticleArr;i++)
		{
			delete ParticleArr[i];
		}
		for (list <Effects*>::iterator it = this->ef.begin();it!=this->ef.end();it++)
		{
			delete *it;
		}
		hge->Release();
	}
	
	
};


#endif