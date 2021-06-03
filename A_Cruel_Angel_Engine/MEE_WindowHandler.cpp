#include "MEE_WindowHandler.h"

unsigned int  MEE::WindowHandler::width = 800, MEE::WindowHandler::height = 600;
int MEE::WindowHandler::pos_x = 100, MEE::WindowHandler::pos_y = 100;
std::string MEE::WindowHandler::windowName = "MEE";
WindowHandlerAPI MEE::WindowHandler::handlerAPI = WindowHandlerAPI::SDL;
RenderAPI MEE::WindowHandler::renderAPI = RenderAPI::OpenGL;

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

WindowHandlerAPI MEE::WindowHandler::GetHandlerAPI()
{
	return handlerAPI;
}

RenderAPI MEE::WindowHandler::getRenderAPI()
{
	return renderAPI;
}

