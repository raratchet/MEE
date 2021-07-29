#pragma once
#include<functional>
#include "MEE_Exports.h"

enum class InputHandlerAPI
{
	SDL,
	GLFW
};

using GamepadID = unsigned int;

//Binding Functions
InputHandlerAPI MEE_EXPORT MEE_GetInputHandlerAPI();
void MEE_EXPORT MEE_bind_keyboard_KeyPressedThisFrame(int plugin_id, const std::string& func_name);
void MEE_EXPORT MEE_bind_keyboard_KeyIsPressed(int plugin_id, const std::string& func_name);
void MEE_EXPORT MEE_bind_keyboard_KeyUp(int plugin_id, const std::string& func_name);
void MEE_EXPORT MEE_bind_mouse_KeyPressedThisFrame(int plugin_id, const std::string& func_name);
void MEE_EXPORT MEE_bind_mouse_KeyIsPressed(int plugin_id, const std::string& func_name);
void MEE_EXPORT MEE_bind_mouse_KeyUp(int plugin_id, const std::string& func_name);
void MEE_EXPORT MEE_bind_mouse_GetPosition(int plugin_id, const std::string& func_name);
void MEE_EXPORT MEE_bind_gamepad_KeyPressedThisFrame(int plugin_id, const std::string& func_name);
void MEE_EXPORT MEE_bind_gamepad_KeyIsPressed(int plugin_id, const std::string& func_name);
void MEE_EXPORT MEE_bind_gamepad_KeyUp(int plugin_id, const std::string& func_name);
void MEE_EXPORT MEE_bind_gamepad_GetJoystick(int plugin_id, const std::string& func_name);
void MEE_EXPORT MEE_bind_gamepad_MakeRumble(int plugin_id, const std::string& func_name);

//Keyboard
inline std::function<bool(int key)> MEE_keyboard_KeyPressedThisFrame;
inline std::function<bool(int key)> MEE_keyboard_KeyIsPressed;
inline std::function<bool(int key)> MEE_keyboard_KeyUp;
//Mouse
inline std::function<bool(int key)> MEE_mouse_KeyIsPressed;
inline std::function<bool(int key)> MEE_mouse_KeyUp;
inline std::function<bool(int key)> MEE_mouse_KeyPressedThisFrame;
inline std::function<void(int* x_val,int* y_val)> MEE_mouse_GetPosition;
//Gamepads
inline std::function<bool(GamepadID,int key)> MEE_gamepad_KeyPressedThisFrame;
inline std::function<bool(GamepadID,int key)> MEE_gamepad_KeyIsPressed;
inline std::function<bool(GamepadID,int key)> MEE_gamepad_KeyUp;
inline std::function<void(GamepadID,int* x_val,int* y_val)> MEE_gamepad_GetJoystick;
inline std::function<void(GamepadID,int duration)> MEE_gamepad_MakeRumble;
