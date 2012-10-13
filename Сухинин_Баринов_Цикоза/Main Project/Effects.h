//����� ���� ������� 3081/4
#ifndef _EFFECTS_
#define _EFFECTS_

#include "include\hge\hge.h"
#include "include\hge\hgevector.h"
#include "include\hge\hgeparticle.h"
#include "Bullet.h"
//������������� ����������� ���������� 
class Effects
{
public:
	hgeVector position;
	LifeCircle lifecircle;
	Effects(hgeVector position){this->position=position;this->lifecircle=Life;}
	virtual void UpdatePos(hgeVector,hgeVector)=0;
	virtual void Update(float)=0;
	virtual void Render()=0;
	virtual bool CanDel()=0;
	virtual void SetRemoveFlag()=0;
};


class Ef_Bullet : public Effects
{
public:
	/////////////////////////////////
	hgeParticleSystem * particle;//for beautiful render effects
	/////////////////////////////////
	Bullet * ps;
	Ef_Bullet(hgeParticleSystem * particle,hgeVector position,hgeVector TileOffset,Bullet * ps):Effects(position)
	{
		this->ps=ps;
		this->particle=particle;
		this->particle->FireAt(position.x,position.y);//������� � ���������� �����������
		this->particle->Transpose(-TileOffset.x,-TileOffset.y);//�������� � ��������� ������ (������)
	}
	void UpdatePos(hgeVector TileDelta,hgeVector tankpos)
	{
		
		if (this->ps->lifecircle==Life)//���� ���� ����
		{
			this->position=ps->position;
			this->particle->MoveTo(this->position.x,this->position.y,false);
		}
		else if (this->lifecircle==Life)//���� ���� ������, �� ������� ������ ��� ���� ���
		{
			this->particle->Stop();
			this->lifecircle=Unused;
		}
		this->particle->Transpose(-TileDelta.x,-TileDelta.y);//��������
	}
	void Update(float dt){this->particle->Update(dt);}//��������� ��������� ������� ������
	void Render(){this->particle->Render();}
	bool CanDel()//��������� �� ����������� ��������
	{
		if (this->particle->GetParticlesAlive()==0) {this->lifecircle=CanRemove; return true;}
		return false;
	}
	void SetRemoveFlag(){this->ps->lifecircle=CanRemove;}//������������� ���� ��� ��������, ��� ������� ��� ������� ������ ��� �� ��������� � ���
};




#endif