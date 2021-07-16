#pragma once
#include <memory>
#include <iostream>
#include "MEG_Exports.h"
#include "MEG_Aliases.h"

class MEG_IMPORT Input
{
public:
	static struct MEG_IMPORT Keyboard
	{
		static bool KeyWasPressedThisFrame(int key);
		static bool KeyIsPressed(int key);
		static bool KeyUp(int key);
	};

	static struct MEG_IMPORT Mouse
	{
		static Vector2 MousePosition();
		static bool KeyWasPressedThisFrame(int key);
		static bool KeyIsPressed(int key);
		static bool KeyUp(int key);
	};
private:

};

