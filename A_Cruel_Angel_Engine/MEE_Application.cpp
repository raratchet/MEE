#include "MEE_Application.h"
#include "MEE_SDLHandler.h"
#include "MEE_GLFWHandler.h"
#include "MEE_Graphics.h"
#include "MEE_Physics.h"

//TEMP
#include "MEE_Global.h"

namespace MEE
{
	Application::Application()
	{
		MEE_GLOBAL::application = this;
	}

	bool Application::Init()
	{
		bool success = true;


		pluginManager = std::make_shared<PluginManager>(PluginManager());

		if (!pluginManager->Init())
		{
			std::cout<< "Couldn't initialize Plugin Manager";
			success = false;
		}

		if (WindowHandler::GetHandlerAPI() == WindowHandlerAPI::SDL)
			w_handler = std::make_shared<SDLHandler>(SDLHandler());
		else if (WindowHandler::GetHandlerAPI() == WindowHandlerAPI::GLFW)
			w_handler = std::make_shared<GLFWHandler>(GLFWHandler());
		else
			w_handler = std::make_shared<SDLHandler>(SDLHandler());

		if (!w_handler->Init())
		{
			std::cout << "Couldn't initialize Window \n";
			success = false;
		}

		resourceManager = std::make_shared<ResourceManager>(ResourceManager());

		if (!resourceManager->Init())
		{
			std::cout << "An error has ocurr in the Resource Manager \n";
			success = false;
		}

		//Sus verificaciones
		sceneManager = std::make_shared<SceneManager>(SceneManager());
		inputManager = std::make_shared<InputManager>(InputManager());
		return success;
	}

	void Application::Load()
	{
		pluginManager->Load();
	}


	void Application::Loop()
	{
		while (!exit)
		{
			Update();
			Draw();
		}
	}

	void Application::Update()
	{
		pluginManager->Update();
		//Do update
		auto scene = sceneManager->GetCurrentScene();
		MEE_PhysicsStep(scene->GetID());
		scene->Update();
		//
		pluginManager->PostUpdate();
	}

	void Application::Draw()
	{
		MEE_RenderClear();
		//Do draw
		sceneManager->GetCurrentScene()->Draw();
		//
		w_handler->SwapBuffer();
	}

	std::weak_ptr<WindowHandler> Application::GetWindow()
	{
		return w_handler;
	}

	std::weak_ptr<PluginManager> MEE::Application::GetPluginManager()
	{
		return pluginManager;
	}

	std::weak_ptr<ResourceManager> Application::GetResourceManager()
	{
		return resourceManager;
	}

	std::weak_ptr<SceneManager> Application::GetSceneManager()
	{
		return sceneManager;
	}

	std::weak_ptr<InputManager> Application::GetInputManager()
	{
		return inputManager;
	}

	void Application::Stop()
	{
		pluginManager->Stop();
		w_handler->Stop();
	}
}


