#pragma once
#include "MEE_Scene.h"
#include <stack>

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
		std::stack<std::shared_ptr<Scene>> scenes;
	};
}

