#pragma once
#include "MEE_Maths.h"
#include "MEE_Exports.h"

namespace MEE
{

	class Object;

	class MEE_EXPORT Component
	{
	public:
		Component(Object& parent);
	protected:
		Object& object;
	};

	class MEE_EXPORT Transform : public Component
	{
	public:
		Transform(Object& parent);
		void setPosition(Vector2 position_vector);
		void setScale(Vector2 scale_vector);
		void setRotation(float rotation_float);
		Vector2& getPosition();
		Vector2& getScale();
		float& getRotation();
	private:
		Vector2 position = Vector2();
		Vector2 scale = Vector2(1, 1);
		float rot = 0;
	};

	class MEE_EXPORT Behaviour : public Component
	{
	public:
		Behaviour(Object& parent);
		virtual void start();
		virtual void update();
		virtual void destroy();
		//Object& Object() { return object; }

	};

	class MEE_EXPORT Animation : public Component
	{
	public:
		Animation(Object& parent);
	};

}

