/*****************************************************************//**
 * \file   MEE_WindowHandler.h
 * \brief  
 * 
 * \author Maximiliano Herrera
 * \date   November 2021
 *********************************************************************/
#pragma once
#include <string>

enum class WindowHandlerAPI;
enum class RenderAPI;

namespace MEE
{
	/**
	 * Base class for window handling.
	 * The window handler API dictates the Input API as well.
	 */
	class WindowHandler
	{
	public:
		virtual bool Init() = 0;
		virtual void Stop() = 0;
		static void SetWindowSize(unsigned int w, unsigned int h);
		static void SetWindowPosition(int x, int y);
		static void SetWindowName(const std::string& name);
		static void SetHandlerAPI(const WindowHandlerAPI& api);
		static void SetRenderAPI(const RenderAPI& api);
		static void GetWindowSize(int* w, int* h);
		static void SetFullscreenMode(bool mode);
		static bool GetFullscreenMode();
		static WindowHandlerAPI GetHandlerAPI();
		static RenderAPI GetRenderAPI();
		virtual void SwapBuffer() = 0;
		virtual void RefreshWindow() = 0;
	protected:
		static unsigned int width, height;
		static bool fullscreened;
		static int pos_x, pos_y ;
		static std::string windowName;
	};
}


