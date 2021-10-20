#include "MEE_Plugin.h"
#include "MEE_Logging.h"

namespace MEE
{

	Plugin::Plugin(std::filesystem::path filename, const PluginInformation& info)
	{
		m_lib = PLUGIN_PROGRAM_HANDLE;

		pluginInformation = info;

		if (!m_lib)
			throw "Unable to load Plugin!";

		MEE_LOGGER::Log("Loading " + info.name + " version " + info.version);

		OnInit = (onInitType)PLUGIN_LOAD_EXTERN(m_lib, "OnInit");
		OnLoad = (onLoadType)PLUGIN_LOAD_EXTERN(m_lib, "OnLoad");
		OnShutdown = (onShutdownType)PLUGIN_LOAD_EXTERN(m_lib, "OnShutdown");
		
		if (!(OnInit && OnLoad && OnShutdown))
			throw "Error while loading plugin missing Functions";

		OnUpdate = (onUpdateType)PLUGIN_LOAD_EXTERN(m_lib, "OnUpdate");
		OnDraw = (onDrawType)PLUGIN_LOAD_EXTERN(m_lib, "OnDraw");
		OnPostUpdate = (onPostUpdateType)PLUGIN_LOAD_EXTERN(m_lib, "OnPostUpdate");
	}


	Plugin::~Plugin()
	{
		MEE_LOGGER::Log("Shutting down " + pluginInformation.name);

		PLUGIN_CLOSE_EXTERN(m_lib);
	}

}

