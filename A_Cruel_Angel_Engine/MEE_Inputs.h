#pragma once
#include<functional>
#include "MEE_Exports.h"

//Binding Functions
void MEE_EXPORT MEE_bind_keyboard_KeyPressedThisFrame(int plugin_id, const std::string& func_name);
void MEE_EXPORT MEE_bind_keyboard_KeyIsPressed(int plugin_id, const std::string& func_name);
void MEE_EXPORT MEE_bind_keyboard_KeyUp(int plugin_id, const std::string& func_name);
void MEE_EXPORT MEE_bind_mouse_KeyPressedThisFrame(int plugin_id, const std::string& func_name);
void MEE_EXPORT MEE_bind_mouse_KeyIsPressed(int plugin_id, const std::string& func_name);
void MEE_EXPORT MEE_bind_mouse_KeyUp(int plugin_id, const std::string& func_name);
void MEE_EXPORT MEE_bind_mouse_GetPosition(int plugin_id, const std::string& func_name);


//Keyboard
inline std::function<bool(int)> MEE_keyboard_KeyPressedThisFrame;
inline std::function<bool(int)> MEE_keyboard_KeyIsPressed;
inline std::function<bool(int)> MEE_keyboard_KeyUp;
//Mouse
inline std::function<bool(int)> MEE_mouse_KeyPressedThisFrame;
inline std::function<bool(int)> MEE_mouse_KeyIsPressed;
inline std::function<bool(int)> MEE_mouse_KeyUp;
inline std::function<void(int*, int*)> MEE_mouse_GetPosition;
