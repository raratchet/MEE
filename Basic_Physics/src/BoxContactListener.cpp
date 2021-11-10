#include "BoxContactListener.h"
#include <iostream>
#include "BoxCollider.h"

void Basic_Physics::BoxContactListener::BeginContact(b2Contact* contact)
{
	b2Body* first = contact->GetFixtureA()->GetBody();
	b2Body* second = contact->GetFixtureB()->GetBody();

	BoxCollider* collider_1 = (BoxCollider*)first->GetUserData().pointer;
	BoxCollider* collider_2 = (BoxCollider*)second->GetUserData().pointer;

	if (collider_1->TriggerStart_CallBack)
		collider_1->TriggerStart_CallBack(*collider_2, FunctionParameters::NoParameters());

	if (collider_2->TriggerStart_CallBack)
		collider_2->TriggerStart_CallBack(*collider_1, FunctionParameters::NoParameters());

}

void Basic_Physics::BoxContactListener::EndContact(b2Contact* contact)
{
	b2Body* first = contact->GetFixtureA()->GetBody();
	b2Body* second = contact->GetFixtureB()->GetBody();

	BoxCollider* collider_1 = (BoxCollider*)first->GetUserData().pointer;
	BoxCollider* collider_2 = (BoxCollider*)second->GetUserData().pointer;

	if (collider_1->TriggerEnd_CallBack)
		collider_1->TriggerEnd_CallBack(*collider_2, FunctionParameters::NoParameters());

	if (collider_2->TriggerEnd_CallBack)
		collider_2->TriggerEnd_CallBack(*collider_1, FunctionParameters::NoParameters());
}

void Basic_Physics::BoxContactListener::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
{
	b2Body* first = contact->GetFixtureA()->GetBody();
	b2Body* second = contact->GetFixtureB()->GetBody();

	BoxCollider* collider_1 = (BoxCollider*)first->GetUserData().pointer;
	BoxCollider* collider_2 = (BoxCollider*)second->GetUserData().pointer;

	bool enabled = true;
	if (collider_1->GetIsTrigger() || collider_2->GetIsTrigger())
		enabled = false;

	contact->SetEnabled(enabled);

	if (collider_1->CollisionStart_CallBack)
		collider_1->CollisionStart_CallBack(*collider_2, FunctionParameters::NoParameters());

	if (collider_2->CollisionStart_CallBack)
		collider_2->CollisionStart_CallBack(*collider_1, FunctionParameters::NoParameters());
}

void Basic_Physics::BoxContactListener::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse)
{
	b2Body* first = contact->GetFixtureA()->GetBody();
	b2Body* second = contact->GetFixtureB()->GetBody();

	BoxCollider* collider_1 = (BoxCollider*)first->GetUserData().pointer;
	BoxCollider* collider_2 = (BoxCollider*)second->GetUserData().pointer;

	if (collider_1->CollisionResolve_CallBack)
		collider_1->CollisionResolve_CallBack(*collider_2, FunctionParameters::NoParameters());

	if (collider_2->CollisionResolve_CallBack)
		collider_2->CollisionResolve_CallBack(*collider_1, FunctionParameters::NoParameters());
}
