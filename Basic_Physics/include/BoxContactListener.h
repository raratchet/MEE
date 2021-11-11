#pragma once
#include <box2d/b2_contact.h>
#include <box2d/b2_world.h>
#include <box2d/b2_world_callbacks.h>

namespace Basic_Physics
{
	class BoxContactListener : public b2ContactListener
	{
	public:

		virtual void BeginContact(b2Contact* contact) override;

		virtual void EndContact(b2Contact* contact) override;

		virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold) override;

		virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse) override;
	};
}


