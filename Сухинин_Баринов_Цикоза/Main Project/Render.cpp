//Автор Дима Баринов 3081/4
#include "Render.h"


bool Render::Load()
{	
	return this->data->renderdat->LoadAll();;
}

void Render::Render_My_Tank()
{
	//нулевой спрайт  -  шасси
	//первый - башня
	this->data->renderdat->GetSprite(0)->RenderEx(this->My_tank->position.x-this->data->tilemap->GetOffset_x(), this->My_tank->position.y-this->data->tilemap->GetOffset_y(), this->My_tank->angle_tank-M_PI_2,0.5);
	this->data->renderdat->GetSprite(1)->RenderEx(this->My_tank->position.x-this->data->tilemap->GetOffset_x(), this->My_tank->position.y-this->data->tilemap->GetOffset_y(), this->My_tank->angle_turret-M_PI_2,0.5);
	
}
void Render::Render_Tanks()
{
	if (this->data->tanks.empty()) return;
	list <Tank*>::iterator it=this->data->tanks.begin();
	while(it!=this->data->tanks.end())
	{
		this->data->renderdat->GetSprite(0)->SetColor((*it)->color);
		this->data->renderdat->GetSprite(1)->SetColor((*it)->color);
		this->data->renderdat->GetSprite(0)->RenderEx((*it)->position.x-this->data->tilemap->GetOffset_x(), (*it)->position.y-this->data->tilemap->GetOffset_y(), (*it)->angle_tank-M_PI_2,0.5);
		this->data->renderdat->GetSprite(1)->RenderEx((*it)->position.x-this->data->tilemap->GetOffset_x(), (*it)->position.y-this->data->tilemap->GetOffset_y(), (*it)->angle_turret-M_PI_2,0.5);
		it++;
	}

	//this->data->renderdat->GetSprite(0)->RenderEx();
	//this->data->renderdat->GetSprite(1)->RenderEx();
}
void Render::Render_Bullets()
{
	if (this->data->renderdat->ef.empty())return;
	list <Bullet*>::iterator it;
	list <Effects*>::iterator ite;
	for (ite= this->data->renderdat->ef.begin();ite != this->data->renderdat->ef.end();)
	{
		switch((*ite)->lifecircle)
			{
				case CanRemove:
					delete *ite;
					ite=this->data->renderdat->ef.erase(ite);
					if (this->data->renderdat->ef.empty()) ite=this->data->renderdat->ef.begin();
					break;
				case Unused:
					if ((*ite)->CanDel())
					{
						(*ite)->SetRemoveFlag();
					}
					(*ite)->UpdatePos(hgeVector(this->data->tilemap->GetOffset_x(),this->data->tilemap->GetOffset_y()),this->My_tank->position);
					(*ite)->Update(hge->Timer_GetDelta());
					(*ite)->Render();
					ite++;
					break;
				case Life:
					(*ite)->UpdatePos(hgeVector(this->data->tilemap->GetOffset_x(),this->data->tilemap->GetOffset_y()),this->My_tank->position);
					(*ite)->Update(hge->Timer_GetDelta());
					(*ite)->Render();
					ite++;
					break;
			}
		
	}

	

}
void Render::Render_fog_of_war()
{

}
void Render::Free()
{
	//	пока пусто
}