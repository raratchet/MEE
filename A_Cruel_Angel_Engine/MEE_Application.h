#pragma once
#include<memory>
#include<string>
#include<iostream>

#include "MEE_WindowHandler.h"
#include "MEE_PluginManager.h"
#include "MEE_Resources.h"
#include "MEE_SceneManager.h"
#include "MEE_InputManager.h"
#include "MEE_Time.h"

namespace MEE
{
	class MEE_EXPORT Application
	{
	public:
		Application();
		~Application() = default;
		bool Init();
		void Load();
		void Stop();
		void Loop();
		void Update();
		void Draw();
		void CloseApplicationSignal();
		std::weak_ptr<WindowHandler> GetWindow();
		std::weak_ptr<PluginManager> GetPluginManager();
		std::weak_ptr<ResourceManager> GetResourceManager();
		std::weak_ptr<SceneManager> GetSceneManager();
		std::weak_ptr<InputManager> GetInputManager();
		std::weak_ptr<TimeManager> GetTimeManager();
	private:
		bool exit = false;
		std::shared_ptr<SceneManager> sceneManager;
		std::shared_ptr<WindowHandler> w_handler;
		std::shared_ptr<PluginManager>pluginManager;
		std::shared_ptr<ResourceManager> resourceManager;
		std::shared_ptr<InputManager> inputManager;
		std::shared_ptr<TimeManager> timeManager;
	};
}


