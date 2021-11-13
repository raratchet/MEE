/*****************************************************************//**
 * \file   MEE_Inputs.h
 * \brief The Interface between MEE and Input Module.\n
 * This header contains functions to bind and link a module function to the engine. \n
 * \author Maximiliano Herrera
 * \date   November 2021
 *********************************************************************/
#pragma once
#include<functional>
#include "MEE_Exports.h"

enum class InputHandlerAPI
{
	SDL,
	GLFW
};

using GamepadID = unsigned int;

InputHandlerAPI MEE_EXPORT MEE_GetInputHandlerAPI();
void MEE_EXPORT MEE_CloseApplicationSignal();

//Estas funciones envuelen a las que existen en engine
//Son las funciones disponibles para los modulos y addons

void MEE_EXPORT MEE_bind_keyboard_KeyPressedThisFrame(int plugin_id, const char* func_name);
void MEE_EXPORT MEE_bind_keyboard_KeyIsPressed(int plugin_id, const char* func_name);
void MEE_EXPORT MEE_bind_keyboard_KeyUp(int plugin_id, const char* func_name);
void MEE_EXPORT MEE_bind_mouse_KeyPressedThisFrame(int plugin_id, const char* func_name);
void MEE_EXPORT MEE_bind_mouse_KeyIsPressed(int plugin_id, const char* func_name);
void MEE_EXPORT MEE_bind_mouse_KeyUp(int plugin_id, const char* func_name);
void MEE_EXPORT MEE_bind_mouse_GetPosition(int plugin_id, const char* func_name);
void MEE_EXPORT MEE_bind_gamepad_KeyPressedThisFrame(int plugin_id, const char* func_name);
void MEE_EXPORT MEE_bind_gamepad_KeyIsPressed(int plugin_id, const char* func_name);
void MEE_EXPORT MEE_bind_gamepad_KeyUp(int plugin_id, const char* func_name);
void MEE_EXPORT MEE_bind_gamepad_GetJoystick(int plugin_id, const char* func_name);
void MEE_EXPORT MEE_bind_gamepad_MakeRumble(int plugin_id, const char* func_name);

#ifdef MEE_ENGINE

//Keyboard
extern std::function<bool(int key)> MEE_keyboard_KeyPressedThisFrame;
extern std::function<bool(int key)> MEE_keyboard_KeyIsPressed;
extern std::function<bool(int key)> MEE_keyboard_KeyUp;
//Mouse
extern std::function<bool(int key)> MEE_mouse_KeyIsPressed;
extern std::function<bool(int key)> MEE_mouse_KeyUp;
extern std::function<bool(int key)> MEE_mouse_KeyPressedThisFrame;
extern std::function<void(int* x_val,int* y_val)> MEE_mouse_GetPosition;
//Gamepads
extern std::function<bool(GamepadID,int key)> MEE_gamepad_KeyPressedThisFrame;
extern std::function<bool(GamepadID,int key)> MEE_gamepad_KeyIsPressed;
extern std::function<bool(GamepadID,int key)> MEE_gamepad_KeyUp;
extern std::function<void(GamepadID,int* x_val,int* y_val)> MEE_gamepad_GetJoystick;
extern std::function<void(GamepadID,int duration)> MEE_gamepad_MakeRumble;

#endif // MEE_ENGINE