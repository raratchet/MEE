#include "MEE_Scene.h"
#include "MEE_Object.h"
#include "MEE_Components.h"
#include "MEE_Camera.h" 
#include "MEE_Physics.h"
#include "MEE_WindowHandler.h"
#include "MEE_Graphics.h"
#include "MEE_Global.h"

namespace MEE
{
	Scene::Scene() 
	{ 
        CreateMainSceneCamera();
	}

	 Scene::~Scene() 
	 { 
		sceneCameras.clear(); 
		sceneObjects.clear(); 
		sceneColliders.clear(); 
		drawObjects.clear(); 
	 }

     GameObject& Scene::CreateGameObject(const std::string& name)
     {
         std::shared_ptr <GameObject> temp(new GameObject(*this, name));
         sceneObjects.push_back(temp);
         drawObjects.push_back(temp);
         return *(temp);
     }

     GameObject& Scene::CreateGameObject(const std::string& name, Sprite& sprite)
     {
         std::shared_ptr <GameObject> temp(new GameObject(*this, name,sprite));
         sceneObjects.push_back(temp);
         drawObjects.push_back(temp);
         return *(temp);
     }

     WorldObject& Scene::CreateWorldObject(const std::string& name)
     {
         std::shared_ptr<WorldObject> temp(new WorldObject(*this, name));
         sceneObjects.push_back(temp);
         return *(temp);
     }

     Camera& Scene::CreateCamera()
     {
         std::shared_ptr<Camera> camera(new Camera());
         sceneCameras.push_back(camera);
         return *(camera);
     }

     Camera& Scene::CreateCamera(const Vector2& pos, int widht, int height)
     {
         std::shared_ptr<Camera> camera(new Camera(pos, widht, height));
         sceneCameras.push_back(camera);
         return *(camera);
     }

     bool Scene::IsLoaded()
     {
         return loaded;
     }

     SceneID Scene::GetID()
     {
         return id;
     }

     Camera& Scene::GetMainCamera()
     {
         return *sceneCameras.front().get();
     }

     void Scene::CreateMainSceneCamera()
     {
         int w, h;
         WindowHandler::GetWindowSize(&w,&h);

         CreateCamera(Vector2(),w,h);
     }

     void Scene::SetCurrenCamera(std::weak_ptr<Camera> camera)
     {
         MEE_GLOBAL::application->GetRenderManager().lock()->SetCurrentCamera(camera);
     }

     void Scene::Update()
     {
         //Update transforms in module
         for (auto& collider : sceneColliders)
         {
             if (collider->GetParent().GetEnabled())
             {
                 auto transform = collider->transform.lock();
                 auto position = transform->GetPosition();
                 MEE_Collider asMEE_Collider = (MEE_Collider)(collider.get());
                 MEE_SetColliderTransform(asMEE_Collider, position.x, position.y, transform->GetRotation());
             }
         }

         //Run physics
         MEE_PhysicsStep(id);

         //Update transforms in engine
         for (auto& collider : sceneColliders)
         {
             if (collider->GetParent().GetEnabled())
             {
                 auto transform = collider->transform.lock();
                 Vector2 position;
                 float angle;

                 MEE_Collider asMEE_Collider = (MEE_Collider)(collider.get());
                 MEE_GetColliderTransform(asMEE_Collider, &position.x, &position.y, &angle);

                 transform->SetPosition(position);
                 transform->SetRotation(angle);
                 transform->modified = false;
             }
         }

         //Update scene objects
         for (auto& obj : sceneObjects)
             for (auto& beh : obj->updatables)
                 if(obj->GetEnabled())
                    beh->Update();
     }

     void Scene::Draw()
     {
         for (auto& camera : sceneCameras)
         {

             if (!camera->GetActive())
                 continue;

             SetCurrenCamera(camera);
             MEE_RenderDebugGrid(); //temp

             for (auto& drawable : drawObjects)
             {
                 if(drawable->GetVisible())
                    drawable->Draw(camera);
             }
         }
     }
}