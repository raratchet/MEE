#pragma once
#include<memory>
#include<string>
#include<iostream>

#include "MEE_WindowHandler.h"
#include "MEE_PluginManager.h"
#include "MEE_Resources.h"
#include "MEE_SceneManager.h"
#include "MEE_InputManager.h"

namespace MEE
{
	class MEE_EXPORT Application
	{
	public:
		Application();
		~Application() = default;
		bool init();
		void load();
		void stop();
		void loop();
		void update();
		void draw();
		std::weak_ptr<WindowHandler> getWindow();
		std::weak_ptr<PluginManager> getPluginManager();
		std::weak_ptr<ResourceManager> getResourceManager();
		//Leer el comentario de abajo
		std::weak_ptr<SceneManager> getSceneManager();
		std::weak_ptr<InputManager> getInputManager();
		/*El scene manager debe ser acesible desde el lado del
		* juego pordria facilitar su acceso creando un clase singleton
		* que facilite su uso y controle sus llamadas de una mejor forma
		* 
		* por ahora esto se queda asi con la finalidad de poder probar
	    */
	private:
		bool exit = false;
		std::shared_ptr<SceneManager> sceneManager;
		std::shared_ptr<WindowHandler> w_handler;
		std::shared_ptr<PluginManager>pluginManager;
		std::shared_ptr<ResourceManager> resourceManager;
		std::shared_ptr<InputManager> inputManager;
	};
}


