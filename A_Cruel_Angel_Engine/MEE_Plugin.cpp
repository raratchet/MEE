#include "MEE_Plugin.h"

namespace MEE
{

	Plugin::Plugin(std::filesystem::path filename, const PluginInformation& info)
	{
		m_lib = PLUGIN_PROGRAM_HANDLE;

		pluginInformation = info;

		if (!m_lib) {
			throw "[MEE] Unable to load Plugin!";
		}

		std::cout << "[MEE] Loading "<< info.name << " version "<< info.version << std::endl;

		OnInit = (onInitType)PLUGIN_LOAD_EXTERN(m_lib, "OnInit");
		OnLoad = (onLoadType)PLUGIN_LOAD_EXTERN(m_lib, "OnLoad");
		OnShutdown = (onShutdownType)PLUGIN_LOAD_EXTERN(m_lib, "OnShutdown");
		//Revisar si estos existen
		OnUpdate = (onUpdateType)PLUGIN_LOAD_EXTERN(m_lib, "OnUpdate");
		OnUpdate = (onDrawType)PLUGIN_LOAD_EXTERN(m_lib, "OnDraw");
		OnPostUpdate = (onPostUpdateType)PLUGIN_LOAD_EXTERN(m_lib, "OnPostUpdate");
	}


	Plugin::~Plugin()
	{
		std::cout << "[MEE] Shutting down Plugin" << std::endl;

		PLUGIN_CLOSE_EXTERN(m_lib);
	}

}

