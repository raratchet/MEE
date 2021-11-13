#include "MEE_Inputs.h"
#include "MEE_Global.h"
#include "MEE_WindowHandler.h"
#include "MEE_Graphics.h"

//Keyboard
inline std::function<bool(int key)> MEE_keyboard_KeyPressedThisFrame;
inline std::function<bool(int key)> MEE_keyboard_KeyIsPressed;
inline std::function<bool(int key)> MEE_keyboard_KeyUp;
//Mouse
inline std::function<bool(int key)> MEE_mouse_KeyIsPressed;
inline std::function<bool(int key)> MEE_mouse_KeyUp;
inline std::function<bool(int key)> MEE_mouse_KeyPressedThisFrame;
inline std::function<void(int* x_val, int* y_val)> MEE_mouse_GetPosition;
//Gamepads
inline std::function<bool(GamepadID, int key)> MEE_gamepad_KeyPressedThisFrame;
inline std::function<bool(GamepadID, int key)> MEE_gamepad_KeyIsPressed;
inline std::function<bool(GamepadID, int key)> MEE_gamepad_KeyUp;
inline std::function<void(GamepadID, int* x_val, int* y_val)> MEE_gamepad_GetJoystick;
inline std::function<void(GamepadID, int duration)> MEE_gamepad_MakeRumble;

InputHandlerAPI MEE_EXPORT MEE_GetInputHandlerAPI()
{
	WindowHandlerAPI window = MEE::WindowHandler::GetHandlerAPI();
	InputHandlerAPI api = InputHandlerAPI::SDL;
	if (window == WindowHandlerAPI::SDL)
	{
		api = InputHandlerAPI::SDL;
	}
	else if (window == WindowHandlerAPI::GLFW)
	{
		api = InputHandlerAPI::GLFW;
	}
	return api;
}

void MEE_EXPORT MEE_CloseApplicationSignal()
{
	MEE_GLOBAL::application->CloseApplicationSignal();
}

void MEE_EXPORT MEE_bind_keyboard_KeyPressedThisFrame(int plugin_id, const char* func_name)
{
	auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

	if (pl_manager)
	{
		MEE_keyboard_KeyPressedThisFrame = pl_manager->GetPluginFunction<bool,int>(plugin_id, func_name);
	}
}

void MEE_EXPORT MEE_bind_keyboard_KeyIsPressed(int plugin_id, const char* func_name)
{
	auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

	if (pl_manager)
	{
		MEE_keyboard_KeyIsPressed = pl_manager->GetPluginFunction<bool, int>(plugin_id, func_name);
	}
}

void MEE_EXPORT MEE_bind_keyboard_KeyUp(int plugin_id, const char* func_name)
{
	auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

	if (pl_manager)
	{
		MEE_keyboard_KeyUp = pl_manager->GetPluginFunction<bool, int>(plugin_id, func_name);
	}
}

void MEE_EXPORT MEE_bind_mouse_KeyPressedThisFrame(int plugin_id, const char* func_name)
{
	auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

	if (pl_manager)
	{
		MEE_mouse_KeyPressedThisFrame = pl_manager->GetPluginFunction<bool, int>(plugin_id, func_name);
	}
}

void MEE_EXPORT MEE_bind_mouse_KeyIsPressed(int plugin_id, const char* func_name)
{
	auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

	if (pl_manager)
	{
		MEE_mouse_KeyIsPressed = pl_manager->GetPluginFunction<bool, int>(plugin_id, func_name);
	}
}

void MEE_EXPORT MEE_bind_mouse_KeyUp(int plugin_id, const char* func_name)
{
	auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

	if (pl_manager)
	{
		MEE_mouse_KeyUp = pl_manager->GetPluginFunction<bool, int>(plugin_id, func_name);
	}
}

void MEE_EXPORT MEE_bind_mouse_GetPosition(int plugin_id, const char* func_name)
{
	auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

	if (pl_manager)
	{
		MEE_mouse_GetPosition = pl_manager->GetPluginFunction<void,int*,int*>(plugin_id, func_name);
	}
}

void MEE_EXPORT MEE_bind_gamepad_KeyPressedThisFrame(int plugin_id, const char* func_name)
{
	auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

	if (pl_manager)
	{
		MEE_gamepad_KeyPressedThisFrame = pl_manager->GetPluginFunction<bool,GamepadID,int>(plugin_id, func_name);
	}
}

void MEE_EXPORT MEE_bind_gamepad_KeyIsPressed(int plugin_id, const char* func_name)
{
	auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

	if (pl_manager)
	{
		MEE_gamepad_KeyIsPressed = pl_manager->GetPluginFunction<bool, GamepadID, int>(plugin_id, func_name);
	}
}

void MEE_EXPORT MEE_bind_gamepad_KeyUp(int plugin_id, const char* func_name)
{
	auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

	if (pl_manager)
	{
		MEE_gamepad_KeyUp = pl_manager->GetPluginFunction<bool, GamepadID, int>(plugin_id, func_name);
	}
}

void MEE_EXPORT MEE_bind_gamepad_GetJoystick(int plugin_id, const char* func_name)
{
	auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

	if (pl_manager)
	{
		MEE_gamepad_GetJoystick = pl_manager->GetPluginFunction<void, GamepadID, int*, int*>(plugin_id, func_name);
	}
}

void MEE_EXPORT MEE_bind_gamepad_MakeRumble(int plugin_id, const char* func_name)
{
	auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

	if (pl_manager)
	{
		MEE_gamepad_MakeRumble = pl_manager->GetPluginFunction<void, GamepadID, int>(plugin_id, func_name);
	}
}

