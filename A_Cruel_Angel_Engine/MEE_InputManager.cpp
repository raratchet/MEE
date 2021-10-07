#include <iostream>
#include "MEE_InputManager.h"
#include "MEE_Inputs.h"

namespace MEE
{
#define GAMEPAD_SUPPORTED if(!InputManager::gamepad_supported){\
						  std::cout << "[MEE] Gamepad not supported \n"; return false; }

	bool InputManager::Init()
	{
		//This function checks if all essential input bindings are correctrly set
		// Essential are keyboard and mouse
		bool success = true;

		bool essentials_set =
			MEE_mouse_GetPosition && MEE_mouse_KeyIsPressed && MEE_mouse_KeyPressedThisFrame &&
			MEE_mouse_KeyUp && MEE_keyboard_KeyIsPressed && MEE_keyboard_KeyPressedThisFrame &&
			MEE_keyboard_KeyUp;

		gamepad_supported =
			MEE_gamepad_GetJoystick && MEE_gamepad_KeyIsPressed && MEE_gamepad_KeyPressedThisFrame &&
			MEE_gamepad_KeyUp;

		gamepad_rumble_supported = MEE_gamepad_MakeRumble && true;

		success = essentials_set;

		return success;
	}
	bool InputManager::GetKeyDown(int key)
	{
		return MEE_keyboard_KeyPressedThisFrame(key);
	}
	bool InputManager::GetKeyPressed(int key)
	{
		return MEE_keyboard_KeyIsPressed(key);
	}
	bool InputManager::GetKeyUp(int key)
	{
		return MEE_keyboard_KeyUp(key);
	}

	bool InputManager::GetMouseKeyDown(int key)
	{
		return MEE_mouse_KeyPressedThisFrame(key);
	}
	bool InputManager::GetMouseKeyPressed(int key)
	{
		return MEE_mouse_KeyIsPressed(key);
	}
	bool InputManager::GetMouseKeyUp(int key)
	{
		return MEE_mouse_KeyUp(key);
	}

	bool InputManager::GetControllerKeyDown(int id, int key)
	{
		GAMEPAD_SUPPORTED
		return MEE_gamepad_KeyPressedThisFrame(id,key);
	}
	bool InputManager::GetControllerKeyPressed(int id, int key)
	{
		GAMEPAD_SUPPORTED
		return MEE_gamepad_KeyIsPressed(id,key);
	}
	bool InputManager::GetControllerKeyUp(int id, int key)
	{
		GAMEPAD_SUPPORTED
		return MEE_gamepad_KeyUp(id,key);
	}
	Vector2 InputManager::GetMouse()
	{
		static Vector2 mouse;
		int x, y;
		MEE_mouse_GetPosition(&x,&y);
		mouse.x = x;
		mouse.y = y;
		return mouse;
	}
}
