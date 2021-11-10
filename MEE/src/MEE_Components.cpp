#include "MEE_Components.h"
#include "MEE_Object.h"
#include "MEE_Physics.h"
#include "MEE_Functional.h"

namespace MEE
{
	TransformComponent::TransformComponent()
	{
	}
	void TransformComponent::SetPosition(Vector2 position_vector)
	{
		transform.position = position_vector;
		modified = true;
	}

	void TransformComponent::SetPosition(float posX, float posY)
	{
		transform.position.x = posX;
		transform.position.y = posY;
		modified = true;
	}

	void TransformComponent::SetScale(Vector2 scale_vector)
	{
		transform.scale = scale_vector;
		modified = true;
	}

	void TransformComponent::SetScale(float x, float y)
	{
		transform.scale.x = x;
		transform.scale.y = y;
		modified = true;
	}

	void TransformComponent::SetRotation(float rotation_float)
	{
		transform.rotation = rotation_float;
		modified = true;
	}

	void TransformComponent::Translate(Vector2 vec)
	{
		transform.position = transform.position + vec;
		modified = true;
	}

	Vector2 TransformComponent::GetPosition()
	{
		return transform.position;
	}

	Vector2 TransformComponent::GetScale()
	{
		return transform.scale;
	}

	Transform& TransformComponent::GetTransform()
	{
		return transform;
	}

	float TransformComponent::GetRotation()
	{
		return transform.rotation;
	}

	bool TransformComponent::WasModified()
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
	void Collider::SetTransform(std::shared_ptr<TransformComponent> trans)
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
	void Collider::SetIsTrigger(bool value)
	{
		isTrigger = value;
	}
	bool Collider::GetIsTrigger()
	{
		return isTrigger;
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

	void Collider::SetTriggerStartCallBack(std::function<void(Collider& other, FunctionParameters params)> callback)
	{
		TriggerStart_CallBack = callback;
	}

	void Collider::SetTriggerEndCallBack(std::function<void(Collider& other, FunctionParameters params)> callback)
	{
		TriggerEnd_CallBack = callback;
	}

	void Collider::SetCollisionStartCallBack(std::function<void(Collider& other, FunctionParameters params)> callback)
	{
		CollisionStart_CallBack = callback;
	}

	void Collider::SetCollisionResolveCallBack(std::function<void(Collider& other, FunctionParameters params)> callback)
	{
		CollisionResolve_CallBack = callback;
	}

	void Collider::Raycast(const Vector2& point1, const Vector2& point2, FunctionParameters parameters)
	{
	}

	bool Collider::PointOverlap(const Vector2& point1, FunctionParameters parameters)
	{
		return false;
	}

}