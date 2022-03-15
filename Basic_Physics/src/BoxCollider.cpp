#include "BoxCollider.h"
#include <MEE_Maths.h>
#include <box2d/b2_polygon_shape.h>
#include <box2d/b2_fixture.h>
#include <MEE_Physics.h>

Basic_Physics::BoxCollider::BoxCollider(b2World* world, MEE::Vector2 position , MEE::Vector2 size, ColliderType c_type)
{

    m_type = c_type;
	if (c_type == ColliderType::Static)
	{
		bodyDef.type = b2_staticBody;
	}
	else if (c_type == ColliderType::Dynamic)
	{
		bodyDef.type = b2_dynamicBody;
	}
	else if (c_type == ColliderType::Kinematic)
	{
		bodyDef.type = b2_kinematicBody;
	}

	bodyDef.position.Set(position.x, position.y);
	bodyDef.linearDamping = 0.5f;
	bodyDef.angularDamping = 0.5f;
	bodyDef.userData.pointer = (uintptr_t)this;

	body = world->CreateBody(&bodyDef);

	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(size.x,size.y);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
    m_friction = 1.0f;
	fixtureDef.friction = m_friction;

	body->CreateFixture(&fixtureDef);
	body->SetFixedRotation(true);
	body->SetSleepingAllowed(false);
}

void Basic_Physics::BoxCollider::UpdatePosition()
{
	auto trans = m_transform.lock();
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
	return m_friction;
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
	return m_active;
}

MEE::ColliderType Basic_Physics::BoxCollider::GetType()
{
	return m_type;
}

MEE::ColliderForm Basic_Physics::BoxCollider::GetFigure()
{
	return m_form;
}

void Basic_Physics::BoxCollider::SetVelocity(const MEE::Vector2& vel)
{
	body->SetLinearVelocity({vel.x,vel.y});
}

void Basic_Physics::BoxCollider::SetFriction(float val)
{
    m_friction = val;
	body->GetFixtureList()[0].SetFriction(m_friction);
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
    m_active = val;
	body->SetAwake(val);
}

void Basic_Physics::BoxCollider::SetType(ColliderType val)
{
	//Guadar y reconstruir
	m_type = val;
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

	auto pos = m_transform.lock()->GetPosition();
	bodyDef.position.Set(pos.x, pos.y);

	auto* world = body->GetWorld();

	if (body) world->DestroyBody(body);

	body = world->CreateBody(&bodyDef);

	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(0.5f, 0.5f);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = m_friction;

	body->CreateFixture(&fixtureDef);
}

void Basic_Physics::BoxCollider::SetFigure(ColliderForm val)
{
	//Guardar y reconstruir
	m_form = val;
}

void Basic_Physics::BoxCollider::ApplyForce(const MEE::Vector2& ff, const MEE::Vector2& pp)
{
	b2Vec2 force = { ff.x,ff.y };
	b2Vec2 point = { pp.x,pp.y };

	body->ApplyForceToCenter(force, true);
}

void Basic_Physics::BoxCollider::ApplyLinearImpulse(const MEE::Vector2& imp, const MEE::Vector2& pp)
{
	b2Vec2 force = { imp.x,imp.y };
	b2Vec2 point = { pp.x,pp.y };

	body->ApplyLinearImpulseToCenter(force, true);
}

void Basic_Physics::BoxCollider::Raycast(const MEE::Vector2& point1, const MEE::Vector2& point2, FunctionParameters parameters)
{
	b2RayCastInput input;
	input.p1.Set(0.0f, 0.0f);
	input.p2.Set(1.0f, 0.0f);
	input.maxFraction = 1.0f;
	int32 childIndex = 0;


}

bool Basic_Physics::BoxCollider::PointOverlap(const MEE::Vector2& point1, FunctionParameters parameters)
{
	b2Vec2 point(point1.x, point1.y);
	b2Transform transform;
	transform.SetIdentity();
	return body->GetFixtureList()[0].GetShape()->TestPoint(transform, point);
}

