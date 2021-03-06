#include "MEE_WindowHandler.h"
#include"MEE_Graphics.h"

unsigned int  MEE::WindowHandler::width = 800, MEE::WindowHandler::height = 600;
int MEE::WindowHandler::pos_x = 100, MEE::WindowHandler::pos_y = 100;
std::string MEE::WindowHandler::windowName = "MEE";
WindowHandlerAPI handlerAPI = WindowHandlerAPI::SDL;
RenderAPI renderAPI = RenderAPI::OpenGL;
bool MEE::WindowHandler::fullscreened = false;

void MEE::WindowHandler::SetWindowSize(unsigned int w, unsigned int h)
{
	width = w;
	height = h;
}

void MEE::WindowHandler::SetWindowPosition(int x, int y)
{
	pos_x = x;
	pos_y = y;
}

void MEE::WindowHandler::SetWindowName(const std::string& name)
{
	windowName = name;
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
	*w = width;
	*h = height;
}

void MEE::WindowHandler::SetFullscreenMode(bool mode)
{
	fullscreened = mode;
}

bool MEE::WindowHandler::GetFullscreenMode()
{
	return fullscreened;
}

WindowHandlerAPI MEE::WindowHandler::GetHandlerAPI()
{
	return handlerAPI;
}

RenderAPI MEE::WindowHandler::GetRenderAPI()
{
	return renderAPI;
}

