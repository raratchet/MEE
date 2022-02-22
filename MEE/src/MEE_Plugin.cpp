#include "MEE_Plugin.h"
#include "MEE_Logging.h"
#include "MEE_PluginManager.h"

namespace MEE
{

	Plugin::Plugin(std::filesystem::path filename, const PluginInformation& info)
	{
		try
		{
			m_lib = PLUGIN_PROGRAM_HANDLE;

			pluginInformation = info;

			if (!m_lib)
				throw "Unable to load Plugin!";

            if(info.type == PluginType::MODULE)
                LoadAsModule();
            else if (info.type == PluginType::ADDON)
                LoadAsAddon();
            else
                throw "Unable to load Plugin! Unknown type";
		}
		catch (...)
		{
			MEE_LOGGER::Error("Not able to load plugin: " + info.name);
			pluginInformation.loaded = false;
		}

	}


	Plugin::~Plugin()
	{
		MEE_LOGGER::Log("Shutting down " + pluginInformation.name);

		PLUGIN_CLOSE_EXTERN(m_lib);
	}

    void Plugin::LoadAsModule()
    {
        MEE_LOGGER::Log("Loading module " + pluginInformation.name +
        " version: " + pluginInformation.version +
        " by: " + pluginInformation.author);

        OnInit = (onInitType)PLUGIN_LOAD_EXTERN(m_lib, "OnInit");
        OnLoad = (onLoadType)PLUGIN_LOAD_EXTERN(m_lib, "OnLoad");
        OnShutdown = (onShutdownType)PLUGIN_LOAD_EXTERN(m_lib, "OnShutdown");

        if (!(OnInit && OnLoad && OnShutdown))
            throw "Error while loading module. Missing Functions";

        OnUpdate = (onUpdateType)PLUGIN_LOAD_EXTERN(m_lib, "OnUpdate");
        OnDraw = (onDrawType)PLUGIN_LOAD_EXTERN(m_lib, "OnDraw");
        OnPostUpdate = (onPostUpdateType)PLUGIN_LOAD_EXTERN(m_lib, "OnPostUpdate");
        pluginInformation.loaded = true;
    }

    void Plugin::LoadAsAddon()
    {
        MEE_LOGGER::Log("Loading addon " + pluginInformation.name + " version " + pluginInformation.version);

        OnInit = (onInitType)PLUGIN_LOAD_EXTERN(m_lib, "OnInit");
        OnLoad = (onLoadType)PLUGIN_LOAD_EXTERN(m_lib, "OnLoad");
        OnShutdown = (onShutdownType)PLUGIN_LOAD_EXTERN(m_lib, "OnShutdown");

        if (!(OnInit))
            throw "Error while loading addon. Missing Functions";

        if(!(OnLoad))
            MEE_LOGGER::Warn(pluginInformation.name + " is missing OnLoad function!");

        if(!(OnShutdown))
            MEE_LOGGER::Warn(pluginInformation.name + " is missing OnShutdown function!");

        OnUpdate = (onUpdateType)PLUGIN_LOAD_EXTERN(m_lib, "OnUpdate");
        OnDraw = (onDrawType)PLUGIN_LOAD_EXTERN(m_lib, "OnDraw");
        OnPostUpdate = (onPostUpdateType)PLUGIN_LOAD_EXTERN(m_lib, "OnPostUpdate");
        pluginInformation.loaded = true;
    }

}

