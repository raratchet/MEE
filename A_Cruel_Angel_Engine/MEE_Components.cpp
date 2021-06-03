#include "MEE_Components.h"
#include "MEE_Object.h"


namespace MEE
{
	void Transform::SetPosition(Vector2 position_vector)
	{
		position = position_vector;
	}

	void Transform::SetScale(Vector2 scale_vector)
	{
		scale = scale_vector;
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

	Behaviour::Behaviour(Object& parent) : 
		Component(parent) {}

	Component::Component(Object& parent) : 
		object(parent) {}

	Transform::Transform(Object& parent) : 
		Component(parent) {}

	Animation::Animation(Object& parent) : 
		Component(parent) {}
}