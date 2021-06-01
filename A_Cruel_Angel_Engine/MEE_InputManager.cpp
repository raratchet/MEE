#include "MEE_InputManager.h"
#include "MEE_Inputs.h"

namespace MEE
{
	bool InputManager::GetKeyDown(int key)
	{
		return MEE_keyboard_keyPressedThisFrame(key);
	}
	bool InputManager::GetKeyPressed(int key)
	{
		return MEE_keyboard_keyIsPressed(key);
	}
	bool InputManager::GetKeyUp(int key)
	{
		return MEE_keyboard_keyUp(key);
	}
	Vector2 InputManager::GetMouse()
	{
		static Vector2 mouse;
		int x, y;
		MEE_mouse_position(&x,&y);
		mouse.x = x;
		mouse.y = y;
		return mouse;
	}
}
