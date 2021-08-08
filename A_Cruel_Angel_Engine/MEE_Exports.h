#pragma once

#ifndef MEE_ENGINE
#define MEE_EXPORT __declspec(dllimport)
#else
#define MEE_EXPORT __declspec(dllexport)
#endif

#ifndef MEE_ENGINE
#define MEE_ENGINE_FUNCTION __declspec(dllimport)
#else
#define MEE_ENGINE_FUNCTION __declspec(dllexport)
#endif

#ifndef MEE_ENGINE
#define MEE_ENGINE_VARIABLE __declspec(dllimport)
#else
#define MEE_ENGINE_VARIABLE __declspec(dllexport)
#endif
