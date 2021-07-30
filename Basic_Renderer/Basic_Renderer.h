#pragma once

#include <MEE_PluginHeader.h>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Basic_Texture2D.h"
#include <MEE_Graphics.h>

namespace Basic_Renderer
{
	extern "C"
	{
		PLUGIN_EXPORT void OnInit(int pl_id);
		PLUGIN_EXPORT void OnLoad();
		PLUGIN_EXPORT void OnShutdown();
		PLUGIN_EXPORT void RenderTexture(MEE_Texture2D tex, float x, float y, 
										float scale_x, float scale_y, float a,
										int clipX, int clipY, int clipW, int clipH);
		PLUGIN_EXPORT MEE_Texture2D CreateTexture2D(const std::string path);
		PLUGIN_EXPORT void SetRenderColor(int,int,int,int);
		PLUGIN_EXPORT void RenderClear();
		PLUGIN_EXPORT void SetRenderViewport(int,int,int,int);
		PLUGIN_EXPORT void RenderLine(int,int,int,int);
		PLUGIN_EXPORT void RenderPoint(int,int);
		PLUGIN_EXPORT void RenderPolygon(int*,int);
		PLUGIN_EXPORT void RenderSolidPolygon(int*,int);
		PLUGIN_EXPORT void RenderCircle(int,int,int);
		PLUGIN_EXPORT void RenderSolidCircle(int,int,int);
	}

	inline SDL_Renderer* engineRenderer;

	inline Basic_Texture2D* miTexture;

}

