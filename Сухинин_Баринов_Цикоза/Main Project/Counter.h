#ifndef _HANDLER_
#define _HANDLER_

#include "Data.h"
#include "Tank.h"
#include "include\hge\hgevector.h"
#include <boost\thread.hpp>
#include <boost\timer.hpp>
using namespace boost;

class Counter
{
private:
	thread thread_handler;
	mutex //разрешения
		mut_Handler;
	bool Handler_stop;
public: 
	Data * data;
	

	Counter(Data * data)
	{
		mut_Data.lock();
		this->data=data;
		mut_Data.unlock();
		this->Handler_stop=false;
	}
	void Start()//запуск потоков
	{
		thread_handler = thread(&Counter::HandlerLoop,this,5);
	}
	void Stop()//остановка потоков
	{
		mut_Handler.lock();
		this->Handler_stop=true;
		mut_Handler.unlock();
		thread_handler.join();
	}
	void HandlerLoop(float ms)
	{
		bool stop=false;
		timer t;
		
		while (!stop)
		{
			t.restart();
			mut_Handler.lock();
			stop= this->Handler_stop;
			mut_Handler.unlock();
			//to do here/////
			mut_Data.lock();
			Tank * tank = this->data->My_tank;

			hgeVector oldPosition = tank->position;
			double oldAngle = tank->angle_tank;

			tank->angle_tank+=tank->direction_angle*tank->speed_angle*(float)(ms/10.0);

			//double dturret = (tank->angle_turret_prefer-tank->angle_turret);
			//tank->angle_turret_speed=0.002;
			//if (dturret>tank->angle_turret_speed) { tank->angle_turret+=tank->angle_turret_speed; }
			//else if (dturret<tank->angle_turret_speed) { tank->angle_turret+=tank->angle_turret_speed; }
			//else 
				tank->angle_turret=tank->angle_turret_prefer;

			if (tank->direction_front!=0)
			{
				tank->speed-=tank->direction_front*tank->acceleration*(float)(ms/10.0);
				if (tank->speed>tank->speed_front_limit) tank->speed=tank->speed_front_limit*(float)(ms/10.0);
				if (tank->speed<-tank->speed_front_limit) tank->speed=-tank->speed_front_limit*(float)(ms/10.0);
			}
			else 
			{
				if (tank->speed>tank->acceleration) tank->speed-=tank->acceleration*(float)(ms/10.0);
				else if (tank->speed<-tank->acceleration) tank->speed+=tank->acceleration*(float)(ms/10.0);
				else tank->speed=0;
			}

			//перемещение
			hgeVector v_speed = hgeVector(tank->speed,0);
			v_speed.Rotate(tank->angle_tank);
			tank->position+=v_speed*(float)(ms/10.0);

			//плохой грубый вариант коллизии, возврат в предидущее состояние если коллизия, 
			int w=20;  int h=10; //предположительное расстояние от центра танка до его правой верхней границы
			hgeVector lt = hgeVector(-w,h); //left top угол (левый верхний) танка                 четыре точки границы танка
			hgeVector rt = hgeVector(w,h); //right top
			hgeVector lb = hgeVector(-w,-h); // left bottom
			hgeVector rb = hgeVector(w,-h); //right bottom

			lt.Rotate(tank->angle_tank); //разворот опорных точек танка
			rt.Rotate(tank->angle_tank);
			lb.Rotate(tank->angle_tank);
			rb.Rotate(tank->angle_tank);



			lt+=tank->position; //добавлени глобальных координат
			rt+=tank->position;
			lb+=tank->position;
			rb+=tank->position;

			if (data->tilemap->PointCollide(lt.x,lt.y) //проверка коллизии опорных точек
				|| data->tilemap->PointCollide(rt.x,rt.y)
				|| data->tilemap->PointCollide(lb.x,lb.y)
				|| data->tilemap->PointCollide(rb.x,rb.y))
			 {
				 tank->position=oldPosition; //возврат в предидущее состояние
				 tank->angle_tank=oldAngle;
				 tank->speed=0;		//сброс скорости (столкновение)
			}


			if (tank->weapon_left->ready<0) tank->weapon_left->ready+=(float)(ms/10.0);
			if (tank->weapon_right->ready<0) tank->weapon_right->ready+=(float)(ms/10.0);

			//обработка пуль
			if (!data->bullets.empty())
			{
				list<Bullet*>::iterator it;
				for (it= this->data->bullets.begin();it!=this->data->bullets.end();)
				{
					switch((*it)->lifecircle)
					{
					case CanRemove:
						it=data->bullets.erase(it);
						if (data->bullets.empty()) it=this->data->bullets.end();
						break;
					case Unused:it++;
						break;
					case Life:
						if ((*it)->range>0) 
						{
							if (data->tilemap->PointCollide((*it)->position.x,(*it)->position.y)) 
							{
								//(*it)->range=-50;
								(*it)->lifecircle=Unused;
							

							}
							else
							{

								(*it)->position+=(*it)->speed*(float)(ms/10.0); 
								//t_bull.restart();
								(*it)->range-=(*it)->speed.Length()*(float)(ms/10.0);
							}
						
						} 
					else 
						{
							(*it)->lifecircle=Unused;
						
						}
						it++;
						break;
					default:
						break;

					}
				}
			}
			mut_Data.unlock();
			//end to do
			double dt=ms-t.elapsed();
			if (dt>0)
			Sleep(dt);
		}

	}
};


#endif