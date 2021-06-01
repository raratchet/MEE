#include "MEE_PluginManager.h"
#include <iostream>
#include <yaml-cpp/yaml.h>


namespace MEE
{
	bool PluginManager::hasSuffix(const std::wstring& s, const std::wstring& suffix)
	{
		return s.size() >= suffix.size() && s.compare(s.size() - suffix.size(), suffix.size(), suffix) == 0;
	}

	Plugin::PluginInformation PluginManager::readInfoFile(const std::wstring& path)
	{
		std::string name(path.begin(),path.end());
		YAML::Node info = YAML::LoadFile(name);
		Plugin::PluginInformation plInfo;

		plInfo.name = info["Name"].as<std::string>();
		plInfo.version = info["Version"].as<std::string>();

		return plInfo;
	}
	
	void PluginManager::loadPlugin(const std::wstring& path, const Plugin::PluginInformation& info)
	{
		std::shared_ptr<Plugin> plugin(new Plugin(path,info));
		
		m_pluginList.push_back(plugin);

		plugin->onInit(m_pluginList.size() - 1);
	}

	bool PluginManager::suffixIs(const std::wstring& fileName, const std::wstring& suffix)
	{
		std::wstring fileSuffix(fileName.end() - suffix.size(), fileName.end());

		return suffix == fileSuffix;
	}

	bool PluginManager::checkForDependecies(const Plugin::PluginInformation& info)
	{
		return true;
	}

	bool PluginManager::init()
	{
		bool success = true;
		try
		{
			std::filesystem::directory_iterator pluginMainDirectory("C://Work/T_Plugins/x64");

			std::map<std::wstring, Plugin::PluginInformation> plInfo;
			std::map<std::wstring, std::wstring> plugins;

			for (auto& extFile : pluginMainDirectory)
			{
				std::filesystem::path extPath = extFile.path();

				if (!hasSuffix(extPath.wstring(), PLUGIN_LIBRARY_SUFFIX))
				{
					std::filesystem::directory_iterator pluginDirectory(extPath);
					for (auto& pluginFile : pluginDirectory)
					{
						std::filesystem::path pluginPath = pluginFile.path();
						if (suffixIs(pluginPath, L"yaml"))
							plInfo.insert({ extPath,readInfoFile(pluginPath) });
						if (suffixIs(pluginPath, PLUGIN_LIBRARY_SUFFIX))
							plugins.insert({ extPath,pluginPath });
					}
				}
			}

			for (auto& plugin : plugins)
			{
				auto& pluginInfo = plInfo[plugin.first];
				if (checkForDependecies(pluginInfo))
					loadPlugin(plugin.second, plInfo[plugin.first]);
				else
					std::cout << "[MEE] Cannot load " << pluginInfo.name
					<< " some dependecies are missing" << std::endl;
			}
		}
		catch (std::filesystem::filesystem_error e)
		{
			std::cout << e.what() << '\n';
			success = false;
		}

		return success;
	}

	void PluginManager::load()
	{
		for (auto plugin : m_pluginList)
		{
			plugin->onLoad();
		}
	}

	void PluginManager::update()
	{
		for (auto plugin : m_pluginList)
		{
			if(plugin->onUpdate != nullptr)
				plugin->onUpdate();
		}
	}

	void PluginManager::postUpdate()
	{
		for (auto plugin : m_pluginList)
		{
			if (plugin->onPostUpdate != nullptr)
				plugin->onPostUpdate();
		}
	}

	void PluginManager::stop()
	{
		for (auto plugin : m_pluginList) {
			plugin->onShutdown();
		}
		m_pluginList.clear();
	}
}


