#include "MEE_WindowHandler.h"

unsigned int  MEE::WindowHandler::width = 800, MEE::WindowHandler::height = 600;
int MEE::WindowHandler::pos_x = 100, MEE::WindowHandler::pos_y = 100;
std::string MEE::WindowHandler::windowName = "MEE";
WindowHandlerAPI MEE::WindowHandler::handlerAPI = WindowHandlerAPI::SDL;
RenderAPI MEE::WindowHandler::renderAPI = RenderAPI::OpenGL;

void MEE::WindowHandler::setWindowSize(unsigned int w, unsigned int h)
{
	width = w;
	height = h;
}

void MEE::WindowHandler::setWindowPosition(int x, int y)
{
	pos_x = x;
	pos_y = y;
}

void MEE::WindowHandler::setWindowName(const std::string& name)
{
	windowName = name;
}

void MEE::WindowHandler::setHandlerAPI(const WindowHandlerAPI& api)
{
	handlerAPI = api;
}

void MEE::WindowHandler::setRenderAPI(const RenderAPI& api)
{
	renderAPI = api;
}

WindowHandlerAPI MEE::WindowHandler::getHandlerAPI()
{
	return handlerAPI;
}

RenderAPI MEE::WindowHandler::getRenderAPI()
{
	return renderAPI;
}

