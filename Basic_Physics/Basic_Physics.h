#pragma once
#include<MEE_PluginHeader.h>
#include<set>

namespace Basic_Physics
{
	extern "C"
	{
		PLUGIN_EXPORT void OnInit(int);
		PLUGIN_EXPORT void OnLoad();
		PLUGIN_EXPORT void OnShutDown();
		PLUGIN_EXPORT void OnUpdate();


	}


}
