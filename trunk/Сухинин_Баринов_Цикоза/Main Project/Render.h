//Автор Дима Баринов 3081/4


#ifndef _RENDER_
#define _RENDER_
#include "include\hge\hge.h"
#include "include\hge\hgesprite.h"
#include "include\hge\hgefont.h"
#include "include\hge\hgeparticle.h"
#include "RenderData.h"
#include "Data.h"
#include "Control.h"
#include <list>
#include "Bullet.h"


class Render
{
	HGE * hge;
	Data * data;
public:
	Tank* My_tank;
	Render(HGE * hge , Data * data ,Control * control)
	{
		this->data=data;
		this->hge=hge;
		this->data->renderdat= new RenderData();
		this->My_tank=this->data->My_tank;
	}
	bool Load();//загрузка внех необходимых объектов
	void Free();//чистка
	void Render_info(Control * control)//debug
	{
		this->data->renderdat->fnt->printf(3, 3, HGETEXT_LEFT, "FPS: %d\nmouse x: %f\nmouse y: %f\nTileoffset x %d\nTileoffset y %d\ntankpos x: %f\ntankpos y: %f\nNumber of bullets: %d\nNumber of effects: %d",
			hge->Timer_GetFPS(),control->mouse_x,control->mouse_y,this->data->tilemap->GetOffset_x(),this->data->tilemap->GetOffset_y(),My_tank->position.x,My_tank->position.y,
			this->data->bullets.size(),this->data->renderdat->ef.size()/*,this->data->renderdat->ParticleArr[0]->particleSistem->*/);
	}
	void Render_fog_of_war();
	void Render_My_Tank();
	void Render_Tanks();
	void Render_Bullets();
};



#endif