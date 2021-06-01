#include "MEE_Components.h"
#include "MEE_Object.h"


namespace MEE
{
	void Transform::setPosition(Vector2 position_vector)
	{
		position = position_vector;
	}

	void Transform::setScale(Vector2 scale_vector)
	{
		scale = scale_vector;
	}

	void Transform::setRotation(float rotation_float)
	{
		rot = rotation_float;
	}

	Vector2& Transform::getPosition()
	{
		return position;
	}

	Vector2& Transform::getScale()
	{
		return scale;
	}

	float& Transform::getRotation()
	{
		return rot;
	}

	void Behaviour::start()
	{

	}

	void Behaviour::update()
	{

	}

 
	void Behaviour::destroy()
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