/*****************************************************************//**
 * \file   MEE_SceneManager.h
 * \brief  
 * 
 * \author Maximiliano Herrera
 * \date   November 2021
 *********************************************************************/
#pragma once
#include <list>
#include "MEE_Scene.h"

namespace MEE
{
	/**
	 * Manages all Scene related stuff in the main loop of MEE.
	 */
	class MEE_EXPORT SceneManager
	{
	public:
		SceneManager() = default;
		~SceneManager();
		void AddScene(Scene* scene);
		void QuitScene();
		std::shared_ptr<Scene> GetCurrentScene();
	private:
		std::list<std::pair<int, std::shared_ptr<Scene>>> m_scenes;
	};
}

