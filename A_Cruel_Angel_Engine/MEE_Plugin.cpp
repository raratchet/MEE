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

		onInit = (onInitType)PLUGIN_LOAD_EXTERN(m_lib, "onInit");
		onLoad = (onLoadType)PLUGIN_LOAD_EXTERN(m_lib, "onLoad");
		onShutdown = (onShutdownType)PLUGIN_LOAD_EXTERN(m_lib, "onShutdown");
		//Revisar si estos existen
		onUpdate = (onUpdateType)PLUGIN_LOAD_EXTERN(m_lib, "onUpdate");
		onPostUpdate = (onPostUpdateType)PLUGIN_LOAD_EXTERN(m_lib, "onPostUpdate");
	}


	Plugin::~Plugin()
	{
		std::cout << "[MEE] Shutting down Plugin" << std::endl;

		PLUGIN_CLOSE_EXTERN(m_lib);
	}

}

