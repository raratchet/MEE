#include "MEE_Object.h"
#include "MEE_Physics.h"

namespace MEE
{
	Component& Object::Internal_AddComponent(Component* component)
	{
		component->ParentToObject(this);

		Behaviour* asBehaviour = dynamic_cast<Behaviour*>(component);
		Collider* asCollider = dynamic_cast<Collider*>(component);

		if (asBehaviour)
		{
			updatables.push_back(std::shared_ptr<Behaviour>((Behaviour*)component));
			asBehaviour->Start();
		}
		else if (asCollider)
		{
			auto sceneID = owner.GetID();
			FunctionParameter size = { "Size", 1.0F };
			FunctionParameters params =  FunctionParameters(size);
			Collider* collider = (Collider*)MEE_CreateCollider(sceneID, params);
			collider->SetTransform(std::reinterpret_pointer_cast<Transform>(components[0]));
			auto* asComponent = (Component*)&*collider;
			asComponent->ParentToObject(this);
			delete component;
			component = collider;
			owner.sceneColliders.push_back(std::shared_ptr<Collider>(collider));
		}

		components.push_back(std::shared_ptr<Component>(component));
		return *component;
	}

	Transform& Object::GetTransform()
	{ 
		auto sharedptr = std::reinterpret_pointer_cast<Transform>(components[0]);
		Transform& transform = *sharedptr;
		return transform; 
	}

	Object::~Object()
	{
		components.clear(); 
		updatables.clear();
	}

	Object::Object(Scene& master, const std::string& objName) : owner(master), name(objName)
	{
		AddComponent<Transform>();
	}

	GameObject::GameObject(Scene& master, const std::string& objName)
		: Object(master, objName), Drawable(GetTransform()) {}

	GameObject::GameObject(Scene& master, const std::string& objName, Sprite& sprite)
		: Object(master, objName), Drawable(sprite, GetTransform()) {}

	WorldObject::WorldObject(Scene& master, const std::string& objName) : Object(master, objName) {}
}
