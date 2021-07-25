#pragma once
#include <MEE_Components.h>
#include <box2d/b2_world.h>
#include <box2d/b2_body.h>
#include <box2d/b2_math.h>

namespace Basic_Physics
{
	class BoxCollider : MEE::Collider
	{
	public:
		BoxCollider(b2World* world);
		void UpdatePosition();
	private:
		b2BodyDef bodyDef;
		b2Body* body;
	};
}

