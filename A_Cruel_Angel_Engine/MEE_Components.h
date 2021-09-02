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

	class MEE_EXPORT Updatable
	{
	public:
		virtual void Update() = 0;
		virtual ~Updatable() = default;
	};

	class MEE_EXPORT Component
	{
	public:
		Component() = default;
		Object& GetParent();
		virtual ~Component() {}
	private:
		Object* parent;
		// Must always be called when scene adds a component
		void ParentToObject(Object* object);
		friend class Object;
	};

	class MEE_EXPORT Transform : public Component
	{
	public:
		Transform();
		void SetPosition(Vector2 position_vector);
		void SetPosition(float posX, float posY);
		void SetScale(Vector2 scale_vector);
		void SetScale(float x, float y);
		void SetRotation(float rotation_float);
		void Translate(Vector2 vec);
		Vector2 GetPosition();
		Vector2 GetScale();
		float GetRotation();
		bool WasModified();
	private:
		Vector2 position = Vector2();
		Vector2 scale = Vector2(1, 1);
		float rot = 0;
		bool modified = false;
		friend class Scene;
	};

	class MEE_EXPORT Behaviour : public Component , public Updatable
	{
	public:
		virtual void Start();
		virtual void Update() override;
		virtual void Destroy();
	};

	enum class ColliderType { Static, Dynamic, Kinematic };
	enum class ColliderForm { Circle, Box, Polygon };

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
		std::weak_ptr<Transform> transform;
		void SetTransform(std::shared_ptr<Transform> trans);
		Vector2 velocity;
		float friction;
		float gravityScale;
		bool isRotConstraint;
		bool active;
	    ColliderType type;
	    ColliderForm form;
		std::function<void(Collider& other, FunctionParameters params)> TriggerStart_CallBack; //No me gusta tener que usar de esta manera functions
		std::function<void(Collider& other, FunctionParameters params)> TriggerEnd_CallBack;
		std::function<void(Collider& other, FunctionParameters params)> CollisionStart_CallBack;
		std::function<void(Collider& other, FunctionParameters params)> CollisionResolve_CallBack;
		friend class Object;
		friend class Scene;
	};
}

