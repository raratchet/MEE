#include "MEE_Application.h"
#include "MEE_SDLHandler.h"
#include "MEE_GLFWHandler.h"
#include "MEE_Graphics.h"

//TEMP
#include "MEE_Global.h"

namespace MEE
{
	Application::Application()
	{
		MEE_GLOBAL::application = this;
	}

	bool Application::init()
	{
		bool success = true;


		pluginManager = std::make_shared<PluginManager>(PluginManager());

		if (!pluginManager->init())
		{
			std::cout<< "Couldn't initialize Plugin Manager";
			success = false;
		}

		if (WindowHandler::getHandlerAPI() == WindowHandlerAPI::SDL)
			w_handler = std::make_shared<SDLHandler>(SDLHandler());
		else if (WindowHandler::getHandlerAPI() == WindowHandlerAPI::GLFW)
			w_handler = std::make_shared<GLFWHandler>(GLFWHandler());
		else
			w_handler = std::make_shared<SDLHandler>(SDLHandler());

		if (!w_handler->init())
		{
			std::cout << "Couldn't initialize Window \n";
			success = false;
		}

		resourceManager = std::make_shared<ResourceManager>(ResourceManager());

		if (!resourceManager->init())
		{
			std::cout << "An error has ocurr in the Resource Manager \n";
			success = false;
		}

		//Sus verificaciones
		sceneManager = std::make_shared<SceneManager>(SceneManager());
		inputManager = std::make_shared<InputManager>(InputManager());
		return success;
	}

	void Application::load()
	{
		pluginManager->load();
	}


	void Application::loop()
	{
		//Temp
		std::function<void()> quad = pluginManager->getPluginFunction<void>(0, "renderQuad");
		//
		while (!exit)
		{
			//w_handler->pollEvents();
			update();
			draw();
		}
	}

	void Application::update()
	{
		pluginManager->update();
		//Do update
		sceneManager->getCurrentScene()->update();
		//
		pluginManager->postUpdate();
	}

	void Application::draw()
	{
		MEE_renderClear();
		//Do draw
		sceneManager->getCurrentScene()->draw();
		//
		w_handler->swapBuffer();
	}

	std::weak_ptr<WindowHandler> Application::getWindow()
	{
		return w_handler;
	}

	std::weak_ptr<PluginManager> MEE::Application::getPluginManager()
	{
		return pluginManager;
	}

	std::weak_ptr<ResourceManager> Application::getResourceManager()
	{
		return resourceManager;
	}

	std::weak_ptr<SceneManager> Application::getSceneManager()
	{
		return sceneManager;
	}

	std::weak_ptr<InputManager> Application::getInputManager()
	{
		return inputManager;
	}

	void Application::stop()
	{
		pluginManager->stop();
		w_handler->stop();
	}
}


