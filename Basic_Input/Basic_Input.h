#pragma once
#include<MEE_PluginHeader.h>
#include<set>
#include<SDL.h>

namespace Basic_Input
{
	extern "C"
	{
		PLUGIN_EXPORT void OnInit(int);
		PLUGIN_EXPORT void OnLoad();
		PLUGIN_EXPORT void OnShutDown();
		PLUGIN_EXPORT void OnUpdate();
		PLUGIN_EXPORT void OnPostUpdate();


		PLUGIN_EXPORT void mousePosition(int*,int*);

	}

	void clear();
	void keyboardInput(int key, int state);
	void controllerInput(int button, int state);
	void mouseInput(int x, int y, int button, int state);
	void addKeyDown(int key);
	void addKeyUp(int key);
	void setMouse(int x,int y);

	bool GetKeyDown(int key);

	bool GetKeyPressed(int key);

	bool GetKeyUp(int key);


	inline std::set<int> KeyDown;
	inline std::set<int> KeyPressed;
	inline std::set<int> KeyUp;
	inline std::set<int> OldKeyDown;
	inline int mouse_PosX, mouse_PosY;

}
