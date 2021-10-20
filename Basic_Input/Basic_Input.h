#pragma once
#include<MEE_PluginHeader.h>
#include<set>
#include<map>
#include<list>
#include<SDL.h>

namespace Basic_Input
{
	PLUGIN_FUNCTION void OnInit(int);
	PLUGIN_FUNCTION void OnLoad();
	PLUGIN_FUNCTION void OnShutdown();
	PLUGIN_FUNCTION void OnUpdate();
	PLUGIN_FUNCTION void OnPostUpdate();


	PLUGIN_FUNCTION void mousePosition(int*, int*);

	PLUGIN_FUNCTION bool GetKeyDown(int key);
	PLUGIN_FUNCTION bool GetKeyPressed(int key);
	PLUGIN_FUNCTION bool GetKeyUp(int key);

	PLUGIN_FUNCTION bool GetMouseKeyDown(int key);
	PLUGIN_FUNCTION bool GetMouseKeyPressed(int key);
	PLUGIN_FUNCTION bool GetMouseKeyUp(int key);

	PLUGIN_FUNCTION bool GetControllerKeyDown(int controller, int key);
	PLUGIN_FUNCTION bool GetControllerKeyPressed(int controller, int key);
	PLUGIN_FUNCTION bool GetControllerKeyUp(int controller, int key);

	void clear();
	void keyboardInput(int key, int state);
	void controllerInput(int controller, int button, int state);
	void mouseInput(int x, int y, int button, int state);
	void addKeyDown(int key);
	void addKeyUp(int key);
	void addMouseKeyDown(int key);
	void addMouseKeyUp(int key);
	void addControllerKeyDown(int cotroller,int key);
	void addControllerKeyUp(int controller, int key);
	void setMouse(int x,int y);


	inline std::list<SDL_Joystick*> joysticks;

	inline std::set<int> KeyDown;
	inline std::set<int> KeyPressed;
	inline std::set<int> KeyUp;

	inline std::set<int> MouseKeyDown;
	inline std::set<int> MouseKeyPressed;
	inline std::set<int> MouseKeyUp;

	inline std::map<int, std::set<int>>ControllerKeyDown;
	inline std::map<int, std::set<int>>ControllerKeyPressed;
	inline std::map<int, std::set<int>>ControllerKeyUp;

	inline int mouse_PosX, mouse_PosY;

}
