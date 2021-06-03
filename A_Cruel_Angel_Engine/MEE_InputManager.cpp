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
