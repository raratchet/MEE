#include "MEE_InputManager.h"
#include "MEE_Inputs.h"

namespace MEE
{
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
		return MEE_gamepad_KeyPressedThisFrame(id,key);
	}
	bool InputManager::GetControllerKeyPressed(int id, int key)
	{
		return MEE_gamepad_KeyIsPressed(id,key);
	}
	bool InputManager::GetControllerKeyUp(int id, int key)
	{
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
