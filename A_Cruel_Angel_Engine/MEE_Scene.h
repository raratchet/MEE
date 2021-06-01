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
		virtual void load() = 0;
		void update();
		void draw();
		virtual void unload() = 0;
		class GameObject& createGameObject(const std::string& name);
		class GameObject& createGameObject(const std::string& name, class Sprite& sprite);
		class WorldObject& createWorldObject(const std::string& name);
		class Camera& createCamera();
		class Camera& createCamera(const struct Vector2& pos, int widht, int height);
		bool isLoaded();
	protected:
		std::list<std::shared_ptr<class Camera>> sceneCameras;
		std::list<std::shared_ptr<class Object>> sceneObjects;
		std::list<std::shared_ptr<class Behaviours>> updateComponents;
		std::list<std::shared_ptr<class Drawable>> drawObjects;
		bool loaded = false;
	};
}

