#pragma once


#include <filesystem>
#include <iostream>


#if defined(_WIN64) || defined(_WIN32)

// WINDOWS
#include <windows.h>

#define PLUGIN_EXPORT __declspec(dllexport)
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
#define PLUGIN_LIBRARY_SUFFIX L".so"

#endif

namespace MEE
{
	class Plugin
	{
	private:

		typedef void	(*onInitType)(int);
		typedef void	(*onLoadType)();
		typedef void	(*onShutdownType)();
		typedef void	(*onUpdateType)();
		typedef void	(*onDrawType)();
		typedef void	(*onPostUpdateType)();

		PLUGIN_HANDLE_TYPE m_lib;

	public:

		struct PluginInformation
		{
			std::string name;
			std::string version;

			//TODO ADD DEPENDECIES, TYPE, ALL THAT STUFF
		};

		Plugin(std::filesystem::path filename, const PluginInformation& info);
		~Plugin();

		onInitType	     OnInit;
		onLoadType	     OnLoad;
		onShutdownType   OnShutdown;
		onUpdateType     OnUpdate;
		onDrawType       OnDraw;
		onPostUpdateType OnPostUpdate;

	private:

		PluginInformation pluginInformation;

		friend class PluginManager;
	};

}


