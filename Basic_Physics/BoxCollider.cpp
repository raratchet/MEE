#include "BoxCollider.h"
#include <MEE_Maths.h>
#include <box2d/b2_polygon_shape.h>
#include <box2d/b2_fixture.h>
#include <MEE_Physics.h>

Basic_Physics::BoxCollider::BoxCollider(b2World* world)
{
	bodyDef.type = b2_staticBody;
	bodyDef.position.Set(0, 0);

	body = world->CreateBody(&bodyDef);

	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(1.0f, 1.0f);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	friction = 0.3f;
	fixtureDef.friction = friction;

	body->CreateFixture(&fixtureDef);
}

void Basic_Physics::BoxCollider::UpdatePosition()
{
	auto trans = transform.lock();
	auto pos = body->GetPosition();
	auto angle = body->GetAngle();

	trans->SetPosition(pos.x, pos.y);
	trans->SetRotation(angle);
}

MEE::Vector2 Basic_Physics::BoxCollider::GetVelocity()
{
	auto vel = body->GetLinearVelocity();
	return {vel.x,vel.y};
}

float Basic_Physics::BoxCollider::GetFriction()
{
	return friction;
}

float Basic_Physics::BoxCollider::GetGravity()
{
	return body->GetGravityScale();
}

bool Basic_Physics::BoxCollider::GetRotationConstrait()
{
	return body->IsFixedRotation();
}

bool Basic_Physics::BoxCollider::GetActive()
{
	return active;
}

MEE::ColliderType Basic_Physics::BoxCollider::GetType()
{
	return type;
}

MEE::ColliderForm Basic_Physics::BoxCollider::GetFigure()
{
	return form;
}

void Basic_Physics::BoxCollider::SetVelocity(const MEE::Vector2& vel)
{
	body->SetLinearVelocity({vel.x,vel.y});
}

void Basic_Physics::BoxCollider::SetFriction(float val)
{
	friction = val;
}

void Basic_Physics::BoxCollider::SetGravity(float val)
{
	body->SetGravityScale(val);
}

void Basic_Physics::BoxCollider::SetRotationConstrait(bool val)
{
	body->SetFixedRotation(val);
}

void Basic_Physics::BoxCollider::SetActive(bool val)
{
	active = val;
}

void Basic_Physics::BoxCollider::SetType(ColliderType val)
{
	//Guadar y reconstruir
	type = val;
	if (val == ColliderType::Static)
	{
		bodyDef.type = b2_staticBody;
	}
	else if (val == ColliderType::Dynamic)
	{
		bodyDef.type = b2_dynamicBody;
	}
	else if (val == ColliderType::Kinematic)
	{
		bodyDef.type = b2_kinematicBody;
	}

	auto pos = transform.lock()->GetPosition();
	bodyDef.position.Set(pos.x, pos.y);

	auto* world = body->GetWorld();

	if (body) world->DestroyBody(body);

	body = world->CreateBody(&bodyDef);

	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(1.0f, 1.0f);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = friction;

	body->CreateFixture(&fixtureDef);
}

void Basic_Physics::BoxCollider::SetFigure(ColliderForm val)
{
	//Guardar y reconstruir
	form = val;
}

