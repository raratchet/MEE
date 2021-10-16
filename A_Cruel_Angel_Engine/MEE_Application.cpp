#include "MEE_Application.h"
#include "MEE_SDLHandler.h"
#include "MEE_GLFWHandler.h"
#include "MEE_Graphics.h"
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
			std::cout<< "[MEE] Couldn't initialize Plugin Manager \n";
			return false;
		}

		if (WindowHandler::GetHandlerAPI() == WindowHandlerAPI::SDL)
			w_handler = std::shared_ptr<SDLHandler>(new SDLHandler());
		else if (WindowHandler::GetHandlerAPI() == WindowHandlerAPI::GLFW)
			w_handler = std::shared_ptr<GLFWHandler>(new GLFWHandler());
		else
			w_handler = std::shared_ptr<SDLHandler>(new SDLHandler());


		resourceManager = std::shared_ptr<ResourceManager>(new ResourceManager());
		sceneManager = std::shared_ptr<SceneManager>(new SceneManager());
		inputManager = std::shared_ptr<InputManager>(new InputManager());
		timeManager = std::shared_ptr<TimeManager>(new TimeManager());
		renderManager = std::shared_ptr<RenderingManager>(new RenderingManager());

		//El orden del init importa mucho
		if (!resourceManager->Init())
		{
			std::cout << "[MEE] An error has ocurr in the Resource Manager \n";
			return false;
		}

		if (!renderManager->Init())
		{
			std::cout << "[MEE] Couldn't initialize Rendering Manager \n";
			return false;
		}

		if (!w_handler->Init())
		{
			std::cout << "[MEE] Couldn't initialize Window \n";
			return false;
		}

		if (!inputManager->Init())
		{
			std::cout << "[MEE] Couldn't initialize Input Manager \n";
			return false;
		}


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
			timeManager->StartFrame();
			Update();
			Draw();
			timeManager->EndFrame();
		}
	}

	void Application::Update()
	{
		pluginManager->Update();
		//Do update
		auto scene = sceneManager->GetCurrentScene();
		scene->Update();
		//
		pluginManager->PostUpdate();
	}

	void Application::Draw()
	{
		MEE_RenderClear();
		//Do draw
		sceneManager->GetCurrentScene()->Draw();
		pluginManager->Draw();
		//
		w_handler->SwapBuffer();
	}

	void Application::CloseApplicationSignal()
	{
		exit = true;
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

	std::weak_ptr<TimeManager> Application::GetTimeManager()
	{
		return timeManager;
	}

	std::weak_ptr<RenderingManager> Application::GetRenderManager()
	{
		return renderManager;
	}

	void Application::Stop()
	{
		pluginManager->Stop();
		w_handler->Stop();

		w_handler.reset();
		renderManager.reset();
		inputManager.reset();
		sceneManager.reset();
		timeManager.reset();
		resourceManager.reset();
		pluginManager.reset();

		MEE_GLOBAL::application = nullptr;
	}
}


