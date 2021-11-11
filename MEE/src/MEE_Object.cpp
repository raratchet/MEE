#include "MEE_Object.h"
#include "MEE_Scene.h"
#include "MEE_Physics.h"
#include "MEE_Animation.h"

namespace MEE
{

	void Object::RegisterUpdatable(std::weak_ptr<Updatable> updatable)
	{
		updatables.push_back(updatable.lock());
	}

	Component& Object::AddComponent(Component* component, FunctionParameters& params)
	{

		if (component)
		{
			if (auto isBehaviour = dynamic_cast<Behaviour*>(component))
			{
				return AddBehaviuor(isBehaviour);
			}

			component->ParentToObject(this);
			auto com_ptr = std::shared_ptr<Component>(component);
			components.push_back(com_ptr);

			if (Updatable* asUpdatable = dynamic_cast<Updatable*>(component))
			{
				RegisterUpdatable(std::dynamic_pointer_cast<Updatable>(com_ptr));
			}
		}

		return *component;
	}

	AnimationPlayer& Object::AddAnimationPlayer(FunctionParameters& params)
	{
		if (auto isDrawable = dynamic_cast<Drawable*>(this))
		{
			auto animPlayer = std::shared_ptr<AnimationPlayer>(new AnimationPlayer(*isDrawable));
			std::dynamic_pointer_cast<Component>(animPlayer)->ParentToObject(this);
			components.push_back(animPlayer);
			RegisterUpdatable(std::dynamic_pointer_cast<Updatable>(animPlayer));
			return *animPlayer;
		}
	}

	Collider& Object::AddCollider(FunctionParameters& params)
	{
		auto sceneID = owner.GetID();
		auto transform = std::reinterpret_pointer_cast<TransformComponent>(components[0]);

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
		auto col_ptr = std::shared_ptr<Collider>(collider);
		owner.sceneColliders.push_back(col_ptr);
		components.push_back(col_ptr);
		std::dynamic_pointer_cast<Component>(col_ptr)->ParentToObject(this);

		return *col_ptr;
	}

	Behaviour& Object::AddBehaviuor(Behaviour* behaviour)
	{
		auto beh_ptr = std::shared_ptr<Behaviour>(behaviour);
		components.push_back(beh_ptr);
		std::dynamic_pointer_cast<Component>(beh_ptr)->ParentToObject(this);
		RegisterUpdatable(std::dynamic_pointer_cast<Updatable>(beh_ptr));
		beh_ptr->Start();
		return *beh_ptr;

	}

	TransformComponent& Object::GetTransformComponent()
	{ 
		TransformComponent* pointer = dynamic_cast<TransformComponent*>(components[0].get());
		return *pointer; 
	}

	Object::~Object()
	{
		components.clear(); 
		//Si un componente es updatable y se borra durante 
		// el clear de components crea una excepcion en updatables.
		updatables.clear();
	}

	Object::Object(Scene& master, const std::string& objName) : owner(master), name(objName)
	{
		AddComponent<TransformComponent>();
	}

	Scene& Object::GetScene()
	{
		return owner;
	}

	void Object::SetEnabled(bool value)
	{
		enabled = value;
	}

	std::string Object::GetName()
	{
		return name;
	}

	std::string Object::GetTag()
	{
		return tag;
	}

	void Object::SetName(const std::string& value)
	{
		name = value;
	}

	void Object::SetTag(const std::string& value)
	{
		tag = value;
	}

	bool Object::GetEnabled()
	{
		return enabled;
	}

	GameObject::GameObject(Scene& master, const std::string& objName)
		: Object(master, objName), Drawable(GetTransformComponent()) {}

	GameObject::GameObject(Scene& master, const std::string& objName, Sprite& sprite)
		: Object(master, objName), Drawable(sprite, GetTransformComponent()) {}

	void GameObject::SetEnabled(bool value)
	{
		enabled = value;
		Drawable::SetVisible(value);
	}

	WorldObject::WorldObject(Scene& master, const std::string& objName) : Object(master, objName) {}
}
