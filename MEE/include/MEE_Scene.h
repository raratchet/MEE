/*****************************************************************//**
 * \file   MEE_Scene.h
 * \brief  
 * 
 * \author Maximiliano Herrera
 * \date   November 2021
 *********************************************************************/
#pragma once
#include <list>
#include <string>
#include <memory>
#include "MEE_Exports.h"

namespace MEE
{
	using SceneID = unsigned int;

	/**
	 * Conatains Objects and manages Physics.
	 */
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
		std::shared_ptr<class GameObject> CreateGameObject(const std::string& name);
		/**
		* Creates a gameobject for the current scene
		* and registers it to the draw list.
		*
		* \param name: The name that identifies this gameobject.
		* \param sprite: The sprite that will be drawn for this GameObject.
		* \return A reference to the GameObject.
		*/
        std::shared_ptr<class GameObject> CreateGameObject(const std::string& name, class Sprite& sprite);
		/**
		* Creates a worldobject for the current scene.
		* 
		* \param name: The name that identifies this WorldObject.
		* \return A reference to the WorldObject.
		*/
        std::shared_ptr<class WorldObject> CreateWorldObject(const std::string& name);
		/**
		 * TODO
		 */
        std::shared_ptr<class Camera> CreateCamera();
		/**
		 * TODO
		 */
        std::shared_ptr<class Camera> CreateCamera(const struct Vector2& pos, int widht, int height);
		/**
		* \return Weather the Scene is loaded or not.
		*/
		bool IsLoaded();
		/**
		 * \return This Scene m_id
		 */
		SceneID GetID();
		/**
		 * \return A reference to this Scene main Camera
		 */
        std::shared_ptr<class Camera> GetMainCamera();
		
	private:
		void CreateMainSceneCamera();
		void SetCurrentCamera(std::weak_ptr<class Camera> camera);
	private:
		std::list<std::shared_ptr<class Camera>>   m_sceneCameras;
		std::list<std::shared_ptr<class Object>>   m_sceneObjects;
		std::list<std::shared_ptr<class Collider>> m_sceneColliders;
		std::list<std::shared_ptr<class Drawable>> m_drawObjects;
		bool m_loaded = false;
		SceneID m_id;

		friend class SceneManager;
		friend class Object;
	};
}

