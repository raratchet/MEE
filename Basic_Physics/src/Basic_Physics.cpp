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
	std::string collider("CreateCollider");
	MEE_bind_CreateCollider(pl_id, "CreateCollider");
	MEE_bind_PhysicsStep(pl_id, "PhysicsStep");
	MEE_bind_CreatePhysicsWorld(pl_id, "CreatePhysicsWorld");
	MEE_bind_SetColliderTransform(pl_id, "UpdateTransform");
	MEE_bind_GetColliderTransform(pl_id, "ReadTransform");
}

void Basic_Physics::OnLoad()
{
}

 void Basic_Physics::OnShutdown()
{
}

void Basic_Physics::OnUpdate()
{
}

void Basic_Physics::OnDraw()
{
	DRAWPHYSICS(0)
}

void Basic_Physics::CreatePhysicsWorld(SceneID id, FunctionParameters& params)
{
	static b2Vec2 defaultGravity(0.0f,14.0f);
	physicWorlds[id] = new b2World(defaultGravity);
	physicWorlds[id]->SetContactListener(new BoxContactListener);
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

MEE_Collider Basic_Physics::CastCollider(MEE_Collider collider)
{
	BoxCollider* i_collider = (BoxCollider*)collider;
	return (MEE_Collider) i_collider;
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

	auto position = params["Position"].As<MEE::Vector2>();
	auto size = params["Size"].As<MEE::Vector2>();
	auto type = params["Type"].As<ColliderType>();

	BoxCollider* newCollider = new BoxCollider(world,position,size,type);

	bodies[world].push_back(newCollider);

	return (MEE_Collider)newCollider;
}

void Basic_Physics::PhysicsStep(SceneID id)
{
	auto world = physicWorlds[id];

	double timeStep = MEE_GetDeltaTime();

	int32 velocityIterations = 5;
	int32 positionIterations = 2;

	world->Step(timeStep, velocityIterations, positionIterations);
}
