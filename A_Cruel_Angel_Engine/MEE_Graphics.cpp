#include "MEE_Graphics.h"
#include "MEE_Global.h"
#include "MEE_WindowHandler.h"
#include "MEE_SDLHandler.h"
#include <memory>
#include<iostream>

	void MEE_setWindowHandlerAPI(const WindowHandlerAPI& api)
	{
		MEE::WindowHandler::setHandlerAPI(api);
	}

	void MEE_setRenderAPI(const RenderAPI& api)
	{
		MEE::WindowHandler::setRenderAPI(api);
	}

	void MEE_setWindowSize(unsigned int w, unsigned int h)
	{
		MEE::WindowHandler::setWindowSize(w, h);
	}

	void MEE_setWindowPosition(int x, int y)
	{
		MEE::WindowHandler::setWindowPosition(x,y);
	}

	void MEE_setWindowName(const std::string& name)
	{
		MEE::WindowHandler::setWindowName(name);
	}

	void MEE_bindRenderClear(int plugin_id, const std::string& func_name)
	{
		auto pl_manager = MEE_GLOBAL::application->getPluginManager().lock();

		if (pl_manager)
		{
			MEE_renderClear = pl_manager->getPluginFunction<void>(plugin_id, func_name);
		}

	}  

	void MEE_bindCreateTexture2D(int plugin_id, const std::string& func_name)
	{
		auto pl_manager = MEE_GLOBAL::application->getPluginManager().lock();

		if (pl_manager)
		{
			MEE_createTexture2D = pl_manager->getPluginFunction
				<MEE_Texture2D,const std::string&>(plugin_id, func_name);
		}

	}

	void MEE_bindRenderTexture2D(int plugin_id, const std::string& func_name)
	{
		auto pl_manager = MEE_GLOBAL::application->getPluginManager().lock();

		if (pl_manager)
		{
			MEE_renderTexture2D = pl_manager->getPluginFunction
				<void,const MEE::Texture2D&, float, float,
				int,int,int,int,float>(plugin_id, func_name);
		}

	}

	void MEE_bindinitGL(int plugin_id, const std::string& func_name)
	{
		auto pl_manager = MEE_GLOBAL::application->getPluginManager().lock();

		if (pl_manager)
		{
			MEE_initGL = pl_manager->getPluginFunction<void>(plugin_id, func_name);
		}
	}

	MEE_SDL_Renderer MEE_EXPORT MEE_getSDLRenderer()
	{
		MEE_SDL_Renderer ptr = nullptr;
		if (MEE::WindowHandler::getRenderAPI() == RenderAPI::SDL_Render)
		{
			auto window = MEE_GLOBAL::application->getWindow().lock();

			if (window)
			{
				auto sdlHandler = std::reinterpret_pointer_cast<MEE::SDLHandler>(window);
				ptr = (void*) sdlHandler->sdlRenderer;
			}
		}
		return ptr;
	}


