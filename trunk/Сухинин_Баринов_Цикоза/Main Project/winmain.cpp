

//#include "Global.h"
//#include "Resource.h"
#define _WINSOCKAPI_    // stops windows.h including winsock.h
#include "Data.h"
#include "Control.h"
#include "Render.h"
#include "Counter.h"
#include "Client.h"
//#include "Server.h"
#include <boost\timer.hpp>





HGE *hge=0;


//Properties *prop;
Data *data;						//класс данных
Control *control;				//класс обработчик действий пользователя
Render *render;					//класс рисовальщика
Counter *handler;				//класс обработчика данных (сервер)
Client *client;
int SCREEN_WIDTH =800;
int SCREEN_HEIGHT =600;

//вызывается каждый фрейм: слушаем входные комманды пользователя, 
//вычисляем новые данные (по-хорошему -  в отдельный поток)
bool FrameFunc()
{
	mut_Data.lock();//работает с класом Data, поэтом используем мьютекс
	bool b=control->Detect_input((SCREEN_WIDTH/2),(SCREEN_HEIGHT/2));
	mut_Data.unlock();
	return b;
}
//рисуем все на экран
bool RenderFunc()
{
	
	hge->Gfx_BeginScene();
	hge->Gfx_Clear(0);
	mut_Data.lock();
	data->tilemap->Render();//рисуем карту
	//data->tilemap->Render_with_fof(data->My_tank->position,data->My_tank->r1,data->My_tank->r2);
	render->Render_info(control);//выводим данные //debug
	render->Render_Tanks();//рисуем танки
	render->Render_Bullets();//рисуем все пули
	data->tilemap->RenderFG();
	mut_Data.unlock();
	hge->Gfx_EndScene();

	// RenderFunc should always return false
	return false;
}
//инициализация
bool Init()
{

	//prop= new Properties(hge);
	//hgeResourceManager* res;
	//res= new hgeResourceManager("res/resource.res");

	data= new Data(hge);

	handler= new Counter(data);
	control=new Control(hge,data);
	control->mouse_x=SCREEN_WIDTH/2;
	control->mouse_y=SCREEN_HEIGHT/2;
	//client = new Client();
	//client->Init();
	//client->Connect("");
	//client->SendPacket(client->p_server,(void*)"test",strlen ("test") + 1,
	//	ENET_PACKET_FLAG_RELIABLE);
	//client->Disconnect();
	//return false;
    render=new Render(hge,data,control);
	if (!render->Load())return false;
	
	handler->Start();

	return true;
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// Get HGE interface
	hge = hgeCreate(HGE_VERSION);
	SCREEN_WIDTH=GetSystemMetrics(SM_CXSCREEN);
	SCREEN_HEIGHT=GetSystemMetrics(SM_CYSCREEN);
	// Set up log file, frame function, render function and window title
	//hge->System_SetState(HGE_LOGFILE, "hge_tanks.log");
	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);
	hge->System_SetState(HGE_RENDERFUNC, RenderFunc);
	//hge->System_SetState(HGE_TITLE, "hge_tanks");

	hge->System_SetState(HGE_HIDEMOUSE, false);
	//hge->Resource_AttachPack("res.zip"); 
	//hge->System_SetState(HGE_INIFILE, "res/properties.ini");

	// Set up video mode
	hge->System_SetState(HGE_WINDOWED, true);
	hge->System_SetState(HGE_SCREENWIDTH, SCREEN_WIDTH);
	hge->System_SetState(HGE_SCREENHEIGHT, SCREEN_HEIGHT);
	hge->System_SetState(HGE_SCREENBPP, 32);
	//hge->System_SetState(HGE_FPS, 200); 
	hge->System_SetState(HGE_USESOUND, false);

	if(hge->System_Initiate() && Init())
	{
		// Let's rock now!
		hge->System_Start();

	}
	else MessageBox(NULL, hge->System_GetErrorMessage(), "Error", MB_OK | MB_ICONERROR | MB_SYSTEMMODAL);

	handler->Stop();
	render->Free();
	data->Free();
	hge->System_Shutdown();
	hge->Release();
	return 0;
}
