#include "Basic_Physics.h"

void Basic_Physics::OnInit(int pl_id)
{
	MEE_bind_CreateCollider(pl_id, "CreateCollider");
	MEE_bind_PhysicsStep(pl_id, "PhysicsStep");
	MEE_bind_CreatePhysicsWorld(pl_id, "CreatePhysicsWorld");
}

void Basic_Physics::OnLoad()
{
}

 void Basic_Physics::OnShutDown()
{
}

void Basic_Physics::OnUpdate()
{
}

void Basic_Physics::CreatePhysicsWorld(SceneID id)
{
	static b2Vec2 defaultGravity(0.0f,-10.0f);
	physicWorlds[id] = new b2World(defaultGravity);
}

MEE_Collider Basic_Physics::CreateCollider(SceneID id)
{
	auto world = physicWorlds[id];
	BoxCollider* newCollider = new BoxCollider(world);

	bodies[world].push_back(newCollider);

	return (MEE_Collider)newCollider;
}

void Basic_Physics::PhysicsStep(SceneID id)
{
	auto world = physicWorlds[id];
	world->Step(1/60,1,1);

	for (auto body : bodies[world])
	{
		body->UpdatePosition();
	}
}
