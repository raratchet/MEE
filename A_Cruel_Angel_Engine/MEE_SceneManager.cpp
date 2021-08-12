#include "MEE_SceneManager.h"
#include "MEE_Physics.h"
namespace MEE
{
	SceneManager::~SceneManager()
	{
		while (!scenes.empty())
		{
			scenes.pop_front();
		}
	}

	void SceneManager::AddScene(Scene* scene)
	{
		std::shared_ptr<Scene> shared_scene(scene);
		scenes.push_front({scenes.size(),shared_scene });
		shared_scene->id = scenes.front().first;
		FunctionParameters params = FunctionParameters::NoParameters();
		MEE_CreatePhysicsWorld(shared_scene->id, params);
		if (!scene->IsLoaded())
			scene->Load();
	}

	void SceneManager::QuitScene()
	{
		scenes.pop_front();
	}

	std::shared_ptr<Scene> SceneManager::GetCurrentScene()
	{
		return scenes.front().second;
	}
}
