/*****************************************************************//**
 * \file   MEE_PluginManager.h
 * \brief  
 * 
 * \author Maximiliano Herrera
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "MEE_Plugin.h"
#include <filesystem>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <string>
#include <functional>
#include "MEE_Logging.h"
#include "MEE_Exports.h"

namespace MEE
{
	/**
	 * PluginManager loads, holds, and controls all plugins in the engine.
	 */
	class MEE_EXPORT PluginManager
	{
	private:
		bool HasSuffix(const std::string& s, const std::string& suffix);
        bool IsDirectory(const std::string& path);
		Plugin::PluginInformation* ReadInfoFile(const std::string& path);
        void LoadPlugins(std::map<std::string, Plugin::PluginInformation*>& plInfo,
                         std::map<std::string, std::string>& plugin_pathsxs);
		void LoadPlugin(const std::string& path, Plugin::PluginInformation& info);
        void LoadPluginRecursively(const std::string& path,
                                   Plugin::PluginInformation& info,
                                   const std::map<std::string, std::tuple<std::string,Plugin::PluginInformation*>>& plugins,
                                   std::set<std::string>* queued_plugins = new std::set<std::string>());
		bool SuffixIs(const std::string& fileName, const std::string& suffix);
		bool HasDependencies(const Plugin::PluginInformation& info);
        bool PluginIsLoaded(const std::string& plugin_name);
        std::map<std::string, int> m_loadedPluginIndexes;
		std::vector<std::shared_ptr<Plugin>> m_loadedPluginList;
	public:
		bool Init();
		void OnLoad();
		void OnUpdate();
		void OnDraw();
		void OnPostUpdate();
		void Stop();
		PluginManager()  = default;
		~PluginManager();
		template<class Type,class ... Args>
		std::function<Type(Args...)> GetPluginFunction(int plugin_id, const std::string f_name);
    };

	template<class Type, class ...Args>
	inline std::function<Type(Args...)> PluginManager::GetPluginFunction(int plugin_id, const std::string f_name)
	{
		auto lib = m_loadedPluginList[plugin_id]->m_lib;
		std::string pl_name = m_loadedPluginList[plugin_id]->pluginInformation.name;
		std::function<Type(Args...)> func = (Type(*)(Args...))(PLUGIN_LOAD_EXTERN(lib, f_name.c_str()));
		std::function<Type(Args...)> setUpLogger = [=](Args...args)
		{
			MEE_LOGGER::ScopedLogging log(pl_name);
			return func(args...);
		};
		return setUpLogger;
	}

}



