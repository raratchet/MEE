#pragma once

#include<MEE_PluginHeader.h>
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include"Basic_Texture2D.h"
#include <MEE_Graphics.h>

namespace Basic_Renderer
{
	extern "C"
	{
		PLUGIN_EXPORT void OnInit(int);
		PLUGIN_EXPORT void OnLoad();
		PLUGIN_EXPORT void OnShutdown();
		PLUGIN_EXPORT void renderTexture(MEE_Texture2D tex, float x, float y,
										int clipX, int clipY, int clipW,
										int clipH,float a);
		PLUGIN_EXPORT MEE_Texture2D createTexture2D(const std::string path);
	}

	inline SDL_Renderer* engineRenderer;

	inline Basic_Texture2D* miTexture;

}

