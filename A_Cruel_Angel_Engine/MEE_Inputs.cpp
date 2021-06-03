#include "MEE_Inputs.h"
#include "MEE_Global.h"



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

