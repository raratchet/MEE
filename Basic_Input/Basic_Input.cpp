#include "Basic_Input.h"
#include <MEE_Inputs.h>

namespace Basic_Input
{
	void OnInit(int pl_id)
	{
		//MEE_bind_keyboard_keyIsPressed(pl_id, "");
		//MEE_bind_keyboard_keyPressedThisFrame(pl_id, "");
		//MEE_bind_keyboard_keyUp(pl_id, "");

		//MEE_bind_mouse_keyUp(pl_id, "");
		//MEE_bind_mouse_keyIsPressed(pl_id, "");
		//MEE_bind_mouse_keyPressedThisFrame(pl_id, "");
		MEE_bind_mouse_GetPosition(pl_id, "mousePosition");
	}
	void OnLoad()
	{

	}
	void OnShutDown()
	{

	}
	 
	void OnUpdate()
	{
		clear();
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYDOWN) {
				keyboardInput(event.key.keysym.sym, 0);
			}
			else if (event.type == SDL_KEYUP)
			{
				keyboardInput(event.key.keysym.sym, 1);
			}
			if (event.type == SDL_MOUSEMOTION) {
				mouseInput(event.motion.x, event.motion.y, event.button.button, 0);
			}
			else if (event.type == SDL_MOUSEBUTTONDOWN) {
				mouseInput(event.motion.x, event.motion.y, event.button.button, 1);
			}
			else if (event.type == SDL_MOUSEBUTTONUP) {
				mouseInput(event.motion.x, event.motion.y, event.button.button, 2);
			}
		}
	}

	void mousePosition(int* x, int* y)
	{
		*x = mouse_PosX;
		*y = mouse_PosY;
	}

	void clear()
	{
		OldKeyDown.clear();
		OldKeyDown = KeyDown;
		KeyDown.clear();
		KeyPressed.clear();
		KeyUp.clear();
	}

	void keyboardInput(int key, int state)
	{
		if (state == 0)
			addKeyDown(key);
		else
			addKeyUp(key);
	}

	void controllerInput(int button, int state)
	{
	}

	void mouseInput(int x, int y, int button, int state)
	{
		setMouse(x, y);
	}

	void addKeyDown(int key)
	{
		if (OldKeyDown.find(key) != OldKeyDown.end())
			KeyPressed.insert(key);
		else
			KeyDown.insert(key);
	}

	void addKeyUp(int key)
	{
		KeyUp.insert(key);
	}

	void setMouse(int x, int y)
	{
		mouse_PosX = x;
		mouse_PosY = y;
	}
}