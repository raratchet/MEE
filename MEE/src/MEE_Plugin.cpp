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

			MEE_LOGGER::Log(std::string("Loading " + info.name + " version " + info.version).c_str());

			OnInit = (onInitType)PLUGIN_LOAD_EXTERN(m_lib, "OnInit");
			OnLoad = (onLoadType)PLUGIN_LOAD_EXTERN(m_lib, "OnLoad");
			OnShutdown = (onShutdownType)PLUGIN_LOAD_EXTERN(m_lib, "OnShutdown");

			if (!(OnInit && OnLoad && OnShutdown))
				throw "Error while loading plugin. Missing Functions";

			OnUpdate = (onUpdateType)PLUGIN_LOAD_EXTERN(m_lib, "OnUpdate");
			OnDraw = (onDrawType)PLUGIN_LOAD_EXTERN(m_lib, "OnDraw");
			OnPostUpdate = (onPostUpdateType)PLUGIN_LOAD_EXTERN(m_lib, "OnPostUpdate");
			pluginInformation.loaded = true;
		}
		catch (...)
		{
			MEE_LOGGER::Error(std::string("Not able to load plugin: " + info.name).c_str());
			pluginInformation.loaded = false;
		}

	}


	Plugin::~Plugin()
	{
		MEE_LOGGER::Log(std::string("Shutting down " + pluginInformation.name).c_str());

		PLUGIN_CLOSE_EXTERN(m_lib);
	}

}

