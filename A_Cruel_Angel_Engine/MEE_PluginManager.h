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
		bool HasSuffix(const std::wstring& s, const std::wstring& suffix);
		Plugin::PluginInformation ReadInfoFile(const std::wstring& path);
		void LoadPlugin(const std::wstring& path, const Plugin::PluginInformation& info);
		bool SuffixIs(const std::wstring& fileName, const std::wstring& suffix);
		bool CheckForDependecies(const Plugin::PluginInformation& info);
		std::vector<std::shared_ptr<Plugin>> m_pluginList;
	public:
		bool Init();
		void Load();
		void Update();
		void Draw();
		void PostUpdate();
		void Stop();
		PluginManager()  = default;
		~PluginManager() = default;
		template<class Type,class ... Args>
		std::function<Type(Args...)> GetPluginFunction(int plugin_id, const std::string f_name);
	};

	template<class Type, class ...Args>
	inline std::function<Type(Args...)> PluginManager::GetPluginFunction(int plugin_id, const std::string f_name)
	{
		auto lib = m_pluginList[plugin_id]->m_lib;
		std::function<Type(Args...)> func = (Type(*)(Args...))(PLUGIN_LOAD_EXTERN(lib, f_name.c_str()));
		return func;
	}

}



