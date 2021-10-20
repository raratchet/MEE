#pragma once

#if defined(_WIN64) || defined(_WIN32)

// WINDOWS
#include <windows.h>

#define PLUGIN_FUNCTION extern "C" __declspec(dllexport)
#define PLUGIN_CLASS __declspec(dllexport)
#define PLUGIN_HANDLE_TYPE HMODULE
#define PLUGIN_PROGRAM_HANDLE GetModuleHandleW(nullptr) // esto no lo deberia permitir
#define PLUGIN_LOAD_EXTERN GetProcAddress

#elif defined(__APPLE__) || defined(__linux)

// APPLE & LINUX
#include <dlfcn.h>

#define PLUGIN_EVT_EXPORT
#define PLUGIN_HANDLE_TYPE void*
#define PLUGIN_PROGRAM_HANDLE dlopen(nullptr, RTLD_LAZY)
#define PLUGIN_LOAD_EXTERN dlsym

#endif