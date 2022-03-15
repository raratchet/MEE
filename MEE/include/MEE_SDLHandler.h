/*****************************************************************//**
 * \file   MEE_SDLHandler.h
 * \brief  
 * 
 * \author Maximiliano Herrera
 * \date   October 2021
 *********************************************************************/
#pragma once
#include <string>
#include <SDL.h>
#include <memory>

#include "MEE_WindowHandler.h"

namespace MEE
{
	/**
	 * Concrete WindowHandler for SDL API.
	 */
	class SDLHandler : public WindowHandler
	{
	public:
		virtual bool Init() override;
		virtual void Stop() override;
		virtual void SwapBuffer() override;
		virtual void RefreshWindow() override;
		void SDL_Render_RenderClear();
        SDL_Renderer* GetRenderer();

    private:
		SDL_Window* m_window;
		SDL_GLContext m_glContext;
		SDL_Renderer* m_sdlRenderer;
		SDL_Surface* m_sdlSurface;
	};
}


