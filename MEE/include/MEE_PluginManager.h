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
		void LoadPlugin(const std::string& path, const Plugin::PluginInformation& info);
		bool SuffixIs(const std::string& fileName, const std::string& suffix);
		bool CheckForDependencies(Plugin::PluginInformation& info);
		std::vector<std::shared_ptr<Plugin>> m_pluginList;
	public:
		bool Init();
		void Load();
		void Update();
		void Draw();
		void PostUpdate();
		void Stop();
		PluginManager()  = default;
		~PluginManager();
		template<class Type,class ... Args>
		std::function<Type(Args...)> GetPluginFunction(int plugin_id, const std::string f_name);
	};

	template<class Type, class ...Args>
	inline std::function<Type(Args...)> PluginManager::GetPluginFunction(int plugin_id, const std::string f_name)
	{
		auto lib = m_pluginList[plugin_id]->m_lib;
		std::string pl_name = m_pluginList[plugin_id]->pluginInformation.name;
		std::function<Type(Args...)> func = (Type(*)(Args...))(PLUGIN_LOAD_EXTERN(lib, f_name.c_str()));
		std::function<Type(Args...)> setUpLogger = [=](Args...args)
		{
			MEE_LOGGER::ScopedLogging log(pl_name);
			return func(args...);
		};
		return setUpLogger;
	}

}



