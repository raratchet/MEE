#include "MEE_SceneManager.h"
#include "MEE_Physics.h"
namespace MEE
{
	SceneManager::~SceneManager()
	{
		while (!m_scenes.empty())
		{
			m_scenes.pop_front();
		}
	}

	void SceneManager::AddScene(Scene* scene)
	{
		std::shared_ptr<Scene> shared_scene(scene);
		m_scenes.push_front({m_scenes.size(), shared_scene });
		shared_scene->m_id = m_scenes.front().first;
		FunctionParameters params = FunctionParameters::NoParameters();
		MEE_CreatePhysicsWorld(shared_scene->m_id, params);
		if (!scene->IsLoaded())
			scene->Load();
	}

	void SceneManager::QuitScene()
	{
		m_scenes.pop_front();
	}

	std::shared_ptr<Scene> SceneManager::GetCurrentScene()
	{
		return m_scenes.front().second;
	}
}
