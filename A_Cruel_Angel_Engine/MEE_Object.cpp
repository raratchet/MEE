#include "MEE_Object.h"
#include "MEE_Physics.h"
#include "MEE_Animation.h"

namespace MEE
{
	Component& Object::Internal_AddComponent(Component* component, FunctionParameters& params, const std::string& type ) //Debo dividir esta funcion
	{

		if (type == "Collider")
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
				if (isDrawable && isDrawable->GetSprite().lock())
				{
					auto sprite = isDrawable->GetSprite().lock();
					auto scale = transform->GetScale();
					auto bsize = Vector2(sprite->GetSpriteWidth() * scale.x, 
										sprite->GetSpriteHeight() * scale.y);
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

			Collider* collider = static_cast<Collider*>(MEE_CreateCollider(sceneID, params));
			collider->SetTransform(transform);
			component = collider;
			owner.sceneColliders.push_back(std::shared_ptr<Collider>(collider));
		}
		else if (type == "AnimationPlayer")
		{
			if (Drawable* isDrawable = dynamic_cast<Drawable*>(this))
			{
				AnimationPlayer* animPlayer = new AnimationPlayer(*isDrawable);
				component = animPlayer;
			}
		}

		if (component)
		{
			component->ParentToObject(this);
			components.push_back(std::shared_ptr<Component>(component));
		}

		if (Updatable* asUpdatable = dynamic_cast<Updatable*>(component))
		{
			updatables.push_back(std::shared_ptr<Updatable>(asUpdatable));
			if (Behaviour* asBehaviour = dynamic_cast<Behaviour*>(component))
			{
				asBehaviour->Start();
			}
		}

		return *component;
	}

	Transform& Object::GetTransform()
	{ 
		Transform* pointer = dynamic_cast<Transform*>(components[0].get());
		return *pointer; 
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

	Scene& Object::GetScene()
	{
		return owner;
	}

	void Object::SetEnabled(bool value)
	{
		enabled = value;
	}

	bool Object::GetEnabled()
	{
		return enabled;
	}

	GameObject::GameObject(Scene& master, const std::string& objName)
		: Object(master, objName), Drawable(GetTransform()) {}

	GameObject::GameObject(Scene& master, const std::string& objName, Sprite& sprite)
		: Object(master, objName), Drawable(sprite, GetTransform()) {}

	void GameObject::SetEnabled(bool value)
	{
		enabled = value;
		Drawable::SetVisible(value);
	}

	WorldObject::WorldObject(Scene& master, const std::string& objName) : Object(master, objName) {}
}
