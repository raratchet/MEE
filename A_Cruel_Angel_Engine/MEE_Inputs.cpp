#include "MEE_Inputs.h"
#include "MEE_Global.h"


void MEE_EXPORT MEE_bind_updateInput(int plugin_id, const std::string& func_name)
{
	auto pl_manager = MEE_GLOBAL::application->getPluginManager().lock();

	if (pl_manager)
	{
		MEE_updateInput = pl_manager->getPluginFunction<void>(plugin_id, func_name);
	}
}

void MEE_EXPORT MEE_bind_keyboard_keyPressedThisFrame(int plugin_id, const std::string& func_name)
{
	auto pl_manager = MEE_GLOBAL::application->getPluginManager().lock();

	if (pl_manager)
	{
		MEE_keyboard_keyPressedThisFrame = pl_manager->getPluginFunction<bool,int>(plugin_id, func_name);
	}
}

void MEE_EXPORT MEE_bind_keyboard_keyIsPressed(int plugin_id, const std::string& func_name)
{
	auto pl_manager = MEE_GLOBAL::application->getPluginManager().lock();

	if (pl_manager)
	{
		MEE_keyboard_keyIsPressed = pl_manager->getPluginFunction<bool, int>(plugin_id, func_name);
	}
}

void MEE_EXPORT MEE_bind_keyboard_keyUp(int plugin_id, const std::string& func_name)
{
	auto pl_manager = MEE_GLOBAL::application->getPluginManager().lock();

	if (pl_manager)
	{
		MEE_keyboard_keyUp = pl_manager->getPluginFunction<bool, int>(plugin_id, func_name);
	}
}

void MEE_EXPORT MEE_bind_mouse_keyPressedThisFrame(int plugin_id, const std::string& func_name)
{
	auto pl_manager = MEE_GLOBAL::application->getPluginManager().lock();

	if (pl_manager)
	{
		MEE_mouse_keyPressedThisFrame = pl_manager->getPluginFunction<bool, int>(plugin_id, func_name);
	}
}

void MEE_EXPORT MEE_bind_mouse_keyIsPressed(int plugin_id, const std::string& func_name)
{
	auto pl_manager = MEE_GLOBAL::application->getPluginManager().lock();

	if (pl_manager)
	{
		MEE_mouse_keyIsPressed = pl_manager->getPluginFunction<bool, int>(plugin_id, func_name);
	}
}

void MEE_EXPORT MEE_bind_mouse_keyUp(int plugin_id, const std::string& func_name)
{
	auto pl_manager = MEE_GLOBAL::application->getPluginManager().lock();

	if (pl_manager)
	{
		MEE_mouse_keyUp = pl_manager->getPluginFunction<bool, int>(plugin_id, func_name);
	}
}

void MEE_EXPORT MEE_bind_mouse_position(int plugin_id, const std::string& func_name)
{
	auto pl_manager = MEE_GLOBAL::application->getPluginManager().lock();

	if (pl_manager)
	{
		MEE_mouse_position = pl_manager->getPluginFunction<void,int*,int*>(plugin_id, func_name);
	}
}

