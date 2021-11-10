/*****************************************************************//**
 * \file   MEE_Object.h
 * \brief  Defines Object, GameObject and WorldObject
 * 
 * \author Maximiliano Herrera
 * \date   October 2021
 *********************************************************************/

#pragma once
#include <memory>
#include <vector>
#include <string>
#include "MEE_Components.h"
#include "MEE_Drawable.h"
#include "MEE_Exports.h"
#include "MEE_Functional.h"


namespace MEE
{
	//Pre declarations
	class Scene;

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
		//The main pointer to a component is saved here. Every other reference should be a weak one.
		std::vector<std::shared_ptr<Component>> components;
		//If a updatable is a component should be inserted via RegisterUpdatable.
		std::vector<std::shared_ptr<Updatable>> updatables;
		std::string tag;

		bool enabled = true;

		void RegisterUpdatable(std::weak_ptr<Updatable> updatable);
		Component& AddComponent(Component* component, FunctionParameters& params);
		AnimationPlayer& AddAnimationPlayer(FunctionParameters& params);
		Collider& AddCollider(FunctionParameters& params);
		Behaviour& AddBehaviuor(Behaviour* behaviour);
		friend class Scene;
		
	};


	class MEE_EXPORT GameObject : public Object, public Drawable // El demonio mismo
	{
	public:
		virtual ~GameObject() = default;
	protected:
		GameObject(Scene& master, const std::string& objName);
		GameObject(Scene& master, const std::string& objName, Sprite& sprite);
		virtual void SetEnabled(bool value) override;
		friend class Scene;
	};

	class MEE_EXPORT WorldObject : public Object
	{
	public:
		virtual ~WorldObject() = default;
	protected:
		WorldObject(Scene& master, const std::string& objName);
		friend class Scene;
	};


	template<class T>
	inline T& Object::AddComponent(FunctionParameters params)
	{
		auto* component = new T;
		return (T&) AddComponent(component,params);

	}

	class AnimationPlayer;

	template<>
	inline AnimationPlayer& Object::AddComponent<AnimationPlayer>(FunctionParameters params)
	{
		return AddAnimationPlayer(params);

	}

	class Collider;

	template <>
    inline Collider& Object::AddComponent<Collider>(FunctionParameters params)
	{
		return AddCollider(params);
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
}


