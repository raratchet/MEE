#include "MEE_Object.h"
#include "MEE_Physics.h"

namespace MEE
{
	Component& Object::Internal_AddComponent(Component* component, FunctionParameters& params)
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
			auto transform = std::reinterpret_pointer_cast<Transform>(components[0]);

			if (!params.Has("Position"))
			{
				FunctionParameter position = { "Position", transform->GetPosition() };
				params.Add(position);
			}

			if (!params.Has("Size"))
			{
				Drawable* isDrawable = dynamic_cast<Drawable*>(this);
				FunctionParameter size;
				if (isDrawable)
				{
					auto sprite = isDrawable->GetSprite().lock();
					auto scale = transform->GetScale();
					auto bsize = Vector2(sprite->GetSpriteWidth(), sprite->GetSpriteHeight());
					bsize = bsize / MEE_GetPixelsPerUnit();
					size = { "Size", bsize / 2 };
				}
				else
				{
					size = { "Size", transform->GetScale() / 2 };
				}
				params.Add(size);
			}

			if (!params.Has("Type"))
			{
				FunctionParameter type = { "Type", ColliderType::Static };
				params.Add(type);
			}

			Collider* collider = (Collider*)MEE_CreateCollider(sceneID, params);
			collider->SetTransform(transform);
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
