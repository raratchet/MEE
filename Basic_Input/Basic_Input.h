#pragma once
#include<MEE_PluginHeader.h>
#include<set>
#include<SDL.h>

namespace Basic_Input
{
	extern "C"
	{
		PLUGIN_EXPORT void onInit(int);
		PLUGIN_EXPORT void onLoad();
		PLUGIN_EXPORT void onShutDown();
		PLUGIN_EXPORT void onUpdate();


		PLUGIN_EXPORT void mousePosition(int*,int*);

	}

	void clear();
	void keyboardInput(int key, int state);
	void controllerInput(int button, int state);
	void mouseInput(int x, int y, int button, int state);
	void addKeyDown(int key);
	void addKeyUp(int key);
	void setMouse(int x,int y);

	std::set<int> KeyDown;
	std::set<int> KeyPressed;
	std::set<int> KeyUp;
	std::set<int> OldKeyDown;
	int mouse_PosX, mouse_PosY;

}
