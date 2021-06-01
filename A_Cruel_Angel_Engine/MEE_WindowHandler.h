#pragma once
#include <string>
#include"MEE_Graphics.h"

namespace MEE
{
	class WindowHandler
	{
	public:
		virtual bool init() = 0;
		virtual void stop() = 0;
		virtual void pollEvents() = 0;
		static void setWindowSize(unsigned int w, unsigned int h);
		static void setWindowPosition(int x, int y);
		static void setWindowName(const std::string& name);
		static void setHandlerAPI(const WindowHandlerAPI& api);
		static void setRenderAPI(const RenderAPI& api);
		static WindowHandlerAPI getHandlerAPI();
		static RenderAPI getRenderAPI();
		virtual void swapBuffer() = 0;
	protected:
		static unsigned int width, height;
		static int  pos_x, pos_y ;
		static std::string windowName;
		static WindowHandlerAPI handlerAPI;
		static RenderAPI renderAPI;
	};
}


