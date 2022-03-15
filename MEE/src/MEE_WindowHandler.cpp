#include "MEE_WindowHandler.h"
#include"MEE_Graphics.h"

unsigned int  MEE::WindowHandler::m_width = 800, MEE::WindowHandler::m_height = 600;
int MEE::WindowHandler::m_x = 100, MEE::WindowHandler::m_y = 100;
std::string MEE::WindowHandler::m_windowName = "MEE";
WindowHandlerAPI handlerAPI = WindowHandlerAPI::SDL;
RenderAPI renderAPI = RenderAPI::OpenGL;
bool MEE::WindowHandler::m_fullscreenned = false;

void MEE::WindowHandler::SetWindowSize(unsigned int w, unsigned int h)
{
    m_width = w;
    m_height = h;
}

void MEE::WindowHandler::SetWindowPosition(int x, int y)
{
    m_x = x;
    m_y = y;
}

void MEE::WindowHandler::SetWindowName(const std::string& name)
{
    m_windowName = name;
}

void MEE::WindowHandler::SetHandlerAPI(const WindowHandlerAPI& api)
{
	handlerAPI = api;
}

void MEE::WindowHandler::SetRenderAPI(const RenderAPI& api)
{
	renderAPI = api;
}

void MEE::WindowHandler::GetWindowSize(int* w, int* h)
{
	*w = m_width;
	*h = m_height;
}

void MEE::WindowHandler::SetFullscreenMode(bool mode)
{
    m_fullscreenned = mode;
}

bool MEE::WindowHandler::GetFullscreenMode()
{
	return m_fullscreenned;
}

WindowHandlerAPI MEE::WindowHandler::GetHandlerAPI()
{
	return handlerAPI;
}

RenderAPI MEE::WindowHandler::GetRenderAPI()
{
	return renderAPI;
}

