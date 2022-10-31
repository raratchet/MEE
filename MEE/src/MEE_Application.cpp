#include "MEE_Application.h"
#include "MEE_SDLHandler.h"
#include "MEE_GLFWHandler.h"
#include "MEE_Graphics.h"
#include "MEE_Global.h"
#include "MEE_Logging.h"


namespace MEE
{
	Application::Application()
	{
		MEE_GLOBAL::application = this;
		MEE_LOGGER::InitLogging();
		MEE_LOGGER::CreateLogger("MEG");
	}

	bool Application::Init()
	{
		bool success = true;


		pluginManager = std::make_unique<PluginManager>(PluginManager());

		if (!pluginManager->Init())
		{
			MEE_LOGGER::Fatal("Couldn't initialize Plugin Manager");
			return false;
		}

		if (WindowHandler::GetHandlerAPI() == WindowHandlerAPI::SDL)
			w_handler = std::make_unique<SDLHandler>(SDLHandler());
		else if (WindowHandler::GetHandlerAPI() == WindowHandlerAPI::GLFW)
			w_handler = std::make_unique<GLFWHandler>(GLFWHandler());
		else
			w_handler = std::make_unique<SDLHandler>(SDLHandler());

		resourceManager = std::make_unique<ResourceManager>(ResourceManager());
		sceneManager = std::make_unique<SceneManager>(SceneManager());
		inputManager = std::make_unique<InputManager>(InputManager());
		timeManager = std::make_unique<TimeManager>(TimeManager());
		renderManager = std::make_unique<RenderingManager>(RenderingManager());

		//El orden del init importa mucho
		if (!resourceManager->Init())
		{
			MEE_LOGGER::Fatal("An error has occurred in the Resource Manager");
			return false;
		}

		if (!renderManager->Init())
		{
			MEE_LOGGER::Fatal("Couldn't initialize Rendering Manager");
			return false;
		}

		if (!w_handler->Init())
		{
			MEE_LOGGER::Fatal("Couldn't initialize Window");
			return false;
		}

		if (!inputManager->Init())
		{
			MEE_LOGGER::Fatal("Couldn't initialize Input Manager");
			return false;
		}


		return success;
	}

	void Application::Load()
	{
        pluginManager->OnLoad();
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
        pluginManager->OnUpdate();
		//Do update
		auto scene = sceneManager->GetCurrentScene();
		scene->Update();
		//
		pluginManager->OnPostUpdate();
	}

	void Application::Draw()
	{
		MEE_RenderClear();
		//Do draw
		sceneManager->GetCurrentScene()->Draw();
        pluginManager->OnDraw();
		//
		w_handler->SwapBuffer();
	}

	void Application::CloseApplicationSignal()
	{
		exit = true;
	}

	WindowHandler* Application::GetWindow()
	{
		return w_handler.get();
	}

	PluginManager* MEE::Application::GetPluginManager()
	{
		return pluginManager.get();
	}

	ResourceManager* Application::GetResourceManager()
	{
		return resourceManager.get();
	}

	SceneManager* Application::GetSceneManager()
	{
		return sceneManager.get();
	}

	InputManager* Application::GetInputManager()
	{
		return inputManager.get();
	}

	TimeManager* Application::GetTimeManager()
	{
		return timeManager.get();
	}

	RenderingManager* Application::GetRenderManager()
	{
		return renderManager.get();
	}

	void Application::Stop()
	{
		pluginManager->Stop();
		w_handler->Stop();

		MEE_LOGGER::FlushLog();

		w_handler.reset();
		sceneManager.reset();
		renderManager.reset();
		inputManager.reset();
		timeManager.reset();
		resourceManager.reset();
		pluginManager.reset();

		MEE_GLOBAL::application = nullptr;
	}
}


