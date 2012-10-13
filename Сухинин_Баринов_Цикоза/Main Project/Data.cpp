//����� ���� ������� 3081/4

#include "Data.h"


Data::Data(HGE * hge)
{
	this->weapons= list <Weapon*>();
	//���(��� ����),�����,������ ������,�������� ������,���
	Weapon * w= new Weapon("Gunnar1",10,2000,10,1);
	this->weapons.push_back(w);
	w= new Weapon("Lazar1",100,2000,50,2);
	this->weapons.push_back(w);


	this->tanks =  list<Tank*>();
	list <Tank*>::iterator t;
	this->tanks.push_back(new Tank("Player1",	//������,
		hgeVector(1000,500),					//�������
		0.05,									//����������� ���������
		1.5,									//���� ��������� ��������
		0.04,									//���� ������� ��������
		0xFFFFA000));							//���� ����� rgb	
	t=this->tanks.begin();
	(*t)->CopyWeaponList(this->weapons);
	list <Weapon*>::iterator i=this->weapons.begin();
	(*t)->SetWeapon_left(*i);i++;
	(*t)->SetWeapon_right(*i);

	this->tanks.push_back(new Tank("Player2",	//������,
		hgeVector(1000,700),					//�������
		0.05,									//����������� ���������
		1.5,									//���� ��������� ��������
		0.04,									//���� ������� ��������
		0xFFFF0000));									
	t=this->tanks.begin();
	(*t)->CopyWeaponList(this->weapons);
	i=this->weapons.begin();
	(*t)->SetWeapon_left(*i);i++;
	(*t)->SetWeapon_right(*i);

	//������� �����
	tilemap = new HGETileMap(hge, 0, 0, 50, 50);
	//tilemap = new HGETileMap(50, 50);
	tilemap->Init();
	tilemap->LoadMap("res/test.map");
	
	this->My_tank=*(this->tanks.begin());//��� ��������

};
//������
void Data::Free()
{
	delete this->tilemap;
	this->renderdat->Free();
	delete this->renderdat;
	
	for(list<Bullet*>::iterator it=this->bullets.begin();it!=this->bullets.end();it++)
		delete *it;
	this->bullets.clear();
	for(list<Tank*>::iterator it=this->tanks.begin();it!=this->tanks.end();it++)
		delete *it;
	this->tanks.clear();
	for(list<Weapon*>::iterator it=this->weapons.begin();it!=this->weapons.end();it++)
		delete *it;
	this->weapons.clear();

}