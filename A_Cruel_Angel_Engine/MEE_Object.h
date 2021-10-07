#pragma once
#include <memory>
#include <vector>
#include <string>
#include "MEE_Components.h"
#include "MEE_Scene.h"
#include "MEE_Drawable.h"
#include "MEE_Exports.h"
#include "MEE_Functional.h"


namespace MEE
{
	class MEE_EXPORT Object
	{
	public:

		template<class T = Component>
		T& AddComponent(FunctionParameters params = FunctionParameters::NoParameters());

		template<class T = Component>
		void RemoveComponent();

		template<class T = Component>
		T& GetComponent();

		void operator=(Object& obj) { obj = *this; }

		TransformComponent& GetTransformComponent();

		Scene& GetScene();

		virtual void SetEnabled(bool value);

		std::string GetName();
		std::string GetTag();

		void SetName(const std::string& value);
		void SetTag(const std::string& value);

		bool GetEnabled();

		virtual ~Object();

	protected:
		Object(Scene& master, const std::string& objName);
		Scene& owner; 
		std::string name;
		std::vector<std::shared_ptr<Component>> components;
		std::vector<std::shared_ptr<Updatable>> updatables;
		std::string tag;

		bool enabled = true;

		Component& Internal_AddComponent(Component* component, FunctionParameters& params, const std::string& type = "Default");
		friend class Scene;
		
	};


	class MEE_EXPORT GameObject : public Object, public Drawable // El demonio mismo
	{
	public:
		virtual ~GameObject() {}
	protected:
		GameObject(Scene& master, const std::string& objName);
		GameObject(Scene& master, const std::string& objName, Sprite& sprite);
		virtual void SetEnabled(bool value) override;
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
	inline T& Object::AddComponent(FunctionParameters params)
	{
		auto* component = new T;
		return (T&) Internal_AddComponent(component,params);

	}

	class AnimationPlayer;

	template<>
	inline AnimationPlayer& Object::AddComponent<AnimationPlayer>(FunctionParameters params)
	{
		return (AnimationPlayer&)Internal_AddComponent(nullptr, params, "AnimationPlayer");

	}

	class Collider;

	template <>
    inline Collider& Object::AddComponent<Collider>(FunctionParameters params)
	{
		return (Collider&)Internal_AddComponent(nullptr,params,"Collider");
	}

	template<class T>
	void Object::RemoveComponent()
	{
		for (auto it = components.begin(); it != components.end(); it++)
		{
			auto component = *it;
			auto componentAsType = dynamic_cast<T>(component);
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
	inline T& Object::GetComponent()
	{
		for (auto component : components)
		{
			auto componentAsType = dynamic_cast<T*>(component.get());
			if (componentAsType)
			{
				return *componentAsType;
			}
		}
	}

	//template<>
	//inline Collider& Object::GetComponent<Collider>()
	//{
	//	for (auto component : components)
	//	{
	//		Collider* componentAsType = dynamic_cast<Collider*>(component.get());
	//		if (componentAsType)
	//		{
	//			Collider* collider = CastCollider(componentAsType);
	//			return *collider;
	//		}
	//	}
	//}
}


