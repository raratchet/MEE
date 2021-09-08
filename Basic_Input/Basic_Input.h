#pragma once
#include<MEE_PluginHeader.h>
#include<set>
#include<map>
#include<list>
#include<SDL.h>

namespace Basic_Input
{
	extern "C"
	{
		PLUGIN_EXPORT void OnInit(int);
		PLUGIN_EXPORT void OnLoad();
		PLUGIN_EXPORT void OnShutdown();
		PLUGIN_EXPORT void OnUpdate();
		PLUGIN_EXPORT void OnPostUpdate();


		PLUGIN_EXPORT void mousePosition(int*,int*);

		PLUGIN_EXPORT bool GetKeyDown(int key);
		PLUGIN_EXPORT bool GetKeyPressed(int key);
		PLUGIN_EXPORT bool GetKeyUp(int key);

		PLUGIN_EXPORT bool GetControllerKeyDown(int controller, int key);
		PLUGIN_EXPORT bool GetControllerKeyPressed(int controller, int key);
		PLUGIN_EXPORT bool GetControllerKeyUp(int controller, int key);

	}

	void clear();
	void keyboardInput(int key, int state);
	void controllerInput(int controller, int button, int state);
	void mouseInput(int x, int y, int button, int state);
	void addKeyDown(int key);
	void addKeyUp(int key);
	void addControllerKeyDown(int cotroller,int key);
	void addControllerKeyUp(int controller, int key);
	void setMouse(int x,int y);


	inline std::list<SDL_Joystick*> joysticks;

	inline std::set<int> KeyDown;
	inline std::set<int> KeyPressed;
	inline std::set<int> KeyUp;

	inline std::map<int, std::set<int>>ControllerKeyDown;
	inline std::map<int, std::set<int>>ControllerKeyPressed;
	inline std::map<int, std::set<int>>ControllerKeyUp;

	inline int mouse_PosX, mouse_PosY;

}
