#pragma once
#include <list>
#include <string>
#include <memory>
#include "MEE_Exports.h"

namespace MEE
{
	using SceneID = unsigned int;

	class MEE_EXPORT Scene
	{
	public:
		Scene();
		virtual ~Scene();
		/**
		 * To be defined in client.
		 * 
		 */
		virtual void Load() = 0;
		/**
		* Updates every updatable in the scene each frame.
		* 
		*/
		void Update();
		/**
		* Draws every drawable in the scene each frame.
		* 
		*/
		void Draw();
		/**
		 * To be defined in client
		 * 
		 */
		virtual void Unload() = 0;
		/**
		* Creates a gameobject for the current scene 
		* and registers it to the draw list.
		* 
		* \param name: The name that identifies this GameObject.
		* \return A reference to the GameObject.
		*/
		class GameObject& CreateGameObject(const std::string& name);
		/**
		* Creates a gameobject for the current scene
		* and registers it to the draw list.
		*
		* \param name: The name that identifies this gameobject.
		* \param sprite: The sprite that will be drawn for this GameObject.
		* \return A reference to the GameObject.
		*/
		class GameObject& CreateGameObject(const std::string& name, class Sprite& sprite);
		/**
		* Creates a worldobject for the current scene.
		* 
		* \param name: The name that identifies this gameobject.
		* \return A reference to the WorldObject.
		*/
		class WorldObject& CreateWorldObject(const std::string& name);
		/**
		 * TODO
		 */
		class Camera& CreateCamera();
		/**
		 * TODO
		 */
		class Camera& CreateCamera(const struct Vector2& pos, int widht, int height);
		/**
		* \return Weather the scene is loaded or not.
		*/
		bool IsLoaded();
		/**
		 * \return This scene id
		 */
		SceneID GetID();
		/**
		 * .
		 * 
		 * \return 
		 */
		Camera& GetMainCamera();
		
	private:
		void CreateMainSceneCamera();
		void SetCurrenCamera(std::weak_ptr<class Camera> camera);
	private:
		std::list<std::shared_ptr<class Camera>> sceneCameras;
		std::list<std::shared_ptr<class Object>> sceneObjects;
		std::list<std::shared_ptr<class Collider>> sceneColliders;
		std::list<std::shared_ptr<class Drawable>> drawObjects;
		bool loaded = false;
		SceneID id;

		friend class SceneManager;
		friend class Object;
	};
}

