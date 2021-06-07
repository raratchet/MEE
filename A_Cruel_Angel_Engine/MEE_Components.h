#pragma once
#include "MEE_Maths.h"
#include "MEE_Exports.h"

namespace MEE
{

	class Object;

	class MEE_EXPORT Component
	{
	public:
		Object& Obj();
	protected:
		Object* parent;
		// Must always be called when scene adds a component
		void ParentObject(Object* object);
		friend class Object;
	};

	class MEE_EXPORT Transform : public Component
	{
	public:
		Transform();
		Transform(Object* object);
		void SetPosition(Vector2 position_vector);
		void SetScale(Vector2 scale_vector);
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

}

