//Автор Дима Баринов 3081/4


#include "RenderData.h"
//загружает все спрайты
bool RenderData::LoadAll()
{
	HGE * hge=hgeCreate(HGE_VERSION);
	this->tex=LoadTex(hge,"res/model1.jpg");
	if (!this->tex)return false;
	if (!LoadSprite(new SpriteClass(0,"Sprite_Tank_Player_body",new hgeSprite(tex, 0, 0, 128, 128))))return false;//0
	//this->Arr[0]->sprite->SetColor(0xFFFFA000);
	this->Arr[0]->sprite->SetHotSpot(64,64);
	this->Arr[0]->sprite->SetZ(0.5);
	this->Arr[0]->sprite->SetBlendMode(BLEND_ZWRITE);
	if (!LoadSprite(new SpriteClass(1,"Sprite_Tank_Player_Turret",new hgeSprite(tex, 128, 0, 64, 64))))return false;//1
	//this->Arr[1]->sprite->SetColor(0xFFFFA000);
	this->Arr[1]->sprite->SetHotSpot(32,32);
	this->Arr[1]->sprite->SetZ(0.5);
	this->Arr[1]->sprite->SetBlendMode(BLEND_ZWRITE);
	tex=LoadTex(hge,"res/fog.png");
	if (!this->tex)return false;
	if (!LoadSprite(new SpriteClass(2,"Sprite_fog",new hgeSprite(tex, 0, 0, 16, 16))))return false;//2
	tex=LoadTex(hge,"res/bullets.jpg");
	if (!this->tex)return false;
	this->Arr[2]->sprite->SetHotSpot(128,128);
	this->Arr[2]->sprite->SetZ(0.1);
	this->Arr[2]->sprite->SetBlendMode(BLEND_ZWRITE);

	if (!LoadSprite(new SpriteClass(3,"Sprite_Bullet_Gunnar1",new hgeSprite(tex, 0, 0, 16, 16))))return false;//3
	//this->Arr[2]->sprite->SetColor(0xFFFFA000);
	this->Arr[3]->sprite->SetHotSpot(8,8);
	this->Arr[3]->sprite->SetZ(0.5);
	this->Arr[3]->sprite->SetBlendMode(BLEND_ALPHAADD  | BLEND_ZWRITE);
	if (!LoadParticle(new ParticleClass(0,"Plasma",new hgeParticleSystem("res/Plasma.psi",Arr[3]->sprite))))return false;//0
	//this->ParticleArr[0]->particleSistem->SetScale(1.0);
	if (!LoadParticle(new ParticleClass(1,"Lazar",new hgeParticleSystem("res/Lazar_2.psi",Arr[3]->sprite))))return false;//1
	//this->ParticleArr[1]->particleSistem->SetScale(0.5);
	//this->ParticleArr[1]->particleSistem->info.nEmission=3000;
	
	this->fnt=new hgeFont("res/font1.fnt");
	hge->Release();
	return true;
}
//загружает единичный спрайт
bool RenderData::LoadSprite(SpriteClass *s)
{
	this->Arr[s->id]=s;
	this->count_Arr++;
	return true;
}
//загружает единичную систему частиц
bool RenderData::LoadParticle(ParticleClass * p)
{
	this->ParticleArr[p->id]=p;
	this->count_ParticleArr++;
	return true;
}
//загружает текстуру
HTEXTURE RenderData::LoadTex(HGE * hge,string name)
{
	HTEXTURE tex;
	tex=hge->Texture_Load(name.c_str());
	if(!tex)
	{
		string s="Can't load "+name;
		MessageBox(NULL, s.c_str(), "Error", MB_OK | MB_ICONERROR | MB_APPLMODAL);
	return false;
	}
	hge->Release();
	return tex;

}