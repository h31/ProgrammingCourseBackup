//Автор Дима Баринов 3081/4

#include "Control.h"


bool Control::Detect_input(float x_centre,float y_centre)
{
	Tank *tank;
	
	tank = this->data->My_tank;
	if (hge->Input_GetKeyState(HGEK_ESCAPE)) return true;

	if (hge->Input_GetKeyState(HGEK_SPACE)) this->space=true;else this->space=false;

	if (hge->Input_GetKeyState(HGEK_LEFT)) this->ar_left=true;else this->ar_left=false;
	if (hge->Input_GetKeyState(HGEK_RIGHT)) this->ar_right=true;else this->ar_right=false;
	if (hge->Input_GetKeyState(HGEK_UP)) this->ar_up=true;else this->ar_up=false;
	if (hge->Input_GetKeyState(HGEK_DOWN)) this->ar_down=true;else this->ar_down=false;

	if (hge->Input_GetKeyState(HGEK_D))      tank->direction_angle=1;
	else if (hge->Input_GetKeyState(HGEK_A)) tank->direction_angle=-1; else tank->direction_angle=0;
	if (hge->Input_GetKeyState(HGEK_W))		 tank->direction_front=1;
	else if (hge->Input_GetKeyState(HGEK_S)) tank->direction_front=-1;  else tank->direction_front=0;

	if (hge->Input_GetKeyState(HGEK_LBUTTON))this->fire_weapon1=true;else this->fire_weapon1=false;
	if (hge->Input_GetKeyState(HGEK_RBUTTON))this->fire_weapon2=true;else this->fire_weapon2=false;
	this->data->tilemap->SetOffset(this->data->My_tank->position.x-x_centre,this->data->My_tank->position.y-y_centre);

	hge->Input_GetMousePos(&mouse_x,&mouse_y);
	tank->angle_turret_prefer=hgeVector((tank->position.x-this->data->tilemap->GetOffset_x()-mouse_x),(tank->position.y-this->data->tilemap->GetOffset_y()-mouse_y)).Angle();
		
	this->Tank_shoot(tank);

	return false;
}

void Control::Tank_shoot(Tank * tank)
{
	if (!this->fire_weapon1 && !this->fire_weapon2) return;
	RenderData * rend=this->data->renderdat;
	hgeParticleSystemInfo info;
	//weapon 1
	if (this->fire_weapon1 && tank->weapon_left->ready>=0)
	{
	info=rend->ParticleArr[0]->particleSistem->info;//0 - система частиц для левого орудия
	//задаем вектор полета снаряда
	hgeVector v(tank->weapon_left->startSpeed,0);//
	v.Rotate(tank->angle_turret+M_PI); //
	Bullet* b = new Bullet(tank->position,v,tank->weapon_left->type,tank->weapon_left->radius);//создаем пулю
	this->data->bullets.push_back(b);
	Effects * e = new Ef_Bullet(new hgeParticleSystem(&info),tank->position,data->tilemap->GetOffset(),b);//создаем систему частиц, связанную с пулей
	this->data->renderdat->ef.push_back(e);
	
	tank->weapon_left->ready=-tank->weapon_left->countDown;//сброс готовности(перезарядка)
	}
	//weapon 2
	if (this->fire_weapon2 && tank->weapon_right->ready>=0)
	{
	info=rend->ParticleArr[1]->particleSistem->info;
	hgeVector v(tank->weapon_right->startSpeed,0);
	v.Rotate(tank->angle_turret+M_PI); 
	Bullet* b = new Bullet(tank->position,v,tank->weapon_right->type,tank->weapon_right->radius);
	this->data->bullets.push_back(b);
	Effects * e = new Ef_Bullet(new hgeParticleSystem(&info),tank->position,data->tilemap->GetOffset(),b);
	this->data->renderdat->ef.push_back(e);	
	tank->weapon_right->ready=-tank->weapon_right->countDown;
	}
}