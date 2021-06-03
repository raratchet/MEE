#include "MEE_Scene.h"
#include "MEE_Object.h"
#include "MEE_Components.h"
#include "MEE_Camera.h" 
#include "MEE_Graphics.h"//?

namespace MEE
{
	Scene::Scene() 
	{ 
		CreateCamera(); 
	}

	 Scene::~Scene() 
	 { 
		sceneCameras.clear(); 
		sceneObjects.clear(); 
		updateComponents.clear(); 
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

     void Scene::Update()
     {
         for (auto& obj : sceneObjects)
             for (auto& beh : obj->updatables)
                 beh->Update();
     }

     void Scene::Draw()
     {
         for (auto& camera : sceneCameras)
         {
             if (!camera->GetActive())
                 continue;
             //REVISA ESTA LINEA
             //Renderer::SetCurrentCamera(camera);

             for (auto& drawable : drawObjects)
             {
                 drawable->Draw();
             }
         }
     }
}