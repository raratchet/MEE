#pragma once

#include "MEE_Plugin.h"

#include <filesystem>
#include <vector>
#include <memory>
#include <functional>


namespace MEE
{
	class PluginManager
	{
	private:
		bool hasSuffix(const std::wstring& s, const std::wstring& suffix);
		Plugin::PluginInformation readInfoFile(const std::wstring& path);
		void loadPlugin(const std::wstring& path, const Plugin::PluginInformation& info);
		bool suffixIs(const std::wstring& fileName, const std::wstring& suffix);
		bool checkForDependecies(const Plugin::PluginInformation& info);
		std::vector<std::shared_ptr<Plugin>> m_pluginList;
	public:
		bool init();
		void load();
		void update();
		void postUpdate();
		void stop();
		PluginManager() = default;
		~PluginManager() = default;

		template<class Type,class ... Args>
		std::function<Type(Args...)> getPluginFunction(int plugin_id, const std::string f_name);
	};

	template<class Type, class ...Args>
	inline std::function<Type(Args...)> PluginManager::getPluginFunction(int plugin_id, const std::string f_name)
	{
		auto lib = m_pluginList[plugin_id]->m_lib;
		std::function<Type(Args...)> func = (Type(*)(Args...))(PLUGIN_LOAD_EXTERN(lib, f_name.c_str()));
		return func;
	}

}



