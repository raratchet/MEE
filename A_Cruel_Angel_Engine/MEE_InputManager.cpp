#include <iostream>
#include "MEE_InputManager.h"
#include "MEE_Inputs.h"

namespace MEE
{
#define GAMEPAD_SUPPORTED if(!InputManager::gamepad_supported){\
						  std::cout << "[MEE] Gamepad not supported \n"; return false; }

#define MEE_CHECK_FUNCTION(FUNCTION)\
try\
{\
    FUNCTION\
}\
catch(...)\
{\
    std::cout << "[MEE] An error ocurred while calling a function in MEE_INPUT" << std::endl;\
}


	InputManager::~InputManager()
	{
		MEE_mouse_GetPosition = nullptr;
		MEE_mouse_KeyIsPressed = nullptr;
		MEE_mouse_KeyPressedThisFrame = nullptr;
		MEE_mouse_KeyUp = nullptr;

		MEE_keyboard_KeyIsPressed = nullptr;
		MEE_keyboard_KeyPressedThisFrame = nullptr;
		MEE_keyboard_KeyUp = nullptr;

		MEE_gamepad_GetJoystick = nullptr;
		MEE_gamepad_KeyIsPressed = nullptr;
		MEE_gamepad_KeyPressedThisFrame = nullptr;
		MEE_gamepad_KeyUp = nullptr;
		MEE_gamepad_MakeRumble = nullptr;
	}

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
			MEE_gamepad_KeyIsPressed && MEE_gamepad_KeyPressedThisFrame &&
			MEE_gamepad_KeyUp;

		gamepad_rumble_supported = MEE_gamepad_MakeRumble && true;

		success = essentials_set;

		return success;
	}
	bool InputManager::GetKeyDown(int key)
	{
		bool value = false;
		MEE_CHECK_FUNCTION(value = MEE_keyboard_KeyPressedThisFrame(key);)
		return value;
	}
	bool InputManager::GetKeyPressed(int key)
	{
		bool value = false;
		MEE_CHECK_FUNCTION(value = MEE_keyboard_KeyIsPressed(key);)
		return value;
	}
	bool InputManager::GetKeyUp(int key)
	{
		bool value = false;
		MEE_CHECK_FUNCTION(value = MEE_keyboard_KeyUp(key);)
		return value;
	}

	bool InputManager::GetMouseKeyDown(int key)
	{
		bool value = false;
		MEE_CHECK_FUNCTION(value = MEE_mouse_KeyPressedThisFrame(key);)
		return value;
	}
	bool InputManager::GetMouseKeyPressed(int key)
	{
		bool value = false;
		MEE_CHECK_FUNCTION(value = MEE_mouse_KeyIsPressed(key);)
		return value;
	}
	bool InputManager::GetMouseKeyUp(int key)
	{
		bool value = false;
		MEE_CHECK_FUNCTION(value = MEE_mouse_KeyUp(key);)
		return value;
	}

	bool InputManager::GetControllerKeyDown(int id, int key)
	{
		GAMEPAD_SUPPORTED
		bool value = false;
		MEE_CHECK_FUNCTION(value = MEE_gamepad_KeyPressedThisFrame(id,key);)
		return value;
	}
	bool InputManager::GetControllerKeyPressed(int id, int key)
	{
		GAMEPAD_SUPPORTED
		bool value = false;
		MEE_CHECK_FUNCTION(value = MEE_gamepad_KeyIsPressed(id, key);)
		return value;
	}
	bool InputManager::GetControllerKeyUp(int id, int key)
	{
		GAMEPAD_SUPPORTED
		bool value = false;
		MEE_CHECK_FUNCTION(value = MEE_gamepad_KeyUp(id, key);)
		return value;
	}
	Vector2 InputManager::GetMouse()
	{
		static Vector2 mouse;
		int x, y;
		MEE_CHECK_FUNCTION(MEE_mouse_GetPosition(&x,&y);)
		mouse.x = x;
		mouse.y = y;
		return mouse;
	}
}
