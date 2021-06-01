#pragma once
#include <SDL.h>
#include <memory>

#include "MEE_WindowHandler.h"

namespace MEE
{
	class SDLHandler : public WindowHandler
	{
	public:
		virtual bool init() override;
		virtual void stop() override;
		virtual void pollEvents() override;
		virtual void swapBuffer() override;
		void SDL_Render_RenderClear();

		//Pasarlo a private
		SDL_Window* window;
		SDL_GLContext glContext;
		SDL_Renderer* sdlRenderer;
		SDL_Surface* sdlSurface;
	private:
	};
}


