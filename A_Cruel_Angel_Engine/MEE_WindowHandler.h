#pragma once
#include <string>
#include"MEE_Graphics.h"

namespace MEE
{
	class WindowHandler
	{
	public:
		virtual bool Init() = 0;
		virtual void Stop() = 0;
		virtual void PollEvents() = 0;
		static void SetWindowSize(unsigned int w, unsigned int h);
		static void SetWindowPosition(int x, int y);
		static void SetWindowName(const std::string& name);
		static void SetHandlerAPI(const WindowHandlerAPI& api);
		static void SetRenderAPI(const RenderAPI& api);
		static WindowHandlerAPI GetHandlerAPI();
		static RenderAPI GetRenderAPI();
		virtual void SwapBuffer() = 0;
	protected:
		static unsigned int width, height;
		static int  pos_x, pos_y ;
		static std::string windowName;
		static WindowHandlerAPI handlerAPI;
		static RenderAPI renderAPI;
	};
}


