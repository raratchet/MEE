#include "MEE_PluginManager.h"
#include <iostream>
#include <yaml-cpp/yaml.h>

namespace MEE
{
	bool PluginManager::HasSuffix(const std::string& s, const std::string& suffix)
	{
		return s.size() >= suffix.size() && s.compare(s.size() - suffix.size(), suffix.size(), suffix) == 0;
	}

    bool PluginManager::IsDirectory(const std::string &path)
    {
        try
        {
           auto isDirectory = std::filesystem::directory_entry(path);
            return true;
        }
        catch (std::filesystem::filesystem_error error)
        {
            return false;
        }
    }

	Plugin::PluginInformation* PluginManager::ReadInfoFile(const std::string& path)
	{
		std::string name(path.begin(),path.end());
		YAML::Node info = YAML::LoadFile(name);
		Plugin::PluginInformation* plInfo = new Plugin::PluginInformation();

		plInfo->name = info["Name"].as<std::string>();
		plInfo->version = info["Version"].as<std::string>();
        plInfo->author = info["Author"].as<std::string>();

        auto type = info["Type"].as<std::string>();
        if(type == "Module")
            plInfo->type = Plugin::PluginType::MODULE;
        else if(type == "Addon")
            plInfo->type = Plugin::PluginType::ADDON;
        else
            plInfo->type = Plugin::PluginType::UNKNOWN;

		return plInfo;
	}
	
	void PluginManager::LoadPlugin(const std::string& path, Plugin::PluginInformation& info)
	{

        if(info.loaded) return;

		Plugin* pl = new Plugin(path, info);
		if (!pl->pluginInformation.loaded) return;

		std::shared_ptr<Plugin> plugin(pl);
		
		m_loadedPluginList.push_back(plugin);

		MEE_LOGGER::CreateLogger(info.name);

		MEE_LOGGER::ScopedLogging log(info.name);

        int pl_id = m_loadedPluginList.size() - 1;

		plugin->OnInit(pl_id);
        info.id = pl_id;
        m_loadedPluginIndexes[info.name] = pl_id;
	}

    bool PluginManager::SuffixIs(const std::string &fileName, const std::string &suffix)
    {
        std::string fileSuffix(fileName.end() - suffix.size(), fileName.end());

        return suffix == fileSuffix;
    }

	bool PluginManager::HasDependencies(const Plugin::PluginInformation& info)
	{
        return info.dependencies.empty() ? false : true;
	}

	bool PluginManager::Init()
	{
		bool success = true;
		try
		{
			std::filesystem::directory_iterator pluginMainDirectory("./Plugins/");

            // Key -> El path hacia la carpeta donde está el info_file.
			std::map<std::string, Plugin::PluginInformation*> plInfo;
            // Key -> El path hacia la carpeta donde se encuentra la libreria.
            // Value -> El path completo de la libreria.
			std::map<std::string, std::string> plugins;

			for (auto& extFile : pluginMainDirectory)
			{
				std::filesystem::path extPath = extFile.path();

				if (std::filesystem::is_directory(extPath))
				{
					std::filesystem::directory_iterator pluginDirectory(extPath);
					for (auto& pluginFile : pluginDirectory)
					{
						auto pluginPath = pluginFile.path().string();
						if (SuffixIs(pluginPath, "yaml"))
							plInfo.insert({ extPath,ReadInfoFile(pluginPath) });
						if (SuffixIs(pluginPath, PLUGIN_LIBRARY_SUFFIX))
							plugins.insert({ extPath,pluginPath });
					}
				}
			}
            LoadPlugins(plInfo, plugins);
		}
		catch (std::filesystem::filesystem_error e)
		{
            MEE_LOGGER::Error(e.what());
			success = false;
		}

		return success;
	}

    void PluginManager::LoadPluginRecursively(const std::string &path,
                                              Plugin::PluginInformation &info,
                                              const std::map<std::string,
                                              std::tuple<std::string,Plugin::PluginInformation*>>& plugins,
                                              std::set<std::string>* queued_plugins)
    {
        auto queued = queued_plugins->insert(info.name);

        if(queued.second)
        {
            MEE_LOGGER::Error("Error while loading plugins. Recursive dependencies in plugin: " + info.name);
            throw "Recursive Dependencies Exception";
        }//Already queued

        for(auto& dependency : info.dependencies)
        {
            auto dependency_plugin = plugins.at(dependency);
            auto dependency_path = get<0>(dependency_plugin);
            auto dependency_plugin_info = get<1>(dependency_plugin);

            if(HasDependencies(*dependency_plugin_info))
            {
                LoadPluginRecursively(dependency_path,*dependency_plugin_info,plugins,queued_plugins);
            }
            else
            {
                LoadPlugin(dependency_path,*dependency_plugin_info);
            }

        }

        for(auto dependency : info.dependencies)
        {
            if(!PluginIsLoaded(dependency)) //TODO Add configuration to determine if skip o stop engine if dependencies are missing
            {
                MEE_LOGGER::Error("Cannot load " + info.name+ ". Missing Dependencies");
                throw "Missing dependencies exception";
            }
        }

        LoadPlugin(path, info);

    }

    bool PluginManager::PluginIsLoaded(const std::string &plugin_name)
    {
        return false;
    }

    void PluginManager::LoadPlugins(std::map<std::string, Plugin::PluginInformation*>& plInfo,
                                    std::map<std::string, std::string>& plugin_paths)
    {
        //Key -> name of plugin
        //Value -> tuple: path to plugin lib and plugin_info
        std::map<std::string,
        std::tuple<std::string,Plugin::PluginInformation*>> plugins;

        for(auto& plugin_path : plugin_paths)
        {
            auto plugin_info = plInfo[plugin_path.first];
            plugins[plugin_info->name] = std::make_tuple(plugin_path.second,plugin_info);
        }

        for (auto& plugin : plugins)
        {
            auto& plugin_path = get<0>(plugin.second);
            auto plugin_info = get<1>(plugin.second);

            if (plugin_info != nullptr)
            {
                if(!HasDependencies(*plugin_info))
                    LoadPlugin(plugin_path, *plugin_info);
                else
                    LoadPluginRecursively(plugin_path, *plugin_info, plugins);
            }
            else
                MEE_LOGGER::Warn("Some plugins may have not been loaded.");
        }
    }

	void PluginManager::OnLoad()
	{
		for (auto plugin : m_loadedPluginList)
		{
			MEE_LOGGER::ScopedLogging log(plugin->pluginInformation.name);
			plugin->OnLoad();
		}
	}

	void PluginManager::OnUpdate()
	{
		for (auto plugin : m_loadedPluginList)
		{
			if (plugin->OnUpdate != nullptr)
			{
				MEE_LOGGER::ScopedLogging log(plugin->pluginInformation.name);
				plugin->OnUpdate();
			}
		}
	}

	void PluginManager::OnDraw()
	{
		for (auto plugin : m_loadedPluginList)
		{
			if (plugin->OnDraw != nullptr)
			{
				MEE_LOGGER::ScopedLogging log(plugin->pluginInformation.name);
				plugin->OnDraw();
			}
		}
	}

	void PluginManager::OnPostUpdate()
	{
		for (auto plugin : m_loadedPluginList)
		{
			if (plugin->OnPostUpdate != nullptr)
			{
				MEE_LOGGER::ScopedLogging log(plugin->pluginInformation.name);
				plugin->OnPostUpdate();
			}
		}
	}

	void PluginManager::Stop()
	{
		for (auto plugin : m_loadedPluginList) {
			MEE_LOGGER::ScopedLogging log(plugin->pluginInformation.name);
			plugin->OnShutdown();
		}
	}

	PluginManager::~PluginManager()
	{
		m_loadedPluginList.clear();
	}
}


