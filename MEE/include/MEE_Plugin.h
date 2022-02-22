/*****************************************************************//**
 * \file   MEE_Plugin.h
 * \brief  
 * 
 * \author Maximiliano Herrera
 * \date   October 2021
 *********************************************************************/
#pragma once
#include <filesystem>
#include <iostream>
#include <vector>
#include "MEE_Exports.h"

#if defined(_WIN64) || defined(_WIN32)

// WINDOWS
#include <windows.h>

#define PLUGIN_FUNCTION __declspec(dllexport)
#define PLUGIN_HANDLE_TYPE HMODULE
#define PLUGIN_PROGRAM_HANDLE LoadLibraryW(filename.c_str());
#define PLUGIN_LOAD_EXTERN GetProcAddress
#define PLUGIN_CLOSE_EXTERN FreeLibrary
#define PLUGIN_LIBRARY_SUFFIX L".dll"

#elif defined(__APPLE__) || defined(__linux)

// APPLE & LINUX
#include <dlfcn.h>

#define PLUGIN_EVT_EXPORT
#define PLUGIN_HANDLE_TYPE void*
#define PLUGIN_PROGRAM_HANDLE dlopen(filename.c_str(), RTLD_LAZY);
#define PLUGIN_LOAD_EXTERN dlsym
#define PLUGIN_CLOSE_EXTERN dlclose
#if defined(__APPLE__)
#define PLUGIN_LIBRARY_SUFFIX ".dylib"
#elif
#define PLUGIN_LIBRARY_SUFFIX ".so"
#endif
#endif

namespace MEE
{
	/**
	 * Plugin is a class that loads and holds a dynamic library as part of the engine.
	 */
	class MEE_EXPORT Plugin
	{
	private:

		typedef void	(*onInitType)(int);
		typedef void	(*onLoadType)();
		typedef void	(*onShutdownType)();
		typedef void	(*onUpdateType)();
		typedef void	(*onDrawType)();
		typedef void	(*onPostUpdateType)();


		PLUGIN_HANDLE_TYPE m_lib;

        enum class PluginType
        {
            ADDON,
            MODULE,
            UNKNOWN
        };

        struct PluginInformation
        {
            std::string name;
            std::string version;
            std::string author;
            int id;
            PluginType type;
            std::vector<std::string> dependencies;
            bool loaded;
        };

	public:



		Plugin(std::filesystem::path filename, const PluginInformation& info);
		virtual ~Plugin();

		onInitType	     OnInit;
		onLoadType	     OnLoad;
		onShutdownType   OnShutdown;
		onUpdateType     OnUpdate;
		onDrawType       OnDraw;
		onPostUpdateType OnPostUpdate;

	private:

		PluginInformation pluginInformation;
        void LoadAsModule();
        void LoadAsAddon();
		friend class PluginManager;
	};

}


