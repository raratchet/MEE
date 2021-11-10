#pragma once

#include <MEE_PluginHeader.h>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Basic_Texture2D.h"
#include <MEE_Graphics.h>

namespace Basic_Renderer
{
	PLUGIN_FUNCTION void OnInit(int pl_id);
	PLUGIN_FUNCTION void OnLoad();
	PLUGIN_FUNCTION void OnShutdown();
	PLUGIN_FUNCTION void RenderTexture(MEE_Texture2D tex, float x, float y,
		float scale_x, float scale_y, float a,
		int clipX, int clipY, int clipW, int clipH,
		bool h_flip, bool v_flip);
	PLUGIN_FUNCTION MEE_Texture2D CreateTexture2D(const std::string path);
	PLUGIN_FUNCTION void SetRenderColor(int, int, int, int);
	PLUGIN_FUNCTION void RenderClear();
	PLUGIN_FUNCTION void SetRenderViewport(int, int, int, int);
	PLUGIN_FUNCTION void RenderLine(float, float, float, float);
	PLUGIN_FUNCTION void RenderPoint(float, float);
	PLUGIN_FUNCTION void RenderPolygon(std::vector<float> vertices);
	PLUGIN_FUNCTION void RenderSolidPolygon(std::vector<float> vertices);
	PLUGIN_FUNCTION void RenderCircle(float, float, float);
	PLUGIN_FUNCTION void RenderSolidCircle(float, float, float);
	PLUGIN_FUNCTION void RenderDebugGrid();

	inline SDL_Renderer* engineRenderer;

	inline Basic_Texture2D* miTexture;

}

