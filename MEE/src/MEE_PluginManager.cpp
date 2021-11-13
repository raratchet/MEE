#include "MEE_PluginManager.h"
#include <iostream>
#include <yaml-cpp/yaml.h>

namespace MEE
{
	bool PluginManager::HasSuffix(const std::wstring& s, const std::wstring& suffix)
	{
		return s.size() >= suffix.size() && s.compare(s.size() - suffix.size(), suffix.size(), suffix) == 0;
	}

	Plugin::PluginInformation* PluginManager::ReadInfoFile(const std::wstring& path)
	{
		std::string name(path.begin(),path.end());
		YAML::Node info = YAML::LoadFile(name);
		Plugin::PluginInformation* plInfo = new Plugin::PluginInformation();

		plInfo->name = info["Name"].as<std::string>();
		plInfo->version = info["Version"].as<std::string>();

		return plInfo;
	}
	
	void PluginManager::LoadPlugin(const std::wstring& path, const Plugin::PluginInformation& info)
	{
		Plugin* pl = new Plugin(path, info);
		if (!pl->pluginInformation.loaded) return;

		std::shared_ptr<Plugin> plugin(pl);
		
		m_pluginList.push_back(plugin);

		MEE_LOGGER::CreateLogger(info.name);

		MEE_LOGGER::ScopedLogging log(info.name.c_str());

		plugin->OnInit(m_pluginList.size() - 1);
	}

	bool PluginManager::SuffixIs(const std::wstring& fileName, const std::wstring& suffix)
	{
		std::wstring fileSuffix(fileName.end() - suffix.size(), fileName.end());

		return suffix == fileSuffix;
	}

	bool PluginManager::CheckForDependecies(Plugin::PluginInformation& info)
	{
		return true;
	}

	bool PluginManager::Init()
	{
		bool success = true;
		try
		{
			std::filesystem::path pls = "Plugins";
			std::filesystem::directory_iterator pluginMainDirectory
			(std:: filesystem::absolute(pls));

			std::map<std::wstring, Plugin::PluginInformation*> plInfo;
			std::map<std::wstring, std::wstring> plugins;

			for (auto& extFile : pluginMainDirectory)
			{
				std::filesystem::path extPath = extFile.path();

				if (!HasSuffix(extPath.wstring(), PLUGIN_LIBRARY_SUFFIX))
				{
					std::filesystem::directory_iterator pluginDirectory(extPath);
					for (auto& pluginFile : pluginDirectory)
					{
						std::filesystem::path pluginPath = pluginFile.path();
						if (SuffixIs(pluginPath, L"yaml"))
							plInfo.insert({ extPath,ReadInfoFile(pluginPath) });
						if (SuffixIs(pluginPath, PLUGIN_LIBRARY_SUFFIX))
							plugins.insert({ extPath,pluginPath });
					}
				}
			}

			for (auto& plugin : plugins)
			{
				auto& pluginInfo = plInfo[plugin.first];
				if (pluginInfo != nullptr)
					if (CheckForDependecies(*pluginInfo))
						LoadPlugin(plugin.second, *pluginInfo);
					else
						MEE_LOGGER::Error(std::string("Cannot load " + pluginInfo->name
							+ " some dependecies are missing").c_str());
				else
					MEE_LOGGER::Warn("Some plugins may have not been loaded.");
			}
		}
		catch (std::filesystem::filesystem_error e)
		{
			MEE_LOGGER::Error(e.what());
			success = false;
		}

		return success;
	}

	void PluginManager::Load()
	{
		for (auto plugin : m_pluginList)
		{
			MEE_LOGGER::ScopedLogging log(plugin->pluginInformation.name.c_str());
			plugin->OnLoad();
		}
	}

	void PluginManager::Update()
	{
		for (auto plugin : m_pluginList)
		{
			if (plugin->OnUpdate != nullptr)
			{
				MEE_LOGGER::ScopedLogging log(plugin->pluginInformation.name.c_str());
				plugin->OnUpdate();
			}
		}
	}

	void PluginManager::Draw()
	{
		for (auto plugin : m_pluginList)
		{
			if (plugin->OnDraw != nullptr)
			{
				MEE_LOGGER::ScopedLogging log(plugin->pluginInformation.name.c_str());
				plugin->OnDraw();
			}
		}
	}

	void PluginManager::PostUpdate()
	{
		for (auto plugin : m_pluginList)
		{
			if (plugin->OnPostUpdate != nullptr)
			{
				MEE_LOGGER::ScopedLogging log(plugin->pluginInformation.name.c_str());
				plugin->OnPostUpdate();
			}
		}
	}

	void PluginManager::Stop()
	{
		for (auto plugin : m_pluginList) {
			MEE_LOGGER::ScopedLogging log(plugin->pluginInformation.name.c_str());
			plugin->OnShutdown();
		}
	}

	PluginManager::~PluginManager()
	{
		m_pluginList.clear();
	}
}


