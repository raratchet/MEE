#pragma once
#include "MEE_Maths.h"
#include <memory>
#include "MEE_Exports.h"


namespace MEE
{

	class Object;

	class MEE_EXPORT Component
	{
	public:
		Object& GetParent();
		virtual ~Component() {}
	protected:
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
		Vector2& GetPosition();
		Vector2& GetScale();
		float& GetRotation();
	private:
		Vector2 position = Vector2();
		Vector2 scale = Vector2(1, 1);
		float rot = 0;
	};

	class MEE_EXPORT Behaviour : public Component
	{
	public:
		virtual void Start();
		virtual void Update();
		virtual void Destroy();

	};


	class MEE_EXPORT Animation : public Component
	{

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
		virtual void SetVelocity(const Vector2&);
		virtual void SetFriction(float);
		virtual void SetGravity(float);
		virtual void SetRotationConstrait(bool);
		virtual void SetActive(bool);
		virtual void SetType(ColliderType);
		virtual void SetFigure(ColliderForm);
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

		friend class Object;
		friend class Scene;
	};
}

