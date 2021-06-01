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
		PLUGIN_EXPORT void onInit(int);
		PLUGIN_EXPORT void onLoad();
		PLUGIN_EXPORT void onShutdown();
		PLUGIN_EXPORT void renderQuad();
		PLUGIN_EXPORT void renderTexture(MEE::Texture2D* tex, float x, float y,
										int clipX, int clipY, int clipW,
										int clipH,float a);
		PLUGIN_EXPORT MEE_Texture2D createTexture2D(const std::string path);
	}

	inline SDL_Renderer* engineRenderer;

	inline Basic_Texture2D* miTexture;

}

