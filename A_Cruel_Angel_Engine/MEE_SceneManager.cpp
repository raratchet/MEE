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

	void SceneManager::AddScene(Scene* scene)
	{
		std::shared_ptr<Scene> shared_scene(scene);
		scenes.push(shared_scene);

		if (!scene->IsLoaded())
			scene->Load();
	}

	void SceneManager::QuitScene()
	{
		scenes.pop();
	}

	std::shared_ptr<Scene> SceneManager::GetCurrentScene()
	{
		return scenes.top();
	}
}
