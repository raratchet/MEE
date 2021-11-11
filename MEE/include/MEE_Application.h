/*****************************************************************//**
 * \file   MEE_Application.h
 * \brief  
 * 
 * \author Maximiliano Herrera
 * \date   October 2021
 *********************************************************************/
#pragma once
#include<memory>
#include<string>
#include<iostream>

#include "MEE_WindowHandler.h"
#include "MEE_PluginManager.h"
#include "MEE_SceneManager.h"
#include "MEE_InputManager.h"
#include "MEE_Time.h"
#include "MEE_Rendering.h"
#include "MEE_ResourceManager.h"

namespace MEE
{
	/**
	 * Application contains and controlls the app/game main loop
	 * and subsystems.
	 */
	class MEE_EXPORT Application
	{
	public:
		/**
		 * Default constructur.
		 * Sets the MEE_GLOBAL Application pointer to this instance.
		 */
		Application();
		~Application() = default;
		/**
		 * Initialize the application.
		 * Builds window, creates and initiliazes all managers.
		 * \return false if application couldn't be initialized correctly.
		 */
		bool Init();
		/**
		 * Load is called after the app is initilized correctly.
		 * Calls the load method in all loaded plugins
		 */
		void Load();
		/**
		 * Unloads all plugins and shutdown all managers.
		 * 
		 */
		void Stop();
		/**
		 * Main Loop of application.
		 * 
		 */
		void Loop();
		/**
		 * The Update function is called once per frame while 
		 * the application loop is still active.
		 * It updates active scenes and all updatable objects those scenes contains.
		 * It calls OnUpdate in all plugins.
		 * It calls OnPostUpdate in all plugins when it ends updating.
		 */
		void Update();
		/**
		 * The Draw function is called once per frame while.
		 * It clears, draws and present in screen all active drawable objects cointained in the active scenes.
		 * It calls OnDraw in all plugins.
		 */
		void Draw();
		/**
		 * It ends the active loop of the running Application.
		 * 
		 */
		void CloseApplicationSignal();
		/**
		 * \return A weak pointer to the WindowHandler.
		 */
		std::weak_ptr<WindowHandler> GetWindow();
		/**
		* \return A weak pointer to the PluginManager.
		*/
		std::weak_ptr<PluginManager> GetPluginManager();
		/**
		* \return A weak pointer to the ResourceManager.
		*/
		std::weak_ptr<ResourceManager> GetResourceManager();
		/**
		* \return A weak pointer to the SceneManager.
		*/
		std::weak_ptr<SceneManager> GetSceneManager();
		/**
		* \return A weak pointer to the InputManager.
		*/
		std::weak_ptr<InputManager> GetInputManager();
		/**
		* \return A weak pointer to the TimeManager.
		*/
		std::weak_ptr<TimeManager> GetTimeManager();
		/**
		* \return A weak pointer to the RenderingManager.
		*/
		std::weak_ptr<RenderingManager> GetRenderManager();
	private:
		bool exit = false;
		std::shared_ptr<SceneManager> sceneManager;
		std::shared_ptr<WindowHandler> w_handler;
		std::shared_ptr<PluginManager>pluginManager;
		std::shared_ptr<ResourceManager> resourceManager;
		std::shared_ptr<InputManager> inputManager;
		std::shared_ptr<TimeManager> timeManager;
		std::shared_ptr<RenderingManager> renderManager;
	};
}


