#pragma once
#include<functional>
#include "MEE_Exports.h"

//Binding Functions
void MEE_EXPORT MEE_bind_updateInput(int plugin_id, const std::string& func_name);
void MEE_EXPORT MEE_bind_keyboard_keyPressedThisFrame(int plugin_id, const std::string& func_name);
void MEE_EXPORT MEE_bind_keyboard_keyIsPressed(int plugin_id, const std::string& func_name);
void MEE_EXPORT MEE_bind_keyboard_keyUp(int plugin_id, const std::string& func_name);
void MEE_EXPORT MEE_bind_mouse_keyPressedThisFrame(int plugin_id, const std::string& func_name);
void MEE_EXPORT MEE_bind_mouse_keyIsPressed(int plugin_id, const std::string& func_name);
void MEE_EXPORT MEE_bind_mouse_keyUp(int plugin_id, const std::string& func_name);
void MEE_EXPORT MEE_bind_mouse_position(int plugin_id, const std::string& func_name);

inline std::function<void()> MEE_updateInput;
//Keyboard
inline std::function<bool(int)> MEE_keyboard_keyPressedThisFrame;
inline std::function<bool(int)> MEE_keyboard_keyIsPressed;
inline std::function<bool(int)> MEE_keyboard_keyUp;
//Mouse
inline std::function<bool(int)> MEE_mouse_keyPressedThisFrame;
inline std::function<bool(int)> MEE_mouse_keyIsPressed;
inline std::function<bool(int)> MEE_mouse_keyUp;
inline std::function<void(int*, int*)> MEE_mouse_position;
