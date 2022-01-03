#pragma once

#if defined(_WIN64) || defined(_WIN32)
#define MEG_EXPORT __declspec(dllexport)
#define MEG_IMPORT __declspec(dllimport)
#elif defined(__APPLE__) || defined(__linux)
#define MEG_EXPORT
#define MEG_IMPORT
#endif