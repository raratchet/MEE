#pragma once
#include <memory>
#include <list>
#include <string>
#include "MEE_Components.h"
#include "MEE_Scene.h"
#include "MEE_Drawable.h"
#include "MEE_Exports.h"


namespace MEE
{
	class MEE_EXPORT Object
	{
	public:
		template<class T = Component>
		void AddComponent()
		{
			std::shared_ptr<T> component(new T(*this));
			components.push_back(component);
			auto tmp = std::reinterpret_pointer_cast<Behaviour>(component);
			if (tmp)
			{
				updatables.push_back(tmp);
				tmp->start();
			}

		}
		template<class T = Component>
		void RemoveComponent()
		{

		}

		void operator=(Object& obj) { obj = *this; }

		Transform& GetTransform() { return transform; }

		virtual ~Object() { components.clear(); updatables.clear(); }

	protected:
		Object(Scene& master, const std::string& objName) : owner(master), name(objName) {}
		Scene& owner;
		std::string name;
		Transform transform = Transform(*this);
		std::list<std::shared_ptr<Component>> components;
		std::list<std::shared_ptr<Behaviour>> updatables;
		friend class Scene;
	};


	class MEE_EXPORT GameObject : public Object, public Drawable // El demonio mismo
	{
	public:
		virtual ~GameObject() {}
	protected:
		GameObject(Scene& master, const std::string& objName)
			: Object(master, objName), Drawable(transform) {}
		GameObject(Scene& master, const std::string& objName, Sprite& sprite)
			: Object(master, objName), Drawable(sprite,transform) {}
		friend class Scene;
	};

	class MEE_EXPORT WorldObject : public Object
	{
	public:
		virtual ~WorldObject() {}
	protected:
		WorldObject(Scene& master, const std::string& objName) : Object(master, objName) {}
		friend class Scene;
	};
}


