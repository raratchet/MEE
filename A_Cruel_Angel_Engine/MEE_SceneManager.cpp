#include "MEE_SceneManager.h"

namespace MEE
{
	SceneManager::~SceneManager()
	{
		while (!scenes.empty())
		{
			scenes.pop();
		}
	}

	void SceneManager::addScene(Scene* scene)
	{
		std::shared_ptr<Scene> shared_scene(scene);
		scenes.push(shared_scene);

		if (!scene->isLoaded())
			scene->load();
	}

	void SceneManager::quitScene()
	{
		scenes.pop();
	}

	std::shared_ptr<Scene> SceneManager::getCurrentScene()
	{
		return scenes.top();
	}
}
