#include "Basic_Input.h"
#include <MEE_Inputs.h>
#include <iostream>

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

		MEE_keyboard_KeyIsPressed = (bool(*)(int))GetKeyPressed;
		MEE_keyboard_KeyPressedThisFrame = (bool(*)(int))GetKeyDown;
		MEE_keyboard_KeyUp = (bool(*)(int))GetKeyUp;

		MEE_bind_gamepad_KeyIsPressed(pl_id, "GetControllerKeyPressed");
		MEE_bind_gamepad_KeyPressedThisFrame(pl_id, "GetControllerKeyDown");
		MEE_bind_gamepad_KeyUp(pl_id, "GetControllerKeyUp");
	}
	void OnLoad()
	{
		for (int i = 0; i < SDL_NumJoysticks(); i++)
		{
			std::cout << "Se detecta un control\n";
			joysticks.push_back(SDL_JoystickOpen(i));
		}
	}
	void OnShutdown()
	{
		for (auto joy : joysticks)
		{
			SDL_JoystickClose(joy);
		}
	}
	 
	void OnUpdate()
	{
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
			if (event.type == SDL_MOUSEMOTION) 
			{
				mouseInput(event.motion.x, event.motion.y, event.button.button, 0);
			}
			else if (event.type == SDL_MOUSEBUTTONDOWN) 
			{
				mouseInput(event.motion.x, event.motion.y, event.button.button, 1);
			}
			else if (event.type == SDL_MOUSEBUTTONUP) 
			{
				mouseInput(event.motion.x, event.motion.y, event.button.button, 2);
			}
			else if( event.type == SDL_JOYBUTTONDOWN)
			{
				controllerInput(event.jbutton.which,event.jbutton.button,0);
			}
			else if (event.type == SDL_JOYBUTTONUP)
			{
				controllerInput(event.jbutton.which, event.jbutton.button, 1);
			}
			else if (event.type == SDL_JOYAXISMOTION)
			{

			}
			else if (event.type == SDL_QUIT)
			{
				MEE_CloseApplicationSignal();
			}
		}


	}

	void OnPostUpdate()
	{
		clear();
	}

	void mousePosition(int* x, int* y)
	{
		*x = mouse_PosX;
		*y = mouse_PosY;
	}

	void clear()
	{
		KeyDown.clear();

		for (auto& C_KeyDown : ControllerKeyDown)
		{
			C_KeyDown.second.clear();
		}
	}

	void keyboardInput(int key, int state)
	{
		if (state == 0)
			addKeyDown(key);
		else
			addKeyUp(key);
	}

	void controllerInput(int controller, int key, int state)
	{
		if (state == 0)
			addControllerKeyDown(controller,key);
		else
			addControllerKeyUp(controller,key);
	}

	void mouseInput(int x, int y, int button, int state)
	{
		setMouse(x, y);
	}

	bool GetKeyDown(int key)
	{
		auto k = KeyDown.find(key);
		return k != KeyDown.end()
			? true : false;
	}

	bool GetKeyPressed(int key)
	{
		auto k = KeyPressed.find(key);
		return k != KeyPressed.end()
			? true : false;
	}

	bool GetKeyUp(int key)
	{
		auto k = KeyUp.find(key);
		return k != KeyUp.end()
			? true : false;
	}

	bool GetControllerKeyDown(int controller, int key)
	{
		auto& KeyDown = ControllerKeyDown[controller];

		auto k = KeyDown.find(key);

		return k != KeyDown.end()
			? true : false;
	}

	bool GetControllerKeyPressed(int controller, int key)
	{
		auto& KeyPressed = ControllerKeyPressed[controller];

		auto k = KeyPressed.find(key);

		return k != KeyPressed.end()
			? true : false;
	}

	bool GetControllerKeyUp(int controller, int key)
	{
		auto& KeyUp = ControllerKeyUp[controller];

		auto k = KeyUp.find(key);

		return k != KeyUp.end()
			? true : false;
	}

	void addKeyDown(int key)
	{

		auto alreadyDown = KeyDown.find(key);
		auto alreadyPressed = KeyPressed.find(key);

		if (alreadyDown == KeyDown.end()
			&& alreadyPressed == KeyPressed.end())
		{
			KeyDown.insert(key);
			KeyPressed.insert(key);
		}
	}

	void addKeyUp(int key)
	{
		KeyUp.insert(key);
		KeyPressed.erase(key);
	}

	void addControllerKeyDown(int controller, int key)
	{
		auto& KeyDown = ControllerKeyDown[controller];
		auto& KeyPressed = ControllerKeyPressed[controller];

		auto alreadyDown = KeyDown.find(key);
		auto alreadyPressed = KeyPressed.find(key);

		if (alreadyDown == KeyDown.end()
			&& alreadyPressed == KeyPressed.end())
		{
			std::cout << "Se presiona " << key << std::endl;
			KeyDown.insert(key);
			KeyPressed.insert(key);
		}
	}

	void addControllerKeyUp(int controller, int key)
	{
		auto& KeyUp = ControllerKeyUp[controller];
		auto& KeyPressed = ControllerKeyPressed[controller];

		KeyUp.insert(key);
		KeyPressed.erase(key);
	}

	void setMouse(int x, int y)
	{
		mouse_PosX = x;
		mouse_PosY = y;
	}
}