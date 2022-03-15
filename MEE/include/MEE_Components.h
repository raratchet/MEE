/*****************************************************************//**
 * \file   MEE_Components.h
 * \brief  Contains several definitions for components.
 * 
 * \author Maximiliano Herrera
 * \date   October 2021
 *********************************************************************/
#pragma once
#include "MEE_Maths.h"
#include <memory>
#include "MEE_Exports.h"
#include <functional>
#include "MEE_Functional.h"

struct FunctionParameters;

namespace MEE
{

	class Object;

	/**
	 * Updatable.
	 */
	class MEE_EXPORT Updatable
	{
	public:
		virtual void Update() = 0;
		virtual ~Updatable() = default;
	};

	/**
	 * Component.
	 */
	class MEE_EXPORT Component
	{
	public:
		Component() = default;
		Object& GetParent();
		virtual ~Component() = default;
	private:
		Object* parent = nullptr;
		// Must always be called when scene adds a component
		void ParentToObject(Object* object);
		friend class Object;
	};

	/**
	 * TransformComponent.
	 */
	class MEE_EXPORT TransformComponent : public Component
	{
	public:
		TransformComponent();
		void SetPosition(Vector2 position_vector);
		void SetPosition(float posX, float posY);
		void SetScale(Vector2 scale_vector);
		void SetScale(float x, float y);
		void SetRotation(float rotation_float);
		void Translate(Vector2 vec);
		Vector2 GetPosition();
		Vector2 GetScale();
		Transform& GetTransform();
		float GetRotation();
		bool WasModified();
	private:
		Transform transform;
		bool modified = false;
		friend class Scene;
	};

	/**
	 * Behaviour.
	 */
	class MEE_EXPORT Behaviour : public Component , public Updatable
	{
	public:
		virtual void Start();
		virtual void Update() override;
		virtual void Destroy();
	};

	enum class ColliderType { Static, Dynamic, Kinematic };
	enum class ColliderForm { Circle, Box, Polygon };

	/**
	 * Collider.
	 */
	class MEE_EXPORT Collider : public Component
	{
	public:
		virtual ~Collider() = default;
		virtual Vector2 GetVelocity();
		virtual float GetFriction();
		virtual float GetGravity();
		virtual bool GetRotationConstrait();
		virtual bool GetActive();
		virtual ColliderType GetType();
		virtual ColliderForm GetFigure();
		virtual void SetVelocity(const Vector2& velocity);
		virtual void SetFriction(float);
		virtual void SetGravity(float);
		virtual void SetRotationConstrait(bool);
		virtual void SetActive(bool);
		virtual void SetIsTrigger(bool);
		virtual bool GetIsTrigger();
		virtual void SetType(ColliderType);
		virtual void SetFigure(ColliderForm);
		virtual void ApplyForce(const Vector2& force, const Vector2& point);
		virtual void ApplyLinearImpulse(const Vector2& impulse, const Vector2& point);
		virtual void Raycast(const Vector2& point1, const Vector2& point2, FunctionParameters parameters);
		virtual bool PointOverlap(const Vector2& point1, FunctionParameters parameters);
		void SetTriggerStartCallBack(std::function<void(Collider& other, FunctionParameters params)> callback); //Puedo solicitar un Behaviour o incluso un scene que tengan una funcion virtual TriggerEnter y envolverla en un lamba para solo pedir una instancia en vez de una funcion completa
		void SetTriggerEndCallBack(std::function<void(Collider& other, FunctionParameters params)> callback);
		void SetCollisionStartCallBack(std::function<void(Collider& other, FunctionParameters params)>callback);
		void SetCollisionResolveCallBack(std::function<void(Collider& other, FunctionParameters params)> callback);
		bool Transform_WasModified();
	protected:
		std::weak_ptr<TransformComponent> m_transform;
		void SetTransform(std::shared_ptr<TransformComponent> trans);
		Vector2 m_velocity;
		float m_friction;
		float m_gravityScale;
		bool m_isRotConstraint;
		bool m_active = true;
		bool m_isTrigger = false;
	    ColliderType m_type;
	    ColliderForm m_form;
		std::function<void(Collider& other, FunctionParameters params)> m_TriggerStart_CallBack; //No me gusta tener que usar de esta manera functions
		std::function<void(Collider& other, FunctionParameters params)> m_TriggerEnd_CallBack;
		std::function<void(Collider& other, FunctionParameters params)> m_CollisionStart_CallBack;
		std::function<void(Collider& other, FunctionParameters params)> m_CollisionResolve_CallBack;
		friend class Object;
		friend class Scene;
	};
}

