#include "MEE_Object.h"

namespace MEE
{
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
