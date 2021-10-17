/*****************************************************************//**
 * \file   MEE_SDLHandler.h
 * \brief  
 * 
 * \author Maximiliano Herrera
 * \date   October 2021
 *********************************************************************/
#pragma once
#include <SDL.h>
#include <memory>

#include "MEE_WindowHandler.h"

namespace MEE
{
	class SDLHandler : public WindowHandler
	{
	public:
		virtual bool Init() override;
		virtual void Stop() override;
		virtual void SwapBuffer() override;
		virtual void RefreshWindow() override;
		void SDL_Render_RenderClear();

		SDL_Window* window;
		SDL_GLContext glContext;
		SDL_Renderer* sdlRenderer;
		SDL_Surface* sdlSurface;
	};
}


