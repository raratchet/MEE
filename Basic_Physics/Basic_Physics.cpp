#include "Basic_Physics.h"
#include "DebugDraw.h"
#include <iostream>

#define DRAW	

#ifdef _DEBUG && DRAW
#define DEBUG_DRAW DebugDraw* draw = new DebugDraw();\
				   physicWorlds[id]->SetDebugDraw(draw);

#define DRAWPHYSICS(x) physicWorlds[x]->DebugDraw();
#else
#define DEBUG_DRAW
#define DRAWPHYSICS(x)
#endif // DEBUG


const float PI = 3.14f;

void Basic_Physics::OnInit(int pl_id)
{
	MEE_bind_CreateCollider(pl_id, "CreateCollider");
	MEE_bind_PhysicsStep(pl_id, "PhysicsStep");
	MEE_bind_CreatePhysicsWorld(pl_id, "CreatePhysicsWorld");
	MEE_bind_SetColliderTransform(pl_id, "UpdateTransform");
	MEE_bind_GetColliderTransform(pl_id, "ReadTransform");
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

void Basic_Physics::OnDraw()
{
	DRAWPHYSICS(0)
}

void Basic_Physics::CreatePhysicsWorld(SceneID id)
{
	static b2Vec2 defaultGravity(0.0f,2.0f);
	physicWorlds[id] = new b2World(defaultGravity);
	DEBUG_DRAW
}

void Basic_Physics::UpdateTransform(MEE_Collider collider, float x, float y, float a)
{
	BoxCollider* bCollider = (BoxCollider*)collider;

	if (bCollider->Transform_WasModified())
	{
		bCollider->body->SetTransform({ x, y }, a);
		bCollider->body->SetAwake(true);
	}
}

void Basic_Physics::ReadTransform(MEE_Collider collider, float* x, float* y, float* a)
{
	BoxCollider* bCollider = (BoxCollider*)collider;

	auto transform = bCollider->body->GetTransform();

	*x = transform.p.x;
	*y = transform.p.y;
	//*a = (transform.q.c != 0) ? (transform.q.c * 180) / PI : 0.0F ;
	*a = 0;
}

MEE_Collider Basic_Physics::CreateCollider(SceneID id,FunctionParameters& params)
{
	auto world = physicWorlds[id];
	BoxCollider* newCollider = new BoxCollider(world);

	bodies[world].push_back(newCollider);

	return (MEE_Collider)newCollider;
}

void Basic_Physics::PhysicsStep(SceneID id)
{
	auto world = physicWorlds[id];

	float timeStep = 1.0f / 60.0f;

	int32 velocityIterations = 3;
	int32 positionIterations = 1;

	world->Step(timeStep, velocityIterations, positionIterations);
}
