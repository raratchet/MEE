#pragma once
#include <list>
#include <string>
#include <memory>
#include "MEE_Exports.h"

namespace MEE
{
	class MEE_EXPORT Scene
	{
	public:
		Scene();
		virtual ~Scene();
		virtual void Load() = 0;
		void Update();
		void Draw();
		virtual void Unload() = 0;
		class GameObject& CreateGameObject(const std::string& name);
		class GameObject& CreateGameObject(const std::string& name, class Sprite& sprite);
		class WorldObject& CreateWorldObject(const std::string& name);
		class Camera& CreateCamera();
		class Camera& CreateCamera(const struct Vector2& pos, int widht, int height);
		bool IsLoaded();
	protected:
		std::list<std::shared_ptr<class Camera>> sceneCameras;
		std::list<std::shared_ptr<class Object>> sceneObjects;
		std::list<std::shared_ptr<class Behaviours>> updateComponents;
		std::list<std::shared_ptr<class Drawable>> drawObjects;
		bool loaded = false;
	};
}

