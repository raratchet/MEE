/*****************************************************************//**
 * \file   MEE_Exports.h
 * \brief  Defines macros from DLL Exporting
 * 
 * \author Maximiliano Herrera
 * \date   November 2021
 *********************************************************************/

#pragma once

#if defined(_WIN64) || defined(_WIN32)
#ifndef MEE_ENGINE
#define MEE_ENGINE_FUNCTION __declspec(dllimport)
#define MEE_ENGINE_VARIABLE __declspec(dllimport)
#define MEE_EXPORT __declspec(dllimport)
#else
#define MEE_ENGINE_FUNCTION __declspec(dllexport)
#define MEE_EXPORT __declspec(dllexport)
#define MEE_ENGINE_VARIABLE __declspec(dllexport)
#endif
#elif defined(__APPLE__) || defined(__linux)
#ifndef MEE_ENGINE
#define MEE_ENGINE_FUNCTION
#define MEE_ENGINE_VARIABLE
#define MEE_EXPORT
#else
#define MEE_ENGINE_FUNCTION
#define MEE_EXPORT
#define MEE_ENGINE_VARIABLE
#endif
#endif

