#include "MEE_Components.h"
#include "MEE_Object.h"


namespace MEE
{
	Transform::Transform()
	{
	}
	void Transform::SetPosition(Vector2 position_vector)
	{
		position = position_vector;
	}

	void Transform::SetPosition(float posX, float posY)
	{
		position.x = posX;
		position.y = posY;
	}

	void Transform::SetScale(Vector2 scale_vector)
	{
		scale = scale_vector;
	}

	void Transform::SetScale(float x, float y)
	{
		scale.x = x;
		scale.y = y;
	}

	void Transform::SetRotation(float rotation_float)
	{
		rot = rotation_float;
	}

	Vector2& Transform::GetPosition()
	{
		return position;
	}

	Vector2& Transform::GetScale()
	{
		return scale;
	}

	float& Transform::GetRotation()
	{
		return rot;
	}

	void Behaviour::Start()
	{

	}

	void Behaviour::Update()
	{

	}

 
	void Behaviour::Destroy()
	{

	}

	Object& Component::GetParent()
	{
		return *parent;
	}

	void Component::ParentToObject(Object* object)
	{
		parent = object;
	}
	void Collider::SetTransform(std::shared_ptr<Transform> trans)
	{
		transform = trans;
	}
}