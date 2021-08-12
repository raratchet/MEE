#include "MEE_Components.h"
#include "MEE_Object.h"
#include "MEE_Physics.h"


namespace MEE
{
	Transform::Transform()
	{
	}
	void Transform::SetPosition(Vector2 position_vector)
	{
		position = position_vector;
		modified = true;
	}

	void Transform::SetPosition(float posX, float posY)
	{
		position.x = posX;
		position.y = posY;
		modified = true;
	}

	void Transform::SetScale(Vector2 scale_vector)
	{
		scale = scale_vector;
		modified = true;
	}

	void Transform::SetScale(float x, float y)
	{
		scale.x = x;
		scale.y = y;
		modified = true;
	}

	void Transform::SetRotation(float rotation_float)
	{
		rot = rotation_float;
		modified = true;
	}

	void Transform::Translate(Vector2 vec)
	{
		position = position + vec;
		modified = true;
	}

	Vector2 Transform::GetPosition()
	{
		return position;
	}

	Vector2 Transform::GetScale()
	{
		return scale;
	}

	float Transform::GetRotation()
	{
		return rot;
	}

	bool Transform::WasModified()
	{
		return modified;
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
	Vector2 Collider::GetVelocity()
	{
		return velocity;
	}
	float Collider::GetFriction()
	{
		return friction;
	}
	float Collider::GetGravity()
	{
		return gravityScale;
	}
	bool Collider::GetRotationConstrait()
	{
		return isRotConstraint;
	}
	bool Collider::GetActive()
	{
		return active;
	}
	ColliderType Collider::GetType()
	{
		return type;
	}
	ColliderForm Collider::GetFigure()
	{
		return form;
	}

	void Collider::SetVelocity(const Vector2& value)
	{
		velocity = value;
	}
	void Collider::SetFriction(float value)
	{
		friction = value;
	}
	void Collider::SetGravity(float value)
	{
		gravityScale = value;
	}
	void Collider::SetRotationConstrait(bool value)
	{
		isRotConstraint = value;
	}
	void Collider::SetActive(bool value)
	{
		active = value;
	}
	void Collider::SetType(ColliderType value)
	{
		type = value;
	}
	void Collider::SetFigure(ColliderForm value)
	{
		form = value;
	}

	void Collider::ApplyForce(const Vector2&, const Vector2&)
	{

	}

	void Collider::ApplyLinearImpulse(const Vector2&, const Vector2&)
	{

	}

	bool Collider::Transform_WasModified()
	{
		auto trans = transform.lock();

		return trans->WasModified();
	}
}