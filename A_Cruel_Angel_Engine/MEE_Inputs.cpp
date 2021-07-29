#include "MEE_Inputs.h"
#include "MEE_Global.h"
#include "MEE_WindowHandler.h"
#include "MEE_Graphics.h"



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

void MEE_EXPORT MEE_bind_keyboard_KeyPressedThisFrame(int plugin_id, const std::string& func_name)
{
	auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

	if (pl_manager)
	{
		MEE_keyboard_KeyPressedThisFrame = pl_manager->GetPluginFunction<bool,int>(plugin_id, func_name);
	}
}

void MEE_EXPORT MEE_bind_keyboard_KeyIsPressed(int plugin_id, const std::string& func_name)
{
	auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

	if (pl_manager)
	{
		MEE_keyboard_KeyIsPressed = pl_manager->GetPluginFunction<bool, int>(plugin_id, func_name);
	}
}

void MEE_EXPORT MEE_bind_keyboard_KeyUp(int plugin_id, const std::string& func_name)
{
	auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

	if (pl_manager)
	{
		MEE_keyboard_KeyUp = pl_manager->GetPluginFunction<bool, int>(plugin_id, func_name);
	}
}

void MEE_EXPORT MEE_bind_mouse_KeyPressedThisFrame(int plugin_id, const std::string& func_name)
{
	auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

	if (pl_manager)
	{
		MEE_mouse_KeyPressedThisFrame = pl_manager->GetPluginFunction<bool, int>(plugin_id, func_name);
	}
}

void MEE_EXPORT MEE_bind_mouse_KeyIsPressed(int plugin_id, const std::string& func_name)
{
	auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

	if (pl_manager)
	{
		MEE_mouse_KeyIsPressed = pl_manager->GetPluginFunction<bool, int>(plugin_id, func_name);
	}
}

void MEE_EXPORT MEE_bind_mouse_KeyUp(int plugin_id, const std::string& func_name)
{
	auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

	if (pl_manager)
	{
		MEE_mouse_KeyUp = pl_manager->GetPluginFunction<bool, int>(plugin_id, func_name);
	}
}

void MEE_EXPORT MEE_bind_mouse_GetPosition(int plugin_id, const std::string& func_name)
{
	auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

	if (pl_manager)
	{
		MEE_mouse_GetPosition = pl_manager->GetPluginFunction<void,int*,int*>(plugin_id, func_name);
	}
}

void MEE_EXPORT MEE_bind_gamepad_KeyPressedThisFrame(int plugin_id, const std::string& func_name)
{
	auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

	if (pl_manager)
	{
		MEE_gamepad_KeyPressedThisFrame = pl_manager->GetPluginFunction<bool,GamepadID,int>(plugin_id, func_name);
	}
}

void MEE_EXPORT MEE_bind_gamepad_KeyIsPressed(int plugin_id, const std::string& func_name)
{
	auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

	if (pl_manager)
	{
		MEE_gamepad_KeyIsPressed = pl_manager->GetPluginFunction<bool, GamepadID, int>(plugin_id, func_name);
	}
}

void MEE_EXPORT MEE_bind_gamepad_KeyUp(int plugin_id, const std::string& func_name)
{
	auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

	if (pl_manager)
	{
		MEE_gamepad_KeyUp = pl_manager->GetPluginFunction<bool, GamepadID, int>(plugin_id, func_name);
	}
}

void MEE_EXPORT MEE_bind_gamepad_GetJoystick(int plugin_id, const std::string& func_name)
{
	auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

	if (pl_manager)
	{
		MEE_gamepad_GetJoystick = pl_manager->GetPluginFunction<void, GamepadID, int*, int*>(plugin_id, func_name);
	}
}

void MEE_EXPORT MEE_bind_gamepad_MakeRumble(int plugin_id, const std::string& func_name)
{
	auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

	if (pl_manager)
	{
		MEE_gamepad_MakeRumble = pl_manager->GetPluginFunction<void, GamepadID, int>(plugin_id, func_name);
	}
}

