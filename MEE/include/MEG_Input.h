#pragma once
#include <memory>
#include <iostream>
#include "MEG_Exports.h"
#include "MEG_Aliases.h"

/**
 * MEG Input Simplifies the access to InputManager funtions via a singletons.
 */
class MEG_IMPORT Input
{
public:
    struct MEG_IMPORT Keyboard
	{
		static bool KeyWasPressedThisFrame(int key);
		static bool KeyIsPressed(int key);
		static bool KeyUp(int key);
	};

    struct MEG_IMPORT Controller
	{
		static bool KeyWasPressedThisFrame(GamepadID id, int key);
		static bool KeyIsPressed(GamepadID id, int key);
		static bool KeyUp(GamepadID id, int key);
	};

    struct MEG_IMPORT Mouse
	{
		static Vector2 MousePosition();
		static bool KeyWasPressedThisFrame(int key);
		static bool KeyIsPressed(int key);
		static bool KeyUp(int key);
	};
private:

};

