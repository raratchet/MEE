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
        m_transform = trans;
	}
	Vector2 Collider::GetVelocity()
	{
		return m_velocity;
	}
	float Collider::GetFriction()
	{
		return m_friction;
	}
	float Collider::GetGravity()
	{
		return m_gravityScale;
	}
	bool Collider::GetRotationConstrait()
	{
		return m_isRotConstraint;
	}
	bool Collider::GetActive()
	{
		return m_active;
	}
	ColliderType Collider::GetType()
	{
		return m_type;
	}
	ColliderForm Collider::GetFigure()
	{
		return m_form;
	}

	void Collider::SetVelocity(const Vector2& value)
	{
        m_velocity = value;
	}
	void Collider::SetFriction(float value)
	{
        m_friction = value;
	}
	void Collider::SetGravity(float value)
	{
        m_gravityScale = value;
	}
	void Collider::SetRotationConstrait(bool value)
	{
        m_isRotConstraint = value;
	}
	void Collider::SetActive(bool value)
	{
        m_active = value;
	}
	void Collider::SetIsTrigger(bool value)
	{
        m_isTrigger = value;
	}
	bool Collider::GetIsTrigger()
	{
		return m_isTrigger;
	}
	void Collider::SetType(ColliderType value)
	{
        m_type = value;
	}
	void Collider::SetFigure(ColliderForm value)
	{
        m_form = value;
	}

	void Collider::ApplyForce(const Vector2&, const Vector2&)
	{

	}

	void Collider::ApplyLinearImpulse(const Vector2&, const Vector2&)
	{

	}

	bool Collider::Transform_WasModified()
	{
		auto trans = m_transform.lock();

		return trans->WasModified();
	}

	void Collider::SetTriggerStartCallBack(std::function<void(Collider& other, FunctionParameters params)> callback)
	{
        m_TriggerStart_CallBack = callback;
	}

	void Collider::SetTriggerEndCallBack(std::function<void(Collider& other, FunctionParameters params)> callback)
	{
        m_TriggerEnd_CallBack = callback;
	}

	void Collider::SetCollisionStartCallBack(std::function<void(Collider& other, FunctionParameters params)> callback)
	{
        m_CollisionStart_CallBack = callback;
	}

	void Collider::SetCollisionResolveCallBack(std::function<void(Collider& other, FunctionParameters params)> callback)
	{
        m_CollisionResolve_CallBack = callback;
	}

	void Collider::Raycast(const Vector2& point1, const Vector2& point2, FunctionParameters parameters)
	{
	}

	bool Collider::PointOverlap(const Vector2& point1, FunctionParameters parameters)
	{
		return false;
	}

}