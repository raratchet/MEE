/*****************************************************************//**
 * \file   MEE_Exports.h
 * \brief  Defines macros from DLL Exporting
 * 
 * \author Maximiliano Herrera
 * \date   November 2021
 *********************************************************************/

#pragma once

#ifndef MEE_ENGINE
#define MEE_ENGINE_FUNCTION __declspec(dllimport)
#define MEE_ENGINE_VARIABLE __declspec(dllimport)
#define MEE_EXPORT __declspec(dllimport)
#else
#define MEE_ENGINE_FUNCTION __declspec(dllexport)
#define MEE_EXPORT __declspec(dllexport)
#define MEE_ENGINE_VARIABLE __declspec(dllexport)
#endif
