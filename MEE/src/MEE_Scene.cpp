#include "MEE_Scene.h"
#include "MEE_Object.h"
#include "MEE_Components.h"
#include "MEE_Camera.h" 
#include "MEE_Physics.h"
#include "MEE_WindowHandler.h"
#include "MEE_Global.h"

#define MEE_CHECK_FUNCTION(FUNC_NAME,FUNCTION)\
try\
{\
    FUNCTION;\
}\
catch(...)\
{\
	std::string message ="An error ocurred while calling ";\
	message += #FUNC_NAME;\
	message += " in MEE_PHYSICS.";\
    MEE_LOGGER::Error(message);\
}

namespace MEE
{
	Scene::Scene() 
	{ 
        CreateMainSceneCamera();
	}

	 Scene::~Scene() 
	 { 
		m_sceneCameras.clear();
		m_sceneObjects.clear();
		m_sceneColliders.clear();
		m_drawObjects.clear();
	 }

    std::shared_ptr<GameObject> Scene::CreateGameObject(const std::string& name)
     {
         std::shared_ptr <GameObject> temp(new GameObject(*this, name));
         m_sceneObjects.push_back(temp);
         m_drawObjects.push_back(temp);
         return temp;
     }

    std::shared_ptr<GameObject> Scene::CreateGameObject(const std::string& name, Sprite& sprite)
     {
         std::shared_ptr <GameObject> temp(new GameObject(*this, name,sprite));
         m_sceneObjects.push_back(temp);
         m_drawObjects.push_back(temp);
         return temp;
     }

    std::shared_ptr<WorldObject> Scene::CreateWorldObject(const std::string& name)
     {
         std::shared_ptr<WorldObject> temp(new WorldObject(*this, name));
         m_sceneObjects.push_back(temp);
         return temp;
     }

    std::shared_ptr<Camera> Scene::CreateCamera()
     {
         std::shared_ptr<Camera> camera(new Camera());
         m_sceneCameras.push_back(camera);
         return camera;
     }

    std::shared_ptr<Camera> Scene::CreateCamera(const Vector2& pos, int widht, int height)
     {
         std::shared_ptr<Camera> camera(new Camera(pos, widht, height));
         m_sceneCameras.push_back(camera);
         return camera;
     }

     bool Scene::IsLoaded()
     {
         return m_loaded;
     }

     SceneID Scene::GetID()
     {
         return m_id;
     }

    std::shared_ptr<Camera> Scene::GetMainCamera()
     {
         return m_sceneCameras.front();
     }

     void Scene::CreateMainSceneCamera()
     {
         int w, h;
         WindowHandler::GetWindowSize(&w,&h);

         CreateCamera(Vector2(),w,h);
     }

     void Scene::SetCurrentCamera(std::weak_ptr<Camera> camera)
     {
         MEE_GLOBAL::application->GetRenderManager().lock()->SetCurrentCamera(camera);
     }

     void Scene::Update()
     {
         //Update transforms in module
         for (auto& collider : m_sceneColliders)
         {
             if (collider->GetParent().GetEnabled())
             {
                 auto transform = collider->m_transform.lock();
                 auto position = transform->GetPosition();
                 MEE_Collider asMEE_Collider = (MEE_Collider)(collider.get());
                 MEE_CHECK_FUNCTION(MEE_SetColliderTransform,
                     MEE_SetColliderTransform(asMEE_Collider, position.x, position.y, transform->GetRotation()));
             }
         }

         //Run physics
         MEE_CHECK_FUNCTION(MEE_PhysicsStep,MEE_PhysicsStep(m_id));

         //Update transforms in engine
         for (auto& collider : m_sceneColliders)
         {
             if (collider->GetParent().GetEnabled())
             {
                 auto transform = collider->m_transform.lock();
                 Vector2 position;
                 float angle;

                 MEE_Collider asMEE_Collider = (MEE_Collider)(collider.get());
                 MEE_CHECK_FUNCTION(MEE_GetColliderTransform, MEE_GetColliderTransform(asMEE_Collider, &position.x, &position.y, &angle));

                 transform->SetPosition(position);
                 transform->SetRotation(angle);
                 transform->modified = false;
             }
         }


         //Update scene objects
         for (auto& obj : m_sceneObjects)
             for (auto& beh : obj->m_updatables)
                 if (obj->GetEnabled())
                 {
                    MEE_LOGGER::ScopedLogging log("MEG");
                    beh->Update();
                 }
     }

     void Scene::Draw()
     {
         for (auto& camera : m_sceneCameras)
         {

             if (!camera->GetActive())
                 continue;

             SetCurrentCamera(camera);
#ifdef _DEBUG
             MEE_GLOBAL::application->GetRenderManager().lock()->RenderDebugGrid();
#endif // _DEBUG

             for (auto& drawable : m_drawObjects)
             {
                 if(drawable->GetVisible())
                    drawable->Draw();
             }

             camera->DrawUIElements();
         }
     }
}