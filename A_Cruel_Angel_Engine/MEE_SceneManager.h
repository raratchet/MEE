#pragma once
#include "MEE_Scene.h"
#include <list>

namespace MEE
{
	class MEE_EXPORT SceneManager
	{
	public:
		SceneManager() = default;
		~SceneManager();
		void AddScene(Scene* scene);
		void QuitScene();
		std::shared_ptr<Scene> GetCurrentScene();
	private:
		std::list<std::pair<int, std::shared_ptr<Scene>>> scenes;
	};
}

