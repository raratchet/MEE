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
	 * Application contains and controls the app/game main loop
	 * and subsystems.
	 */
	class MEE_EXPORT Application
	{
	public:
		/**
		 * Default constructor.
		 * Sets the MEE_GLOBAL Application pointer to this instance.
		 */
		Application();
        /**
         */
		~Application() = default;
		/**
		 * Initialize the application.
		 * Builds window, creates and initializes all managers.
		 * \return false if application couldn't be initialized correctly.
		 */
		bool Init();
		/**
		 * Load is called after the app is initialized correctly.
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
		 * \return Pointer to the WindowHandler.
		 */
		WindowHandler* GetWindow();
		/**
		* \return Pointer to the PluginManager.
		*/
		PluginManager* GetPluginManager();
		/**
		* \return Pointer to the ResourceManager.
		*/
		ResourceManager* GetResourceManager();
		/**
		* \return Pointer to the SceneManager.
		*/
		SceneManager* GetSceneManager();
		/**
		* \return Pointer to the InputManager.
		*/
		InputManager* GetInputManager();
		/**
		* \return Pointer to the TimeManager.
		*/
		TimeManager* GetTimeManager();
		/**
		* \return Pointer to the RenderingManager.
		*/
		RenderingManager* GetRenderManager();
	private:
		bool exit = false;
		std::unique_ptr<SceneManager> sceneManager;
		std::unique_ptr<WindowHandler> w_handler;
		std::unique_ptr<PluginManager>pluginManager;
		std::unique_ptr<ResourceManager> resourceManager;
		std::unique_ptr<InputManager> inputManager;
		std::unique_ptr<TimeManager> timeManager;
		std::unique_ptr<RenderingManager> renderManager;
	};
}


