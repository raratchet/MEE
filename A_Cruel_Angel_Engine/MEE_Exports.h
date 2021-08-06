#pragma once

#define MEE_EXPORT __declspec(dllexport)

#ifndef MEE_ENGINE
#define MEE_ENGINE_FUNCTION __declspec(dllimport)
#else
#define MEE_ENGINE_FUNCTION __declspec(dllexport)
#endif
