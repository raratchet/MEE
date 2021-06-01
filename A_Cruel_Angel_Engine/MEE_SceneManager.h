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
		void addScene(Scene* scene);
		void quitScene();
		std::shared_ptr<Scene> getCurrentScene();
	private:
		std::stack<std::shared_ptr<Scene>> scenes;
	};
}

