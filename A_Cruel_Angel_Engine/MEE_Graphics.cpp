#include "MEE_Graphics.h"
#include "MEE_Global.h"
#include "MEE_WindowHandler.h"
#include "MEE_SDLHandler.h"
#include <memory>
#include<iostream>

	void MEE_SetWindowHandlerAPI(const WindowHandlerAPI& api)
	{
		MEE::WindowHandler::SetHandlerAPI(api);
	}

	void MEE_SetRenderAPI(const RenderAPI& api)
	{
		MEE::WindowHandler::SetRenderAPI(api);
	}

	void MEE_SetWindowSize(unsigned int w, unsigned int h)
	{
		MEE::WindowHandler::SetWindowSize(w, h);
	}

	void MEE_SetWindowPosition(int x, int y)
	{
		MEE::WindowHandler::SetWindowPosition(x,y);
	}

	void MEE_SetWindowName(const std::string& name)
	{
		MEE::WindowHandler::SetWindowName(name);
	}

	void MEE_bind_RenderClear(int plugin_id, const std::string& func_name)
	{
		auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

		if (pl_manager)
		{
			MEE_RenderClear = pl_manager->GetPluginFunction<void>(plugin_id, func_name);
		}

	}  

	void MEE_bind_CreateTexture2D(int plugin_id, const std::string& func_name)
	{
		auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

		if (pl_manager)
		{
			MEE_CreateTexture2D = pl_manager->GetPluginFunction
				<MEE_Texture2D,const std::string&>(plugin_id, func_name);
		}

	}

	void MEE_bind_RenderTexture2D(int plugin_id, const std::string& func_name)
	{
		auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

		if (pl_manager)
		{
			MEE_RenderTexture2D = pl_manager->GetPluginFunction
				<void,const MEE_Texture2D, float, float, float, float, float,
				int,int,int,int>(plugin_id, func_name);
		}

	}

	void MEE_EXPORT MEE_bind_SetRenderColor(int plugin_id, const std::string& func_name)
	{
		auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

		if (pl_manager)
		{
			MEE_SetRenderColor = pl_manager->GetPluginFunction
				<void,int,int,int,int>(plugin_id, func_name);
		}
	}

	void MEE_EXPORT MEE_bind_SetRenderViewport(int plugin_id, const std::string& func_name)
	{
		auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

		if (pl_manager)
		{
			MEE_SetRenderViewport = pl_manager->GetPluginFunction
				<void,int,int,int,int>(plugin_id, func_name);
		}
	}

	void MEE_EXPORT MEE_bind_RenderLine(int plugin_id, const std::string& func_name)
	{
		auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

		if (pl_manager)
		{
			MEE_RenderLine = pl_manager->GetPluginFunction
				<void,int,int,int,int>(plugin_id, func_name);
		}
	}

	void MEE_EXPORT MEE_bind_RenderPoint(int plugin_id, const std::string& func_name)
	{
		auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

		if (pl_manager)
		{
			MEE_RenderPoint = pl_manager->GetPluginFunction
				<void,int,int>(plugin_id, func_name);
		}
	}

	void MEE_EXPORT MEE_bind_RenderPolygon(int plugin_id, const std::string& func_name)
	{
		auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

		if (pl_manager)
		{
			MEE_RenderPolygon = pl_manager->GetPluginFunction
				<void,int*,int>(plugin_id, func_name);
		}
	}

	void MEE_EXPORT MEE_bind_RenderSolidPolygon(int plugin_id, const std::string& func_name)
	{
		auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

		if (pl_manager)
		{
			MEE_RenderSolidPolygon = pl_manager->GetPluginFunction
				<void, int*, int>(plugin_id, func_name);
		}
	}

	void MEE_EXPORT MEE_bind_RenderCircle(int plugin_id, const std::string& func_name)
	{
		auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

		if (pl_manager)
		{
			MEE_RenderCircle = pl_manager->GetPluginFunction
				<void,int,int,int>(plugin_id, func_name);
		}
	}

	void MEE_EXPORT MEE_bind_RenderSolidCircle(int plugin_id, const std::string& func_name)
	{
		auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

		if (pl_manager)
		{
			MEE_RenderSolidCircle = pl_manager->GetPluginFunction
				<void,int,int,int>(plugin_id, func_name);
		}
	}

	void MEE_bind_InitGL(int plugin_id, const std::string& func_name)
	{
		auto pl_manager = MEE_GLOBAL::application->GetPluginManager().lock();

		if (pl_manager)
		{
			MEE_InitGL = pl_manager->GetPluginFunction<void>(plugin_id, func_name);
		}
	}

	MEE_SDL_Renderer MEE_EXPORT MEE_GetSDLRenderer()
	{
		MEE_SDL_Renderer ptr = nullptr;
		if (MEE::WindowHandler::GetRenderAPI() == RenderAPI::SDL_Render)
		{
			auto window = MEE_GLOBAL::application->GetWindow().lock();

			if (window)
			{
				auto sdlHandler = std::reinterpret_pointer_cast<MEE::SDLHandler>(window);
				ptr = (void*) sdlHandler->sdlRenderer;
			}
		}
		return ptr;
	}


