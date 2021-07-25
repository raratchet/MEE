#pragma once
#include <memory>
#include <vector>
#include <string>
#include "MEE_Components.h"
#include "MEE_Scene.h"
#include "MEE_Drawable.h"
#include "MEE_Exports.h"
#include "MEE_Physics.h"


namespace MEE
{
	class MEE_EXPORT Object
	{
	public:
		template<class T = Component>
		inline void AddComponent();

		template<class T = Component>
		void RemoveComponent();

		template<class T = Component>
		Component& GetComponent();

		void operator=(Object& obj) { obj = *this; }

		Transform& GetTransform();

		virtual ~Object();

	protected:
		Object(Scene& master, const std::string& objName);
		Scene& owner; 
		std::string name;
		std::vector<std::shared_ptr<Component>> components;
		std::vector<std::shared_ptr<Behaviour>> updatables;
		friend class Scene;
	};


	class MEE_EXPORT GameObject : public Object, public Drawable // El demonio mismo
	{
	public:
		virtual ~GameObject() {}
	protected:
		GameObject(Scene& master, const std::string& objName);
		GameObject(Scene& master, const std::string& objName, Sprite& sprite);
		friend class Scene;
	};

	class MEE_EXPORT WorldObject : public Object
	{
	public:
		virtual ~WorldObject() {}
	protected:
		WorldObject(Scene& master, const std::string& objName);
		friend class Scene;
	};



	template<class T>
	inline void Object::AddComponent()
	{
		std::shared_ptr<T> component(new T);
		auto* asComponent = (Component*)&*component;
		asComponent->ParentToObject(this);
		components.push_back(component);
		auto* asBehaviour = dynamic_cast<Behaviour*>(asComponent);
		if (asBehaviour)
		{
			updatables.push_back(std::reinterpret_pointer_cast<Behaviour>(component));
			asBehaviour->Start();
		}

	}

	template <>
    inline void Object::AddComponent<Collider>()
	{
		auto sceneID = owner.GetID();
		MEE_CreateCollider(sceneID);
		MEE_Collider mod_collider = MEE_CreateCollider(sceneID);
		std::shared_ptr<Collider> collider((Collider*)MEE_CreateCollider(sceneID));
		collider->SetTransform(std::reinterpret_pointer_cast<Transform>(components[0]));
		auto* asComponent = (Component*)&*collider;
		asComponent->ParentToObject(this);
		components.push_back(collider);
	}

	template<class T>
	void Object::RemoveComponent()
	{
		for (auto it = components.begin(); it != components.end(); it++)
		{
			auto component = *it;
			auto componentAsType = std::reinterpret_pointer_cast<T>(component);
			if (componentAsType)
			{
				auto isBehaviour = std::reinterpret_pointer_cast<Behaviour>(component);
				if (isBehaviour)
				{
					updatables.erase(it); // Checa esta linea estas modificando el array
					isBehaviour->Destroy();
				}
			}
		}
	}

	//template<>
	//void Object::RemoveComponent<Collider>()
	//{

	//}

	template<class T>
	Component& Object::GetComponent()
	{
		for (auto component : components)
		{
			auto componentAsType = std::reinterpret_pointer_cast<T>(component);
			if (componentAsType)
			{
				return *componentAsType;
			}
		}
	}
}


